#include <stdio.h>
#include <stdlib.h>
#include "sortAlgo.h"
#include "searchAlgo.h"
#include "structDef.h"
#include "helpers.h"
#include <ctype.h>

int main() {
    	struct myStruct structArr[10];
    	FILE *fptr;
    	int i;
	int option;
    	if ((fptr = fopen("input.txt", "r")) == NULL) {
        	printf("file does not exist. Exiting program");
        	exit(1);
    	}

    	for (i = 0; i < 10; i++) {
        	fscanf(fptr, "%s", structArr[i].strVal);
    	}
    	for (i = 0; i < 10; i++) {
        	fscanf(fptr, "%d", &structArr[i].int1Val);
    	}
    	for (i = 0; i < 10; i++) {
        	fscanf(fptr, "%d", &structArr[i].int2Val);
	    	}
    	for (i = 0; i < 10; i++) {
        	fscanf(fptr, "%lf", &structArr[i].dblVal);
    	}
	fclose(fptr);
	
	do{
		option = 5;
		printf("\n");
		menu();
		scanf("%d", &option);
		switch(option){
	
			case 1:
				printArray(structArr, 10);
				break;
			case 2:
				printf("Sort by ascending or descending? (A or D): ");
				char sortOrder;
				scanf(" %c", &sortOrder);
				sortOrder = toupper(sortOrder);
				while (sortOrder != 'A' && sortOrder != 'D'){
					printf("Incorrect choice, try again\n");
					printf("Sort by ascending or descending? (A or D): ");
					scanf(" %c", &sortOrder);
					sortOrder = toupper(sortOrder);
				}
				printf("Which sorting algorithm would you like to use? Bubble Sort or Insertion Sort (B or I): ");
				char sortAlgoChoice;
				scanf(" %c", &sortAlgoChoice);
				sortAlgoChoice = toupper(sortAlgoChoice);
				while (sortAlgoChoice != 'B' && sortAlgoChoice != 'I'){
					printf("Incorrect choice, try again\n");
					printf("Which sorting algorithm would you like to use? Bubble Sort or Insertion Sort (B or I): ");
					scanf(" %c", &sortAlgoChoice);
					sortAlgoChoice = toupper(sortAlgoChoice);
					
				}
				if (sortAlgoChoice == 'B')
				{
					BubbleSort(structArr, 10, sortOrder);
  				      	printArray(structArr, 10);
        				printf("\nOutput written to output.txt\n");
        				printArraytoFile(structArr, 10);

				}
				else if (sortAlgoChoice == 'I')
				{
					InsertionSort(structArr, 10, sortOrder);
 					printArray(structArr, 10);
        				printf("\nOutput written to output.txt\n");
        				printArraytoFile(structArr, 10);

				}
				break;
			case 3:
				printf("Which search technique would you like to use? Linear or Binary (L or B): ");
				char searchOption;
				scanf(" %c", &searchOption);
				searchOption = toupper(searchOption);
				while (searchOption != 'L' && searchOption != 'B'){
					printf("Incorrect choice, try again \n");
					printf("Which search technique would you like to use? Linear or Binary (L or B): ");
					scanf(" %c", &searchOption);
					searchOption = toupper(searchOption);
				}
				char search[50];
				printf("Enter the string you would like to search: ");
				scanf("%s", search);
				if (searchOption == 'L'){
					int index = LinearSearch(structArr, 10, search, 0);
					if (index == -1){
						printf("String not found in array\n");
					}
				}
				else if (searchOption == 'B'){
					BubbleSort(structArr, 10, 'A');
					int index = BinarySearch(structArr,search, 0, 9);
					if (index == -1){
						printf("String not found in array\n");
					}
				}
				break;
			case 4:
				convertArraytoList(structArr, 10);		
				break;
			case 5:
				printf("Exiting program\n");
				break;
			default:
				printf("Invalid option, try again\n");
				fflush(stdin);
				break;
		}
	}while(option != 5);
    	return 0;
}

