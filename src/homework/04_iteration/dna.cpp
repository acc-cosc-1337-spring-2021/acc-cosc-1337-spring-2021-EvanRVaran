#include "dna.h"

/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const std::string string)
{
    double totalGC = 0;
    for(int i = 0; i < string.length(); i++)
    {
        if(string[i] == 'G' || string[i] == 'C')
        {
            totalGC++;
        }
    }
    return (double(totalGC/string.length()));
}



/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/

std::string get_reverse_string(std::string string)
{
    std::string reversedString; 
    for(int v = 0; v < string.length(); v++)
    {
        reversedString += string[string.length()- v - 1];
    }
    return reversedString;
}

/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/
std::string get_dna_complement(std::string string)
{
    std::string reversedString = get_reverse_string(string);

    for(int k = 0; k < reversedString.length(); k++)
    {
       
        if(reversedString[k] == 'G')
        { 
            reversedString[k] = 'C';
        }
        else if(reversedString[k] == 'C')
        {
            reversedString[k] = 'G';
        }
        
        if(reversedString[k] == 'A')
        {
            reversedString[k] = 'T';
        }
        else if(reversedString[k] == 'T')
        {
            reversedString[k] = 'A';
        }
    }
    return reversedString;
}
