#include <stdio.h>
#include <string.h>

int permutation (const char *string_1, const char *string_2)
{
    char characters[256];
    memset(characters,0,256 * sizeof(char));
    int result = 0;
    for (int index = 0; index < strlen(string_1); index++)
    {
        if (string_1[index] != ' ')
        {
            characters[string_1[index]]++;
        }
    }
    for (int index = 0; index < strlen(string_2); index++)
    {
        if (string_2[index] != ' ')
        {
            characters[string_2[index]]--;
        }
    }
    for (int index = 0; index < 256; index++)
    {
        if (characters[index] != 0)
        {
            result = 1;
        }
    }
    return result;
}

void main ()
{
    char *string_1[7];
    string_1[0] = "tom marvolo riddle";
    string_1[1] = "adam novitch";
    string_1[2] = "adam novitch";
    string_1[3] = "anagram";
    string_1[4] = "angel";
    string_1[5] = "thing";
    string_1[6] = "bus";

    char *string_2[7];
    string_2[0] = "i am lord voldemort";
    string_2[1] = "acid moth van";
    string_2[2] = "havoc damn it";
    string_2[3] = "nag a ram";
    string_2[4] = "glean";
    string_2[5] = "night";
    string_2[6] = "sub";
    
    int results[7] = { 0, 0, 0, 0, 0, 0, 0};
    int exp;
    int act;
    for (int index = 0; index < 7; index++)
    {
        exp = results[index];
        act = permutation(string_1[index],string_2[index]);
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