//
// encrypt.c
//

#include <string.h>

#include "encrypt.h"


char CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int CHARS_LEN = 62;


char shiftChar(char c, int shift, int direction)
{
  // implement the character shift here:
  //  given a char c shift it either forwards (direction == 1) or backwards (direction == 0)
  //  use the CHARS array above
  //  return the newly shifted char
  //
  // eg.
  //   shiftChar('c', 3, 1) : 'f'
  //   shiftChar('S', 2, 0) : 'P'
  //   shiftChar('b', 3, 0) : '8'
  
  // For a-z, changes ASCII number to match index in array
  int index = c - 97;
  
  // For A-Z, changes ASCII number to match index in array
  if (-32 <= index && index <= -7)
  {
    index += 58;
  }
  // For 0-9, changes ASCII number to match index in array
  else if (-49 <= index && index <= -40)
  {
    index += 101;
  }
  
  // Shift forwards
  if (direction == 1)
  {
    index += shift;
    
    // Keep index in bounds of array
    if (index > 61)
    {
      index -= 62;
    }
    else if (index < 0)
    {
      index += 62;
    }
    
    return CHARS[index];
  }
  // Shift backwards
  else
  {
    index -= shift;
    
    // Keep index in bounds of array
    if (index > 61)
    {
      index -= 62;
    }
    else if (index < 0)
    {
      index += 62;
    }
    
    return CHARS[index];
  }
}


void encrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 1);
  }
}


void decrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 0);
  }
}


void caesarEncrypt(char str[], int shift)
{
  int shifts[] = { shift };
  encrypt(str, shifts, 1);
}


void caesarDecrypt(char str[], int shift)
{
  int shifts[] = { shift };
  decrypt(str, shifts, 1);
}


