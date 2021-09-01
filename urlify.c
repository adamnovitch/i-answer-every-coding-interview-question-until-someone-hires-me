#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * urlify (const char *string)
{
    int leading = 1;
    int prev_space = 0;
    char *result = malloc(strlen(string));
    char *current = result;
    for (int index = 0; index < strlen(string); index++)
    {
        if (leading)
        {
            if (string[index] != ' ')
            {
                *(current++) = string[index];
                leading = 0;
            }
        }
        else
        {
            if (string[index] == ' ')
            {
                if (!prev_space)
                {
                    prev_space = 1;
                }
            }
            else
            {
                if (prev_space)
                {
                    *(current++) = '%';
                    *(current++) = '2';
                    *(current++) = '0';
                }
                *(current++) = string[index];
                prev_space = 0;
            }
        }
    }
    return result;
}

void main ()
{
    int test_length = 4;
    char *input[test_length];
    input[0] = "My cool website";
    input[1] = "My   spectacular   url";
    input[2] = "    geocities";
    input[3] = "   this  is  not  a drill   ";

    char *output;

    char *result[test_length];
    result[0] = "My%20cool%20website";
    result[1] = "My%20spectacular%20url";
    result[2] = "geocities";
    result[3] = "this%20is%20not%20a%20drill";

    for (int index = 0; index < test_length; index++)
    {
        output = urlify(input[index]);
        // strcmp is negated because we want a nonzero for its boolean
        if (!strcmp(output,result[index]))
        {
            printf("Test case %d: Correct!\n",index+1);
        }
        else
        {
            printf("Test case %d: Incorrect!\n\tExpected: %s %d\n\tActual  : %s %d\n",index+1,result[index],strlen(result[index]),output,strlen(output));
        }
    }
}