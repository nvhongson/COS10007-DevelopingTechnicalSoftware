#include "structDef.h"
#include "helpers.h"
#include <stdlib.h>
#include <stdio.h>

void BubbleSort(struct myStruct* structArr, int arrSize, char sortOption){
	int i, j;
	struct myStruct temp;
	for (i = 0; i < arrSize-1; i++)
	{
		for (j = 0; j < arrSize-i-1; j++)
		{
			if (sortOption == 'D'){
				if (compareStrings(structArr[j].strVal, structArr[j+1].strVal) == 1){
					temp = structArr[j];
					structArr[j] = structArr[j+1];
					structArr[j+1] = temp;	
				}
			}
			else if (sortOption == 'A'){
				if (compareStrings(structArr[j].strVal, structArr[j+1].strVal) == -1){
					temp = structArr[j];
					structArr[j] = structArr[j+1];
					structArr[j+1] = temp;
				}
			}
		}
	}
}
void InsertionSort(struct myStruct* structArr, int arrSize, char sortOption){

	int i, j;
	struct myStruct temp;
	for (i = 1; i < arrSize; i++)
	{
		temp = structArr[i];
		j = i-1;
		if (sortOption == 'D') {
            		while (j >= 0 && compareStrings(structArr[j].strVal, temp.strVal) == 1){
                		structArr[j+1] = structArr[j];
                		j--;
            		}
        	} 
		else if (sortOption == 'A') {
            		while (j >= 0 && compareStrings(structArr[j].strVal, temp.strVal) == -1) {
                		structArr[j+1] = structArr[j];
                		j--;
            		}
        	}
        	structArr[j+1] = temp;
	}
}


