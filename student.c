#include <stdio.h>
#include <string.h>


// student structure
//struct Student...

struct Student
{
  char firstName[256];
  char lastName[256];
  int age;
  int id;
};

void printStudent(struct Student* student)
{
  printf("name: %s %s\n", student->firstName, student->lastName);
  printf("age: %d\n", student->age);
  printf("id: %d\n", student->id);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for (int i = 0; i < num; i++)
  {
    printf("\n---- student %d ----\n", i);
    printStudent(&students[i]);
  }
}


int main()
{

  // an array of students
  //xxx students;
  struct Student students[256];
  int numStudents = 0;
  char input[256];
  char firstName[256];
  char lastName[256];
  char age[256];
  char id[256];

  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit: ");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      
      printf("\nPlease enter the student's first name: ");
      fgets(firstName, 256, stdin);
      strcpy(students[numStudents].firstName, firstName);
        
      printf("\nPlease enter the student's last name: ");
      fgets(lastName, 256, stdin);
      strcpy(students[numStudents].lastName, lastName);
        
      printf("\nPlease enter the student's age: ");
      while (1)
      {
        fgets(age, 256, stdin);
        if (sscanf(age, "%d", &students[numStudents].age))
        {
          sscanf(age, "%d", &students[numStudents].age);
          break;
        }
        printf("\nPlease enter a number for the student's age: ");
      }
        
      printf("\nPlease enter the student's id: ");
      while (1)
      {
        fgets(id, 256, stdin);
        if (sscanf(id, "%d", &students[numStudents].id))
        {
          sscanf(id, "%d", &students[numStudents].id);
          break;
        }
        printf("\nPlease enter a number for the student's id: ");
      }
        
      numStudents++; 
    }
  }
  
  printf("\nGoodbye!\n");
}
