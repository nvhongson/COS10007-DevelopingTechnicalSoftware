#include "structDef.h"
#include <stdlib.h>
#include <stdio.h>

struct Node{
	struct myStruct data;
	struct Node *next;
};
void menu(){
        printf("Please select an option from below:\n");
        printf("1: Display the details of the array\n");
        printf("2: Sort the array\n");
        printf("3: Search for a string element\n");
        printf("4: Insert array elements into a List\n");
        printf("5: Exit the program\n\n");
}
void printArray(struct myStruct* structArr, int arr_size){
        int i;
        printf("\n");
        for (i  = 0; i < arr_size; i++)
        {
                printf("%-10s%-7d%-7d%-7.2lf\n", structArr[i].strVal, structArr[i].int1Val, structArr[i].int2Val, structArr[i].dblVal);
        }

}
int compareStrings(char* a, char* b){
	int i = 0;
	while (a[i]  != '\0' || b[i] != '\0'){
		if (a[i] < b[i]){
			return 1;
		}
		else if (a[i] > b[i]){
			return -1;
		}
		i++;
	}
	return 0;
}
void printArraytoFile(struct myStruct* structArr, int arr_size){
	int i;
	FILE *fptr = fopen("output.txt", "w");
	for (i = 0; i < arr_size; i++)
	{
		fprintf(fptr, "%-10s%-7d%-7d%-7.2lf\n", structArr[i].strVal, structArr[i].int1Val, structArr[i].int2Val, structArr[i].dblVal);
	}
}
void convertArraytoList(struct myStruct* structArr, int arr_size){
	int i;
	struct Node* head = NULL;
	head = malloc(sizeof(struct Node));
	head->data = structArr[0];
	head->next = NULL;
	struct Node* node = NULL;
	node = head;
	for (i = 1; i < arr_size; i++)
	{
		node->next = malloc(sizeof(struct Node));
		node = node->next;
		node->data = structArr[i];
		node->next = NULL;
	}
	struct Node* cur = head;
	printf("The list element is as follows: \n");
	while (cur){
		printf("%-10s%-7d%-7d%-7.2lf\n", cur->data.strVal, cur->data.int1Val, cur->data.int2Val, cur->data.dblVal);
		cur = cur->next;
	}
}
