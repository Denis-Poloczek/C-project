# C-project

The Project contains Jaro-Winkler algorithm implementation in C language 

The Jaro Winkler distance algorithm is a string matching technique used to measure the similarity between two strings. It was developed by William E. Winkler in 1990 and is an extension of the Jaro distance algorithm, which was developed by William F. Jaro in 1989.

The Jaro distance algorithm calculates the similarity between two strings by counting the number of matching characters, the number of transpositions (when two characters in a string match, but their positions are switched in the other string), and the length of the common prefix.

The Jaro Winkler distance algorithm can be calculated using the following formula:

Jaro Winkler distance = Jaro distance + (prefix length * scaling factor * (1 - Jaro distance))

![image](https://user-images.githubusercontent.com/73393523/219946866-054a9d6c-4b90-46d8-adc7-16b0ad989e08.png)

The Jaro Winkler distance algorithm extends the Jaro distance algorithm by taking into account the similarity of the initial characters of the two strings being compared. This is done by adding a scaling factor to the Jaro distance based on the number of initial characters that match.
