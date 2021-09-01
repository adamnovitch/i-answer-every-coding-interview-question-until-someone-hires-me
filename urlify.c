#include <stdio.h>
#include <string.h>

char * urlify (const char *string)
{
    const char *replacement = "%20";
    const int offset = sizeof(replacement);
    int leading = 1;
    int trailing = 0;
    char *result;
    for (int index = 0; index < strlen(string); index++)
    {
        if (leading)
        {
            if (string[index] != ' ')
            {
                *result = string[index];
                leading = 0;
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
        if (output == result[index])
        {
            printf("Test case %d: Correct!\n",index+1);
        }
        else
        {
            printf("Test case %d: Incorrect!\n",index+1);
        }
    }
}