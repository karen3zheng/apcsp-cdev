#include <stdio.h>
#include <string.h>

#include "student.h"


const int BUFFSIZE=256;
char inputBuff[256];

// Gets a positive number from the input, asks again if invalid
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
  
  // Array and array length used for Vigenere cipher
  int shiftArr[256] = { '0' };
  int shiftNum = 0;
  
  // Variable that shows which cipher is used
  char cipher = 'c';

  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, l to load, s to save, e encrypt, v to encrypt with Vigenere, q to quit: ");
    fgets(inputBuff, BUFFSIZE, stdin);
    if (sscanf(inputBuff, "%c", &c) != 1) continue; // Restart the loop if input is not 1 char
    if (c == 'q') // Free memory and quit
    {
      deleteStudents(); 
      break;
    }
    else if (c == 'p') // Print students
    {
      printStudents();
      continue;
    }
    else if (c == 'l') // Load students
    {
      loadStudents(key, shiftArr, shiftNum, cipher);
      continue;
    }
    else if (c == 's') // Save students
    {
      saveStudents(key, shiftArr, shiftNum, cipher);
      continue;
    }
    else if (c == 'e') // Enter encrypt key
    {
      printf("\nEnter an encrypt/decrypt key: ");
      key = getInputNumber();
          
      cipher = 'c';
    }
    else if (c == 'v') // Encrypt with Vigenere cipher
    {
      while (1) // Ask for input of how many shifts, asks again if over 256
      {
        printf("\nEnter the number of shifts you want to use: ");
        shiftNum = getInputNumber();
            
        if (shiftNum <= 256)
          break;
        else
          printf("\nPlease enter a number under 256.");
      }
          
      for (int i = 0; i < shiftNum; i++) // Asks for each shift one by one and saves them to array
      {
        printf("\nPlease enter shift %d: ", i + 1);
            
        shiftArr[i] = getInputNumber();
      }
          
      cipher = 'v';
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
