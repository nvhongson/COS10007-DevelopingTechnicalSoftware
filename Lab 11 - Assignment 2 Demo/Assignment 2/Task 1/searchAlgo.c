#include "structDef.h"
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include <string.h>

int LinearSearch(struct myStruct* structArr,int arr_size, char* searchString, int index){
	if (index == arr_size){
		return -1;
	}
	if (strcmp(structArr[index].strVal, searchString) == 0){
		printf("%s found\n", searchString);
		return index;
	}
	return LinearSearch(structArr, arr_size, searchString, index+1);
	

}
int BinarySearch(struct myStruct* structArr, char* searchString, int low, int high) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (strcmp(structArr[mid].strVal, searchString) == 0) {
	printf("%s found\n", searchString);
        return mid;
    }
    if (strcmp(structArr[mid].strVal, searchString) > 0) {
        return BinarySearch(structArr, searchString, low, mid - 1);
    }
    return BinarySearch(structArr, searchString, mid + 1, high);
}
