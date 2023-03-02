/*
how to change character in particular string
for example: 
  collection[0][0] = 'A';
  collection[1][1] = 'P';
  
  doing this gives segment error

and how to print this character by character like example 1.0 below
(for char type pointer to pointer)
  example 1.0:
    char *str = "apple";
    char *cpstr = str;
    while (*cpstr != '\0')
      putchar(*cpstr++);
 
*/
//below is the code..

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {
   const char *str = "apple";
   char **collection = (char **)malloc(5*strlen(str)*sizeof(char)+1);

   collection[0] = "apple";
   collection[1] = "apple";
   collection[2] = "apple";
   collection[3] = "apple";
   collection[4] = "apple";

   collection[0][0] = 'A';
   collection[1][1] = 'P';

   return 0;
}