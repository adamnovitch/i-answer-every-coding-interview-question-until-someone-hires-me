#include <stdio.h>
#include <string.h>

int unique (char *input)
{
    char characters[255];
    memset(characters,0,255);
    int result = 0;
    for (int index = 0; index < strlen(input); index++)
    {
        if (characters[input[index]] == 1)
        {
            result = 1;
            break;
        }
        characters[input[index]] = 1;
    }
    return result;
}

void main ()
{
    char *string[7];
    string[0] = "hello";      // no
    string[1] = "today";      // yes
    string[2] = "is the";     // yes
    string[3] = "day that";   // no
    string[4] = "my pathetic";// no
    string[5] = "existence";  // no
    string[6] = "ends";       // yes

    int results[7] = { 1, 0, 0, 1, 1, 1, 0};
    int exp;
    int act;
    for (int index = 0; index < 7; index++)
    {
        exp = results[index];
        act = unique(string[index]);
        if (exp == act)
        {
            printf("Test case %d: Correct!\n",index+1);
        }
        else
        {
            printf("Test case %d: Incorrect! Expected %d, Actual %d\n",index+1,exp,act);
        }
    }
}