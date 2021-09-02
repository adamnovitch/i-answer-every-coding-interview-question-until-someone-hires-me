#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress (const char *string)
{
  char *result;
  char *current = result;
  char previous = 0;
  char compression_count = 0;
  for (int index = 0; index < strlen(string); index++)
  {
    if (previous)
    {
      if (previous == string[index])
      {
        compression_count++;
      }
      else
      {
        printf("%c %d %c\n",previous,compression_count,*current);
        *(current++) = previous;
        *(current++) = (compression_count + '0');
      }
    }
    previous = string[index];
  }
  printf("%s\n",result);
}

void main ()
{
    int test_length = 4;
    char *input[test_length];
    input[0] = "aaaabbbbccdeeeeeeff";
    input[1] = "ggghhhiijkkkllllmmm";
    input[2] = "nnnnooooooooppqrrrs";
    input[3] = "tuvvvvvvvvvvvvvvwww";

    for (int test_case = 0; test_case < test_length; test_case++)
    {
      compress(input[test_case]);
    }
}