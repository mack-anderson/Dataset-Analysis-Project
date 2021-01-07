#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "babies.h"

int main( int argc, char *argv[] ) {

char maleSNumber[MAXLENGTH];
char femaleSNumber[MAXLENGTH] ;
char maleSNumber2[MAXLENGTH];
char femaleSNumber2[MAXLENGTH] ;
char decade[10];
char choice[10];
char rank[10];
int rankNum;
char gender[10];
char name[10];
char string[100];
char string2[100];
char dec1[100];
char dec2[100];
char decade1[10];
char decade2[10];
char topMaleNames[MAXLENGTH];
char topFemaleNames[MAXLENGTH];
char comma[5];
int j;
char yesOrNo[MAXLENGTH];
int masterLoop = 1;
int femaleRank2;
int maleRank2;

FILE*f1; 
FILE*f2;

strcpy(comma, ", ");
strcpy(topMaleNames, " ");
strcpy(topFemaleNames, " ");


while ( masterLoop == 1 )
    {

    int decadeNum1 = 0;
    int decadeNum2 = 0;
    int i = 0;
    int loop = 1;
    int q;
    int decadeCheck = 1;
   

    while ( decadeCheck == 1) 
    {   
        printf( "What decade do you want to look at? [1880 to 2010]:\n"); /*get the decade desired by the user*/
        fgets(decade,500,stdin);
        reduceSpace(decade);
        for ( i = 0; i < 4; i++)
        {
            decade1[i] = decade[i];
        }
        decade1[4] = '\0';
        
        q = 0;
        for ( i = 5; i < 9; i++)
        {
            decade2[q] = decade[i];
            q++;
        }
        decade2[4] = '\0';
        
        
        decadeNum1 = atoi(decade1);
        decadeNum2 = atoi(decade2);

        if ( ( (atoi(decade1) != 1880) & (atoi(decade1) != 1890) & (atoi(decade1) != 1900) & (atoi(decade1) != 1910) & (atoi(decade1) != 1920) & (atoi(decade1) != 1930) & (atoi(decade1) != 1940) & (atoi(decade1) != 1950) & (atoi(decade1) != 1960) & (atoi(decade1) != 1970) & (atoi(decade1) != 1980) & (atoi(decade1) != 1990) & (atoi(decade1) != 2000) & (atoi(decade1) != 2010) & (atoi(decade1) != 1880) & (atoi(decade1) != 1890) & (atoi(decade1) != 1900) & (atoi(decade1) != 1910) & (atoi(decade1) != 1920) & (atoi(decade1) != 1930) & (atoi(decade1) != 1940) & (atoi(decade1) != 1950) & (atoi(decade1) != 1960) & (atoi(decade1) != 1970) & (atoi(decade1) != 1980) & (atoi(decade1) != 1990) & (atoi(decade1) != 2000) & (atoi(decade1) != 2010) ) || (atoi(decade1) == atoi(decade2)) )
        {
            printf( "The response must be two of 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010, separated by at least one space. No other numbers are acceptable. Both numbers cannot be the same.\n");
        }

        else
        {
            decadeCheck = 0;
        }

    }

   
    sprintf( dec1, "%sNames.txt", decade1 );
   

    if ( (f1 = fopen( dec1, "r")) != NULL ) 
    {   
        i = 0;
        while ( fgets(string, 100, f1) != NULL ) {
            sscanf (string, "%d %s %s %s %s", &popNames.rank[i], popNames.maleName[i], maleSNumber, popNames.femaleName[i], femaleSNumber);
    /* printf ( "%d %s %s %s %s\n",popNames.rank[i],popNames.maleName[i],maleSNumber,popNames.femaleName[i],femaleSNumber ); */
            removeCommas ( maleSNumber );
            removeCommas ( femaleSNumber );
            popNames.maleNumber[i] = atoi ( maleSNumber );
            popNames.femaleNumber[i] = atoi ( femaleSNumber );
            i++;
        }
        fclose( f1 );
    } 
    
    else {
        printf ( "Cannnot open %s\n", argv[1] );
        return ( -2 );
    }

    sprintf( dec2, "%sNames.txt", decade2 );


    if ( (f2 = fopen( dec2, "r")) != NULL ) 
    {   
        i = 0;
        while ( fgets(string2, 100, f1) != NULL ) {
            sscanf (string2, "%d %s %s %s %s", &popNames2.rank[i], popNames2.maleName[i], maleSNumber2, popNames2.femaleName[i], femaleSNumber2);
    /* printf ( "%d %s %s %s %s\n",popNames2.rank[i],popNames2.maleName[i],maleSNumber,popNames2.femaleName[i],femaleSNumber ); */
            removeCommas ( maleSNumber2 );
            removeCommas ( femaleSNumber2 );
            popNames2.maleNumber[i] = atoi ( maleSNumber2 );
            popNames2.femaleNumber[i] = atoi ( femaleSNumber2 );
            i++;
        }
        fclose( f2 );
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
            fflush(stdin);
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
                printf( "Rank %d: %d: Male: %s (%d) and Female: %s (%d)\n", (rankNum+1), decadeNum1, popNames.maleName[rankNum], popNames.maleNumber[rankNum], popNames.femaleName[rankNum], popNames.femaleNumber[rankNum] );
                printf( "        %d: Male: %s (%d) and Female: %s (%d)\n", decadeNum2,  popNames2.maleName[rankNum], popNames2.maleNumber[rankNum], popNames2.femaleName[rankNum], popNames2.femaleNumber[rankNum] );
            }
            else if ( atoi(gender) == 0 )
            {
                printf( "Rank %d: %d: Male: %s (%d)\n", (rankNum+1), decadeNum1, popNames.maleName[rankNum], popNames.maleNumber[rankNum]);
                printf( "        %d: Male: %s (%d)\n", decadeNum2,  popNames2.maleName[rankNum], popNames2.maleNumber[rankNum] );
            
            }
            if ( atoi(gender) == 1 )
            {
                printf( "Rank %d: %d: Female: %s (%d)\n", (rankNum+1), decadeNum1, popNames.femaleName[rankNum], popNames.femaleNumber[rankNum] );
                printf( "        %d: Female: %s (%d)\n", decadeNum2, popNames2.femaleName[rankNum], popNames2.femaleNumber[rankNum] );
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
            
                for ( i = 0; i < 201; i++)
                {
                    if ( strcmp( popNames.maleName[i], name ) == 0 )
                    {
                        printf( "In %d, the male name %s is ranked %d with a count of %d.\n", decadeNum1, name, (i + 1) , popNames.maleNumber[i]  );
                        i = 201;
                    }
                    if ( i == 200)
                    {
                        printf( "In %d, the male name %s is not ranked and\n", decadeNum1, name);
                    }
                    
                    
                }

                for ( i = 0; i < 201; i++)
                {
                    if ( strcmp( popNames2.maleName[i], name ) == 0 )
                    {
                        printf( "in %d, the male name %s is ranked %d with a count of %d.\n", decadeNum2, name, (i + 1) , popNames2.maleNumber[i]  );
                        i = 201;
                    }
                    if ( i == 200)
                    {
                        printf( "In %d, the male name %s is not ranked.\n", decadeNum2, name);
                    }
                    
                    
                }
                
            }


            if ( (atoi( gender )) == 1 )
            {   
                i = 0;
                name[ strlen(name)-1 ] = '\0';
            
                for ( i = 0; i < 201; i++)
                {
                    if ( strcmp( popNames.femaleName[i], name ) == 0 )
                    {
                        printf( "In %d, the female name %s is ranked %d with a count of %d and\n", decadeNum1, name, (i + 1) , popNames.femaleNumber[i]  );
                        i = 201;
                    }
                    if ( i == 200)
                    {
                        printf( "In %d, the female name %s is not ranked and.\n", decadeNum2, name);
                    }
                    
                    
                }
                
                for ( i = 0; i < 201; i++)
                {
                    if ( strcmp( popNames2.femaleName[i], name ) == 0 )
                    {
                        printf( "in %d, the female name %s is ranked %d with a count of %d.\n", decadeNum2, name, (i + 1) , popNames2.femaleNumber[i]  );
                        i = 201;
                    }
                    if ( i == 200)
                    {
                        printf( "In %d, the female name %s is not ranked.\n", decadeNum2, name);
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

                for ( i = 0; i < 201; i++)
                {
                    if ( strcmp( popNames2.femaleName[i], name ) == 0 )
                    {
                    femaleRank2 = ( i - 1 );
                        i = 201;
                    }
                    if ( i == 200)
                    {
                        femaleRank2 = -1;
                    }
                    
                }
                
                for ( i = 0; i < 201; i++)
                {
                    if ( strcmp( popNames2.maleName[i], name ) == 0 )
                    {
                        maleRank2 = ( i - 1 );
                        i = 201;
                    }
                    if ( i == 200)
                    {
                        maleRank2 = -1;
                    }
                    
                                        
                }            
                    
                if ( maleRank == -1 && femaleRank == -1)
                {
                    printf( "In %d, the female name %s is not ranked and the male name %s is not ranked.\n", decadeNum1, name, name );
                }
                else if ( maleRank == -1 && femaleRank != -1)
                {
                    printf( "In %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked.\n", decadeNum1, name, (femaleRank+2), popNames.femaleNumber[femaleRank], name );
                }
                else if ( maleRank != -1 && femaleRank == -1)
                {
                    printf( "In %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d.\n", decadeNum1, name, name, (maleRank+2), popNames.maleNumber[maleRank] );
                }
                else if ( maleRank != -1 && femaleRank != -1)
                {
                    printf( "In %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d.\n", decadeNum1, name, (femaleRank+2), popNames.femaleNumber[femaleRank], name,  (maleRank+2), popNames.maleNumber[maleRank] );
                }
                
                
                if ( maleRank2 == -1 && femaleRank2 == -1)
                {
                    printf( "And in %d, the female name %s is not ranked and the male name %s is not ranked.\n", decadeNum2, name, name );
                }
                else if ( maleRank2 == -1 && femaleRank2 != -1)
                {
                    printf( "And in %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked.\n", decadeNum2, name, (femaleRank2+2), popNames2.femaleNumber[femaleRank2+1], name );
                }
                else if ( maleRank2 != -1 && femaleRank2 == -1)
                {
                    printf( "And in %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d.\n", decadeNum2, name, name, (maleRank2+2), popNames2.maleNumber[maleRank2+1] );
                }
                else if ( maleRank2 != -1 && femaleRank2 != -1)
                {
                    printf( "And in %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d.\n", decadeNum2, name, (femaleRank2+2), popNames2.femaleNumber[femaleRank2+1], name,  (maleRank2+2), popNames2.maleNumber[maleRank2+1] );
                }
            }


            }
            


        else if ( strcmp(choice, "top\n") == 0 ) /*when the user selects top*/
        {   
            j = 0;
            i = 0;
            for ( j=0; j<11; j++ ) {
                
                for ( i = 0; i < 11; i++)
                {            

                    if ( ( strcmp( popNames.maleName[j], popNames2.maleName[i] ) == 0 ) )
                    {
                        strcat ( topMaleNames, popNames.maleName[j] );
                        strcat ( topMaleNames, comma );
                        
                    }
                     

                }
            }        
            topMaleNames[ strlen(topMaleNames) - 2 ] = '\0';
            printf( "Male names that appear in both %d and %d Top Tens:%s\n", decadeNum1, decadeNum2, topMaleNames );

            j = 0;
            i = 0;
            for ( j=0; j<11; j++ ) {
                
                for ( i = 0; i < 11; i++)
                {            

                    if ( ( strcmp( popNames.femaleName[j], popNames2.femaleName[i] ) == 0 ) )
                    {
                        strcat ( topFemaleNames, popNames.femaleName[j] );
                        strcat ( topFemaleNames, comma );
                    }
                    

                }
            }        
            topFemaleNames[ strlen(topFemaleNames) - 2 ] = '\0';
            printf( "Female names that appear in both %d and %d Top Tens:%s\n", decadeNum1, decadeNum2, topFemaleNames );   

        }
            while ( yesNoCheck == 1 )
            {
                printf( "Do you want to ask another question about %d and %d? [Y or N]:\n", decadeNum1, decadeNum2); /*retrieves desired rank from user*/
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
                    printf( "Would you like to select other decades? [Y or N]:\n"); /*retrieves desired rank from user*/
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