#include <stdio.h>
#include <string.h>

#include "student.h"


const int BUFFSIZE=256;
char inputBuff[256];


int getInputNumber()
{
  int num;
  while (1)
  {
    fgets(inputBuff, BUFFSIZE, stdin);
    if (sscanf(inputBuff, "%ud", &num) == 1 && num >= 0) break;
                
    printf("\nNot a valid number - try again: ");
  }
  return num;
}


int main()
{
  char fname[BUFFSIZE];
  char lname[BUFFSIZE];

  // key to encrypt/decrypt
  int key = 0;
  
  int shiftArr[256] = { '0' };
  int shiftNum = 0;
  
  char cipher = 'c';

  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, l to load, s to save, e encrypt, q to quit: ");
    fgets(inputBuff, BUFFSIZE, stdin);
    if (sscanf(inputBuff, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      deleteStudents();
      break;
    }
    else if (c == 'p')
    {
      printStudents();
      continue;
    }
    else if (c == 'l')
    {
      loadStudents(key, shiftArr, shiftNum, cipher);
      continue;
    }
    else if (c == 's')
    {
      saveStudents(key, shiftArr, shiftNum, cipher);
      continue;
    }
    else if (c == 'e')
    {
      while (1)
      {
        printf("\nEnter v to use a Vigenere cipher, enter c to use a Caesar cipher: ");
        fgets(inputBuff, BUFFSIZE, stdin);
        if (sscanf(inputBuff, "%c", &c) != 1) continue;
        
        if (c == 'v')
        {
          while (1)
          {
            printf("\nEnter the number of shifts you want to use: ");
            shiftNum = getInputNumber();
            
            if (shiftNum <= 256)
              break;
            else
              printf("\nPlease enter a number under 256.");
          }
          
          for (int i = 0; i < shiftNum; i++)
          {
            printf("\nPlease enter shift %d: ", i + 1);
            
            shiftArr[i] = getInputNumber();
          }
          
          cipher = 'v';
          break;
        }
        else if (c == 'c')
        {
          printf("\nEnter an encrypt/decrypt key: ");
          
          key = getInputNumber();
          
          cipher = 'c';
          break;
          
        }
      }
    }
    else if (c == 'a')
    {
      // enter a new student      
      printf("\n First name: ");
      fgets(inputBuff, BUFFSIZE, stdin);
      sscanf(inputBuff, "%s", fname);

      printf(" Last name: ");
      fgets(inputBuff, BUFFSIZE, stdin);
      sscanf(inputBuff, "%s", lname);
          
      printf(" Enter age: ");
      int age = getInputNumber();

      printf(" Enter id: ");
      int id = getInputNumber();

      createStudent(fname, lname, age, id);
    }
  }
  
  printf("\nGoodbye!\n");
}
