//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};

// Creates a student dynamically
void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
  
  // Creates memory on heap for Student struct and 2 strings for first/last name
  Student* student = (Student*)malloc(sizeof(Student));
  student->firstName = (char*)malloc((strlen(fname) + 1) * sizeof(char));
  student->lastName = (char*)malloc((strlen(lname) + 1) * sizeof(char));
  
  strcpy(student->firstName, fname);
  strcpy(student->lastName, lname);
  student->age = age;
  student->id = id;
  
  students[numStudents] = student;
  
  numStudents++;
}

// Deletes a student and frees the memory
void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student);
  free(student->firstName);
  free(student->lastName);
}

// Delete students from array and free memory
void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
  
  for (int i = 0; i < numStudents; i++)
  {
    deleteStudent(students[i]);
    students[i] = 0;
    numStudents = 0;
  }
}

// Save students to file
void saveStudents(int key, int shiftArr[], int shiftNum, char cipher)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532 
  
  FILE* fp;
  
  fp = fopen(STUFILE, "w");
  if (fp)
  {
    // Strings that hold the information to be saved
    char fName[256] = { '\0' };
    char lName[256] = { '\0' };
    char age[256] = { '\0' };
    char id[256] = { '\0' };
    
    int numSaved = 0;
    
    for (int i = 0; i < numStudents; i++)
    {
      // Put f/l name in strings
      strcpy(fName, students[i]->firstName);
      strcpy(lName, students[i]->lastName);
      
      // Convert age and id and put them in strings
      sprintf(age, "%d", students[i]->age);
      sprintf(id, "%ld", students[i]->id);
        
      if (cipher == 'c' && key != 0) /// Encrypt each string with Caesar
      {
        caesarEncrypt(fName, key);
        caesarEncrypt(lName, key);
        caesarEncrypt(age, key);
        caesarEncrypt(id, key);
      }
      else if (cipher == 'v') // Encrypt each string with Vigenere
      {
        encrypt(fName, shiftArr, shiftNum);
        encrypt(lName, shiftArr, shiftNum);
        encrypt(age, shiftArr, shiftNum);
        encrypt(id, shiftArr, shiftNum);
      }
    
      // Write each string to the file
      fprintf(fp, "%s %s %s %s\n", fName, lName, age, id);
      printf("saving: %s %s %s %s\n", fName, lName, age, id);
      
      numSaved = i + 1;
    }
    
    printf("saved %d students\n", numSaved);
    
    fclose(fp);
  }
}

// Load students from file
void loadStudents(int key, int shiftArr[], int shiftNum, char cipher)
{
  // load the students from the data file overwriting all exisiting students in memory
  
  deleteStudents();
  
  FILE* fp;
  
  fp = fopen(STUFILE, "r");
  if (fp)
  {
    // Strings that hold the information to be loaded
    char fName[256] = { '\0' };
    char lName[256] = { '\0' };
    char age[256] = { '\0' };
    char id[256] = { '\0' };
    
    int numLoaded = 0;
    
    // Variables that will have age and id in the correct data type
    unsigned int ageNum = 0;
    long idNum = 0;
    
    while (1)
    {
      if (fscanf(fp, "%s %s %s %s\n", fName, lName, age, id) == 4)
      {
        if (cipher == 'c' && key != 0) // Decrypt each string with Caesar
        {
          caesarDecrypt(fName, key);
          caesarDecrypt(lName, key);
          caesarDecrypt(age, key);
          caesarDecrypt(id, key);
        }
        else if (cipher == 'v') // Decrypt each string with Vigenere
        {
          decrypt(fName, shiftArr, shiftNum);
          decrypt(lName, shiftArr, shiftNum);
          decrypt(age, shiftArr, shiftNum);
          decrypt(id, shiftArr, shiftNum);
        }
      
        // Get correct type from age and id strings
        sscanf(age, "%d", &ageNum);
        sscanf(id, "%ld", &idNum);
        
        // Create student
        createStudent(fName, lName, ageNum, idNum);
        numLoaded++;
      }
      else
      {
        break;
      }
    }
    
    printf("loaded %d students\n", numLoaded);
    
    fclose(fp);
  }
}

// Print all information from a Student struct
void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}

// Go through array of students and print each one
void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}



