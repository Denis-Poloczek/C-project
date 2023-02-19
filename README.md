# C-project

The Project contains Jaro-Winkler algorithm implementation in C language 

The Jaro Winkler distance algorithm is a string matching technique used to measure the similarity between two strings. It was developed by William E. Winkler in 1990 and is an extension of the Jaro distance algorithm, which was developed by William F. Jaro in 1989.

The Jaro distance algorithm calculates the similarity between two strings by counting the number of matching characters, the number of transpositions (when two characters in a string match, but their positions are switched in the other string), and the length of the common prefix.

The Jaro Winkler distance algorithm can be calculated using the following formula:

Jaro Winkler distance = Jaro distance + (prefix length * scaling factor * (1 - Jaro distance))

$$JW = J + (l \times p \times (1 - J))$$

where:

$J$ is the Jaro distance between the two strings
$l$ is the length of the common prefix between the two strings, up to a maximum of four characters
$p$ is a scaling factor between 0 and 0.25 that gives more weight to the similarity of the initial characters of the two strings.
$JW$ is the Jaro Winkler distance between the two strings.

The Jaro Winkler distance algorithm extends the Jaro distance algorithm by taking into account the similarity of the initial characters of the two strings being compared. This is done by adding a scaling factor to the Jaro distance based on the number of initial characters that match.
