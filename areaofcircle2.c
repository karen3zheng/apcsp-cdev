#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main

float areaOfCircle(float radius)
{
  float area = radius * radius * M_PI;
  return area;
}


int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  float start = 5.2;
  int reps = 3;
  
  int arg1;
  int arg2;
  
  // for testing only - do not change
  getTestInput(argc, argv, &start, &reps);
  
  if (argc == 1)
  {
    char int1[256];
    char int2[256];
    
    printf("Please enter the first integer\n");
    while (1)
    {
      fgets(int1, 256, stdin);
      if (sscanf(int1, "%d", &arg1) == 1)
      {
        sscanf(int1, "%d", &arg1);
        break;
      } 
      printf("Not a valid integer, please try again\n");
    }
    
    printf("Please enter the second integer\n");
    while (1)
    {
      fgets(int2, 256, stdin);
      if (sscanf(int2, "%d", &arg2) == 1)
      {
        sscanf(int2, "%d", &arg2);
        break;
      } 
      printf("Not a valid integer, please try again\n");
    }
    
    if (arg1 < 0 || arg2 < 0)
    {
      printf("Make sure both integers are not negative\n");
      return 1;
    }
    
    if (arg2 < arg1)
    {
      printf("Make sure the second integer is greater than the first integer\n");
      return 1;
    }
    
    start = arg1;
    reps = arg2 - arg1 + 1;
  }
  else 
  {
    if (argc != 3)
    {
      printf("%s expected 2 args, please enter 2 integers\n", argv[0]);
      return 1;
    }
    
    if (sscanf(argv[1], "%d", &arg1) != 1)
    {
      printf("The first arg is not an integer, please enter 2 integers\n");
      return 1;
    }
    
    if (sscanf(argv[2], "%d", &arg2) != 1)
    {
      printf("The second arg is not an integer, please enter 2 integers\n");
      return 1;
    }
    
    sscanf(argv[1], "%d", &arg1);
    sscanf(argv[2], "%d", &arg2);
    
    if (arg1 < 0 || arg2 < 0)
    {
      printf("Make sure both integers are not negative\n");
      return 1;
    }
    
    if (arg2 < arg1)
    {
      printf("Make sure the second integer is greater than the first integer\n");
      return 1;
    }
    
    start = arg1;
    reps = arg2 - arg1 + 1;
  }

  printf("calculating area of circle starting at %f, and ending at %f\n", start, start+reps-1);
  
  // add your code below to call areaOfCircle function with values between
  // start and end

  for (float i = start; i <= start + reps - 1; i++)
  {
    float area = areaOfCircle(i);
    printf("The area of a circle with radius %f is %f\n", i, area);
  }

  
}
