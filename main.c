//
//  main.c
//  Projekt 1 - C
//
//  Created by Denis Poloczek on 29/05/2020.
//


#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define WYMIAR_X 700
#define WYMIAR_Y 50


#define SCALAR 0.1

static int max(int x, int y) {
    return x > y ? x : y;
}

static int min(int x, int y) {
    return x < y ? x : y;
}

double jaro_winkler_distance(const char *s, const char *a) {
    int i, j, l;
    int m = 0, t = 0;
    int sl = strlen(s);
    int al = strlen(a);
    int sflags[sl], aflags[al];
    int range = max(0, max(sl, al) / 2 - 1);
    double dw;

    if (!sl || !al)
        return 0.0;

    for (i = 0; i < al; i++)
        aflags[i] = 0;

    for (i = 0; i < sl; i++)
        sflags[i] = 0;

    /* Wyliczanie pasujacych znakow i to w taki sposob, ze za pasujace uznajemy znaki, ktore sa na dokladnie tej samej pozycji w obu lub takie, ktore sa przesuniete wzgledem siebie o przyjete z algorytmu jaro maksimium liczone ze wzoru: (dlugosc stringu / 2) - 1 */

    for (i = 0; i < al; i++) {
        for (j = max(i - range, 0), l = min(i + range + 1, sl); j < l; j++) {
            if (a[i] == s[j] && !sflags[j]) {
                sflags[j] = 1;
                aflags[i] = 1;
                m++;
                break;
            }
        }
    }

    if (!m)
        return 0.0;

    /* kalkulacja dla transpozycji - liczymy ile jest takich samych znakow, ktore nie zmiescily sie w maksymalnej odleglosci od siebie wiec nie zostaly uznane za match, ale nadal sa istotne do policzenia dystansu Jaro */

    l = 0;
    for (i = 0; i < al; i++) {
        if (aflags[i] == 1) {
            for (j = l; j < sl; j++) {
                if (sflags[j] == 1) {
                    l = j + 1;
                    break;
                }
            }
            if (a[i] != s[j])
                t++;
        }
    }
    t /= 2;

    /* dystans Jaro liczony jest tak, ze bierzemy ilosc matchy - m i dzielimy przez dlugosc pierwszego stringu potem dodajemy to samo dla drugiego i ostatecznie dodajemy ilosc (matchy - ilosc transpozycji) przez ilosc matchy i wszystko dzielimy na 3, aby powstala liczba byla w przedziale 0.0 - 1.0 bo mamy trzy skladniki ulamkowe wiec 3 czesc jedynki w najlepszym razie moglyby dac 1*/

    dw = (((double)m / sl) + ((double)m / al) + ((double)(m - t) / m)) / 3.0;

    /* wyliczamy ile jest pasujacych znakow do maksymalnie 4 od poczatku stringu */
    l = 0;
    for (i = 0; i < min(min(sl, al), 4); i++)
        if (s[i] == a[i])
            l++;

    /* dystans Jaro-Winkler - wprowadza korekte do algorytmu jaro liczacego dysatns zwiekszajac dystans jaro jezeli faktycznie od 1-4 pierwszych znakow wsytepuje i w 1 i w 2 stringu */
    dw = dw + (l * SCALAR * (1 - dw));

    return dw;
}


int main(int argc, char const *argv[])
{
    /*  Czytanie analizowanego txt + utworzenie listy slow  */
    FILE* inp;
        inp = fopen("pan-tadeusz.txt","r");
        char arr[700][50];
        int i = 0;
        while(1){
            char r = (char)fgetc(inp);
            int k = 0;
            while(r!=' ' && !feof(inp)){
                arr[i][k++] = r;
                r = (char)fgetc(inp);
            }
            arr[i][k]=0;
            if(feof(inp)){
                break;
            }
            i++;
        }
        int j;
        for(j = 0;j<=i;j++){
            printf(" Slowo %d: %s\n",j,arr[j] );
        }
    /*  Czytanie pliku ze "stolista" txt + utworzenie listy slow  */
   
    FILE* inp1;
        inp1 = fopen("stoplista.txt","r");
        char arr_stoplista[280][50];
        int m = 0;
        while(1){
            char r = (char)fgetc(inp1);
            int n = 0;
            while(r!=',' && !feof(inp1)){
                arr_stoplista[m][n++] = r;
                r = (char)fgetc(inp1);
            }
            arr_stoplista[m][n]=0;
            if(feof(inp1)){
                break;
            }
            m++;
        }
        int p;
        for(p = 0;p<=m;p++){
            printf(" Slowo_stoplista %d: %s\n",p,arr_stoplista[p] );   
        }
        
    FILE* inp2;
        inp2 = fopen("corrections.txt","r");
        char arr_corrections[30][50];
        int q = 0;
        while(1){
            char r = (char)fgetc(inp2);
            int h = 0;
            while(r!=',' && !feof(inp2)){
                arr_corrections[q][h++] = r;
                r = (char)fgetc(inp2);
            }
            arr_corrections[q][h]=0;
            if(feof(inp2)){
                break;
            }
            q++;
        }
        int w;
        for(w = 0;w<=q;w++){
            printf(" Slowo_corrections %d: %s\n",w,arr_corrections[w] );    
        }
    
    
    
    
    /*  Wyrzucanie stoplisty z badanego tekstu*/
    
    char arr_bez_stoplisty[700][50];
    int index = 0;
    int counter = 0;
    int flag_exist = 0;
    printf("%s\n","-----------------------------------------" );
    printf("%s\n", "W badanym pliku tekstowym wykryto nastepujace slowa ze stop-listy");
    for(int c = 0; c < 660; c++){
        flag_exist =0;
        for(int d = 0; d < 277; d++)
        {
            if(strcmp(arr[c], arr_stoplista[d]) == 0)
            {
                printf(" %s - %s", arr[c],arr_stoplista[d]);
                counter++;
                flag_exist = 1;
                
            }
           
        }
        if(flag_exist == 0)
        {
            for(int f = 0; f < 50; f++)
            {
                arr_bez_stoplisty[index][f] = arr[c][f];
                
            }
            index++;
            
        }
     
    }
    printf(" %s\n", "");
    printf(" %s\n", "");
    printf("%s\n","-----------------------------------------" );
    printf("%s\n","PODSUMOWANIE BADANIA" );
    printf("%s\n","-----------------------------------------" );
    float procent = (float)counter / 700 * 100;
    printf("W sumie w pliku badanym wykryto: %d slow ze stop listy\n", counter);
    printf("Badany plik w %.2f procentach sklada sie ze slow ze sto listy\n", procent);
 
/*Algorytm Jaro–Winkler distance  */

    
    float alpha;
    printf("Prosze podaj parametr alpha z przedzialu 0.00 - 1.00: ");
    scanf("%f", &alpha);
    printf("%s\n","-----------------------------------------" );
    
    
    for(int i = 0; i < 30; i++ ){
        for(int j = 0; j < 700; j++){
            if(jaro_winkler_distance(arr_corrections[i],arr[j]) >= alpha){
                printf("Slowo wyszukane w pliku to: %s\n podobne do %s\n ze wspolczynnikiem: %.4f\n", arr[j], arr_corrections[i], jaro_winkler_distance(arr_corrections[i],arr[j]));
            }
        }
    }


    
    return 0;
    
}
