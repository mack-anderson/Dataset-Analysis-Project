#include <string.h>

int chop ( char *line ) {
    if (*( line + strlen(line)-1) != '\n') /*check for newline character at end of line*/
    {
       return(-1); /*returns -1 when unsuccessful*/
    }
    else
    {
        *( line + strlen(line) - 1) = '\0'; /*replace newline character with \0*/
        return (0); /*return 0 on success*/
    }
}