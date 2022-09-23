#include <stdio.h>
#include <string.h>

int main() {
  const int NUM_NEW_EMPLOYEES = 4;
  
  const int DEFAULT_SALARY = 75000;
  int salary[NUM_NEW_EMPLOYEES];
  int i;
  
  char employee[NUM_NEW_EMPLOYEES][24];
  
  for (i = 0; i < NUM_NEW_EMPLOYEES; i++) {
    strcpy(employee[i], "");
    salary[i] = 75000;
  }

  while (1) {
    printf("Enter the employee number [0-3] to add name (-1 to quit): ");
    int num;
    char buffer[24];
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
  }
}

