#include <stdio.h>
#include <string.h>

int main()
{
  // Create 2 strings
  char str1[27] = { '\0' };
  char str2[] = "abcdefghijklmnopqrstuvwxyz";
  
  // Fill str1
  for (int i = 0; i < 26; i++)
  {
    str1[i] = 97 + i;
  }
  
  // Compare str1 and str2
  if (strcmp(str1, str2) == 0)
  {
    printf("str1 and str2 are identical\n"); 
  }
  else
  {
    printf("str1 and str2 are different\n");
  }
  
  // Capitalize str1
  for (int i = 0; i < 26; i++)
  {
    str1[i] -= 32;
  }
  
  // Compare str1 and str2
  if (strcmp(str1, str2) == 0)
  {
    printf("str1 and str2 are identical\n"); 
  }
  else
  {
    printf("str1 and str2 are different\n");
  }
  
  // Create 3rd string
  char str3[53];
  strcpy(str3, str1);
  strcat(str3, str2);
  
  // Print all 3 strings
  printf("str1 is %s\nstr2 is %s\nstr3 is %s\n", str1, str2, str3);
  
}