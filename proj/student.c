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

void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
  
  Student* student = (Student*)malloc(sizeof(Student));
  char* firstName = (char*)malloc((strlen(fname) + 1) * sizeof(char));
  char* lastName = (char*)malloc((strlen(lname) + 1) * sizeof(char));
  
  strcpy(firstName, fname);
  strcpy(lastName, lname);
  
  student->firstName = firstName;
  student->lastName = lastName;
  student->age = age;
  student->id = id;
  
  students[numStudents] = student;
  
  numStudents++;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student);
  free(student->firstName);
  free(student->lastName);
}


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
    char fName[256] = { '\0' };
    char lName[256] = { '\0' };
    char age[256] = { '\0' };
    char id[256] = { '\0' };
    int numSaved = 0;
    
    for (int i = 0; i < numStudents; i++)
    {
      strcpy(fName, students[i]->firstName);
      strcpy(lName, students[i]->lastName);
      sprintf(age, "%d", students[i]->age);
      sprintf(id, "%ld", students[i]->id);
        
      if (cipher == 'c' && key != 0)
      {
        caesarEncrypt(fName, key);
        caesarEncrypt(lName, key);
        caesarEncrypt(age, key);
        caesarEncrypt(id, key);
      }
      else if (cipher == 'v')
      {
        encrypt(fName, shiftArr, shiftNum);
        encrypt(lName, shiftArr, shiftNum);
        encrypt(age, shiftArr, shiftNum);
        encrypt(id, shiftArr, shiftNum);
      }
    
      fprintf(fp, "%s %s %s %s\n", fName, lName, age, id);
      printf("saving: %s %s %s %s\n", fName, lName, age, id);
      
      numSaved = i + 1;
    }
    
    printf("saved %d students\n", numSaved);
    
    fclose(fp);
  }
}


void loadStudents(int key, int shiftArr[], int shiftNum, char cipher)
{
  // load the students from the data file overwriting all exisiting students in memory
  
  deleteStudents();
  
  FILE* fp;
  
  fp = fopen(STUFILE, "r");
  if (fp)
  {
    char firstName[256] = { '\0' };
    char lastName[256] = { '\0' };
    char age[256] = { '\0' };
    char id[256] = { '\0' };
    int numLoaded = 0;
    
    unsigned int ageNum = 0;
    long idNum = 0;
    
    while (1)
    {
      if (fscanf(fp, "%s %s %s %s\n", firstName, lastName, age, id) == 4)
      {
        if (cipher == 'c' && key != 0)
        {
          caesarDecrypt(firstName, key);
          caesarDecrypt(lastName, key);
          caesarDecrypt(age, key);
          caesarDecrypt(id, key);
        }
        else if (cipher == 'v')
        {
          decrypt(firstName, shiftArr, shiftNum);
          decrypt(lastName, shiftArr, shiftNum);
          decrypt(age, shiftArr, shiftNum);
          decrypt(id, shiftArr, shiftNum);
        }
      
        sscanf(age, "%d", &ageNum);
        sscanf(id, "%ld", &idNum);
        createStudent(firstName, lastName, ageNum, idNum);
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


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}



