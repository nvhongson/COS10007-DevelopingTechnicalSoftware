#include<stdio.h>
#include"myfile.h"
 
int main() {
   int num1 = 10, num2 = 10, num3;
   num3 = add(num1, num2);
   printf("Sum of two numbers : %d", num3);
   printf("\n");
   return 0;
}

