/*  Defines */
#define MAXLENGTH 20
#define ROWS 200

/* Struct definitions */
struct pNames {
   int  year;
   int  rank[ROWS];
   char maleName[ROWS][MAXLENGTH];   
   int  maleNumber[ROWS];
   char femaleName[ROWS][MAXLENGTH];   
   int  femaleNumber[ROWS];
};

struct pNames popular; /*added on own remember*/
struct pNames popNames;
struct pNames popNames2;

/* Function definitions */
int removeCommas ( char * );
int reduceSpace ( char * );
int chop ( char * );



