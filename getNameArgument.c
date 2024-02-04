#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdarg.h>
#include <ctype.h>//tolower()

/* Use getopt() to parse argument 
 * check man page for the complete documentation
 * getopt() go through all argument (argv) 
 * with a given max (argc).
 * getopt() will return -1 when all arguments are parsed
 * otherwise return the argument.
 * 3 arguments of getopt is the option passes to the program.
 * there are set as follow: "if:tu". the options will be -iftU.
 * options are single character. if the character is preceded 
 * by ':', it means that this option does not have an argument(tu).
 * if the option is succeded by ':' it need an argument (if)
*/

void printBlue(int countArg,...)
{
    va_list args;
    va_start(args,countArg);
    for(int i=1; i<=countArg; i++)
    {
        char* ptr_c = va_arg(args,char*);
        printf("\033[0;33m%s\033[0m",ptr_c);
    }
    va_end(args);
    printf("\n");
}

void printRed(char* phrase)
{
    printf("\033[0;31m%s\033[0m",phrase);
}

int main (int argc, char* argv[])
{
    int opt_arg_index = 0;
    char* name = NULL;
    while( (opt_arg_index = getopt(argc, argv, "u:gf")) != -1)
    {
        switch(opt_arg_index)
        {
            case 'u':
                name = optarg;
                printf("user is selected\n");
                printBlue(2,"your name is ",name);
                break;
            case 'g':
                printf("group is selected\n");
                break;
           case 'f':
                printRed("option invalidu\n");
            break;
           default:
                printRed("option invalid\n");
                return 1;
        }
    }
    return 0;
}
