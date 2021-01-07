#include <string.h>

int reduceSpace ( char *line ) {
    
    int q = 0; /*a counter for rebuilding the line with reduced spaces*/
    int i = 0; /*counter for searching lines*/
    int length = strlen(line); /*creates variable containing number of characters, spaces, and tabs in line*/
    int finalLength; /*stores length of newly created line*/
    int ret; /*return value containing number of spaces removed*/

for (i = 0; i < strlen(line); i++) 
{ /*look at each character of the given line*/

        
        if (i<1)
        {
            if (*(line+i) != ' ' && *(line+i) != '\t') /*check for characters*/
            {
                *(line+(q)) = *(line+i); /*if the first character of the line is a character and not whitespace, bulid new reduced line from this point*/
                q++; /*increment new reduced line*/
            }     
        }
        
        else if (i>0)
        {

            if ( (*(line+i) != ' ' && *(line+i) != '\t') && (*(line+(i-1)) == ' '  )) /*check for character proceeded by white space*/
            {
                *(line+(q)) = ' '; /*replaces 1 or more white spaces with a single white space in new line*/
                *(line+(q+1)) = *(line+i); /*add character to new reduced line*/
                q = q + 2; /*two characters were added to the new line so increment by two*/
            }
            else if ( (*(line+i) != ' ' && *(line+i) != '\t') && ( *(line+(i-1)) == '\t') ) /*check for character proceeded by a tab*/
            {
                *(line+(q)) = ' '; /*replaces 1 or more white spaces with a single white space in new line*/
                *(line+(q+1)) = *(line+i); /*add character to new reduced line*/
                q = q + 2; /*two characters were added to the new line so increment by two*/
                length = length + 3; /*a tab is 4 spaces so an additional three spaces must be added to the already existing space to account for number of total white spaces replaced*/
            }
            
            else if (*(line+i) != ' ' && *(line+i) != '\t' ) /*if this element of the line is a character add to new reduced line*/
            { 

                *(line+(q)) = *(line+i); 
                q++; 
            }
        }
 
        
} 

 *(line+q) = '\0'; /*set an end to the newly created reduced line*/
 finalLength = strlen(line); /*checks length of newly created line*/
 ret = length - finalLength; /*find number of white spaces removed*/

 return(ret); /*return number of spaces removed*/
} 
  
  
  
  
  
  
  
  