#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);
  
  // Set float variables
  float d = 1.2;
  float e = 3.4;
  
  // Print values and addresses
  printf("\nThe value of d is %f\n", d);
  printf("The address of d is %p\n", &d);
  
  printf("\nThe value of e is %f\n", e);
  printf("The address of e is %p\n", &e);
  
  // Set pointers
  float* ptrtoe = &d;
  float* ptrtof = &e;
  
  // Switch d and e and print new values
  int tmp = *ptrtoe;
  *ptrtoe = *ptrtof;
  *ptrtof = tmp;
  
  printf("\nThe new value of d is %f\n", d);
  printf("The new value of e is %f\n", e);
}
