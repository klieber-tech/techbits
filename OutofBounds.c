// Code that asks user to enter new employees names.
// It first asks user to enter the employee number they want to edit
// then it asks to enter the employee name
// Employee salary is defaulted to 50,000

// Security vulnerability is for the user to be able to edit
// the default salary
#include <stdio.h>
#include <string.h>

int main() {
  const int NUM_NEW_EMPLOYEES = 5;
  
  const int DEFAULT_SALARY = 50000;
  int salary[NUM_NEW_EMPLOYEES];
  int i;
  
  char employee[NUM_NEW_EMPLOYEES][16];
  
  for (i = 0; i < NUM_NEW_EMPLOYEES; i++) {
    strcpy(employee[i], "");
    salary[i] = 50000;
  }

  while (1) {
    printf("Enter the employee number [0-4] to add name (-1 to quit): ");
    int num;
    char buffer[16];
    scanf("%d", &num);
    gets(buffer); //to get read of the newline characters
    if (num == -1) {
      return 0;
    } else {
      printf("Enter name of employee: ");
      gets(buffer);
      strcpy(employee[num], buffer);
    }

    for (i = 0; i < NUM_NEW_EMPLOYEES; i++) {
      printf("Salary for employee %d (%s) is %d\n", i, employee[i], salary[i]);
    }
    
    //for debugging to get the right memory address
    for (i = 0; i < NUM_NEW_EMPLOYEES; i++) {
      printf("Address for %d employee: name is %p, salary is %p\n", i, &employee[i], &salary[i]);
    }
  }
}

