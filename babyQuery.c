#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "babies.h"

int main( int argc, char *argv[] ) {

char maleSNumber[MAXLENGTH];
char femaleSNumber[MAXLENGTH] ;
char decade[10];
char choice[10];
char rank[10];
int rankNum;
char gender[10];
char name[10];
char string[100];
char dec[100];
int j;
char yesOrNo[MAXLENGTH];
int masterLoop = 1;



FILE*f1; 


while ( masterLoop == 1 )
    {

    int decadeNum = 0;
    int i = 0;
    int loop = 1;
    int decadeCheck = 1;
    
    

    while ( decadeCheck == 1) 
    {
        
          
        printf( "What decade do you want to look at? [1880 to 2010]:\n"); /*get the decade desired by the user*/
        
        fgets(decade,500,stdin);
       
        chop(decade);
        decadeNum = atoi(decade);
            

        

        if ( ( (strlen( decade) ) < 4 ) || ( (strlen( decade) ) > 4 ) )
        {
            printf( "Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable.\n");
        }

        else if ( (decadeNum != 1880) & (decadeNum != 1890) & (decadeNum != 1900) & (decadeNum != 1910) & (decadeNum != 1920) & (decadeNum != 1930) & (decadeNum != 1940) & (decadeNum != 1950) & (decadeNum != 1960) & (decadeNum != 1970) & (decadeNum != 1980) & (decadeNum != 1990) & (decadeNum != 2000) & (decadeNum != 2010) )
        {
            printf( "Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable.\n");
        }

        else
        {
            decadeCheck = 0;
        }
       
    }

    decade[4] = '\0';
    sprintf(dec, "%sNames.txt", decade);


    if ( (f1 = fopen( dec, "r")) != NULL ) 
    {
        while ( fgets(string, 100, f1) != NULL ) {
            sscanf (string, "%d %s %s %s %s", &popNames.rank[i], popNames.maleName[i], maleSNumber, popNames.femaleName[i], femaleSNumber);
    /* printf ( "%d %s %s %s %s\n",popNames.rank[i],popNames.maleName[i],maleSNumber,popNames.femaleName[i],femaleSNumber ); */
            removeCommas ( maleSNumber );
            removeCommas ( femaleSNumber );
            popNames.maleNumber[i] = atoi ( maleSNumber );
            popNames.femaleNumber[i] = atoi ( femaleSNumber );
            i++;
        }
    } 
    
    else {
        printf ( "Cannnot open %s\n", argv[1] );
        return ( -2 );
    }

    while ( loop == 1 )
    {

        int choiceCheck = 1;
        int rankCheck = 1;
        int maleRank = 0;
        int femaleRank = 0;
        int i = 0; 
        int genderCheck = 1;
        int yesNoCheck = 1;

        while ( choiceCheck == 1 )
        {
            
            printf( "Would you like to see a rank, search for a name, or see the top 10? [rank, search, top]:\n"); /*gets the choice from user*/
            fgets(choice,500,stdin);

            if ( ( strcmp( choice, "rank\n" ) != 0 ) & ( strcmp( choice, "search\n" ) != 0 ) & ( strcmp( choice, "top\n" ) != 0 ) )
            {
            printf( "Please type in rank, search, or top exactly as requested.\n" );
            }
            else
            {
                choiceCheck = 0;
            }


        }

        if ( strcmp( choice, "rank\n" ) == 0 ) /*when the user selects rank*/
        {
            while ( rankCheck == 1 )
            {
                printf( "What rank do you wish to see? [1-200]:\n"); /*retrieves desired rank from user*/
                fgets(rank,500,stdin);
                
                if ( ( (atoi(rank)) < 1 ) || ( (atoi(rank)) > 200 ) )
                {
                printf( "Only numbers between 1 and 200 are acceptable.\n" );
                }
                else
                {
                    rankCheck = 0;
                }
            }
            rankNum = atoi( rank );
            rankNum--;

            while ( genderCheck == 1 )
            {
                printf( "Would you like to see the male (0), female (1), or both (2) name(s)? [0-2]:\n"); /*retrieves desired rank from user*/
                fgets(gender,500,stdin);
                if ( ( (atoi(gender)) != 0 ) & ( (atoi(gender)) != 1 ) & ( (atoi(gender)) != 2 ) )
                {
                printf( "Only the numbers 0, 1, or 2 are acceptable.\n" );
                }
                else
                {
                    genderCheck = 0;
                }
            }

            if ( atoi(gender) == 2 )
            {
                printf( "Rank %d: Male: %s (%d) and Female: %s (%d)\n", (rankNum+1), popNames.maleName[rankNum], popNames.maleNumber[rankNum], popNames.femaleName[rankNum], popNames.femaleNumber[rankNum] );
            }
            else if ( atoi(gender) == 0 )
            {
                printf( "Rank %d: Male: %s (%d)\n", (rankNum+1), popNames.maleName[rankNum], popNames.maleNumber[rankNum] );
            }
            if ( atoi(gender) == 1 )
            {
                printf( "Rank %d: Female: %s (%d)\n", (rankNum+1), popNames.femaleName[rankNum], popNames.femaleNumber[rankNum] );
            }
        }

        else if ( strcmp(choice, "search\n") == 0 ) /*when the user selects search*/
            {
            printf( "What name do you want to search for? [case sensitive]:\n"); /*retrieves desired rank from user*/
            fgets(name,500,stdin);
            
            while ( genderCheck == 1 )
            {
                printf( "Do you wish to search male (0), female (1), or both (2) name? [0-2]:\n"); /*retrieves desired rank from user*/
                fgets(gender,500,stdin);
                if ( ( (atoi(gender)) != 0 ) & ( (atoi(gender)) != 1 ) & ( (atoi(gender)) != 2 ) )
                {
                printf( "Only the numbers 0, 1, or 2 are acceptable.\n" );
                }
                else
                {
                    genderCheck = 0;
                }
            }

            if ( (atoi( gender )) == 0 )
            {   
                i = 0;
                name[ strlen(name)-1 ] = '\0';
            
                for ( i = 0; i < 202; i++)
                {
                    if ( strcmp( popNames.maleName[i], name ) == 0 )
                    {
                        printf( "In %s, the male name %s is ranked %d with a count of %d.\n", decade, name, (i + 1) , popNames.maleNumber[i]  );
                        i = 202;
                    }
                    if ( i == 201)
                    {
                        printf( "In %s, the male name %s is not ranked.\n", decade, name);
                    }
                    
                    
                }
                
            }


            if ( (atoi( gender )) == 1 )
            {   
                i = 0;
                name[ strlen(name)-1 ] = '\0';
            
                for ( i = 0; i < 202; i++)
                {
                    if ( strcmp( popNames.femaleName[i], name ) == 0 )
                    {
                        printf( "In %s, the female name %s is ranked %d with a count of %d.\n", decade, name, (i + 1) , popNames.femaleNumber[i]  );
                        i = 202;
                    }
                    if ( i == 201)
                    {
                        printf( "In %s, the female name %s is not ranked.\n", decade, name);
                    }
                    
                    
                }
                
            }

            if ( (atoi( gender )) == 2 )
            {   
                i = 0;
                name[ strlen(name)-1 ] = '\0';
            
                for ( i = 0; i < 201; i++)
                {
                    if ( strcmp( popNames.femaleName[i], name ) == 0 )
                    {
                    femaleRank = ( i - 1 );
                        i = 201;
                    }
                    if ( i == 200)
                    {
                        femaleRank = -1;
                    }
                    
                }
                
                for ( i = 0; i < 201; i++)
                {
                    if ( strcmp( popNames.maleName[i], name ) == 0 )
                    {
                        maleRank = ( i - 1 );
                        i = 201;
                    }
                    if ( i == 200)
                    {
                        maleRank = -1;
                    }
                    
                    
                }            
                    
                if ( maleRank == -1 && femaleRank == -1)
                {
                    printf( "In %s, the female name %s is not ranked and the male name %s is not ranked.\n", decade, name, name );
                }
                else if ( maleRank == -1 && femaleRank != -1)
                {
                    printf( "In %s, the female name %s is ranked %d with a count of %d and the male name %s is not ranked.\n", decade, name, (femaleRank+2), popNames.femaleNumber[femaleRank], name );
                }
                else if ( maleRank != -1 && femaleRank == -1)
                {
                    printf( "In %s, the female name %s is not ranked and the male name %s is ranked %d with a count of %d.\n", decade, name, name, (maleRank+2), popNames.maleNumber[maleRank] );
                }
                else if ( maleRank != -1 && femaleRank != -1)
                {
                    printf( "In %s, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d.\n", decade, name, (femaleRank+2), popNames.femaleNumber[femaleRank], name,  (maleRank+2), popNames.maleNumber[maleRank] );
                }
            }


            }
            


        else if ( strcmp(choice, "top\n") == 0 ) /*when the user selects top*/
        {
        for ( j=0; j<10; j++ ) {
            printf ( "%-6d %-11s %-11d %-11s %-11d\n", popNames.rank[j], popNames.maleName[j], popNames.maleNumber[j], 
                                                            popNames.femaleName[j], popNames.femaleNumber[j] );
            }
        }
            
   while ( yesNoCheck == 1 )
            {
                printf( "Do you want to ask another question about %d? [Y or N]:\n", decadeNum); /*retrieves desired rank from user*/
                fgets(yesOrNo,500,stdin);
                if ( ( strcmp(yesOrNo, "N\n") != 0 ) & ( strcmp(yesOrNo, "Y\n") != 0 ) &  ( strcmp(yesOrNo, "n\n") != 0 ) & ( strcmp(yesOrNo, "y\n") != 0 ) )
                {
                printf( "Only the single characters Y or N are acceptable.\n" );
                }
                else
                {
                    yesNoCheck = 0;
                }
            }
            yesNoCheck = 1;            
            if ( ( strcmp(yesOrNo, "Y\n") == 0 ) || ( strcmp(yesOrNo, "y\n") == 0 ) )
            {
                loop = 1;
                
            }
            else if ( ( strcmp(yesOrNo, "N\n") == 0 ) || ( strcmp(yesOrNo, "n\n") == 0 ) )
            {
                while ( yesNoCheck == 1 )
                {
                    printf( "Would you like to select another year? [Y or N]:\n"); /*retrieves desired rank from user*/
                    fgets(yesOrNo,500,stdin);
                    if ( ( strcmp(yesOrNo, "N\n") != 0 ) & ( strcmp(yesOrNo, "Y\n") != 0 ) & ( strcmp(yesOrNo, "y\n") != 0 ) & ( strcmp(yesOrNo, "n\n") != 0 ))
                    {
                    printf( "Only the single characters Y or N are acceptable.\n" );
                    }
                    else
                    {
                        yesNoCheck = 0;
                    }
                }                   
                if ( ( strcmp(yesOrNo, "Y\n") == 0 ) || ( strcmp(yesOrNo, "y\n") == 0 ))
                {
                    masterLoop = 1;
                    loop = 0;
                }
                else if (  ( strcmp(yesOrNo, "N\n") == 0 ) || ( strcmp(yesOrNo, "n\n") == 0 ) )
                {
                    printf ( "Thank you for using babyQuery.\n" );
                    return(0);
                }
                
                
            }
            
        }
    }
printf ( "Thank you for using babyQuery.\n");
return(0);

}