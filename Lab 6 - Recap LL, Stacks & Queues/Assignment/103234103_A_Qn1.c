//Son Nguyen - 103234103
// Assignment 1 - COS10007//
// Question 1//
#include <stdio.h>
#include <stdlib.h>

struct studentname {
    char letter;
    struct studentname *next;
};
typedef struct studentname STUDENTName;
typedef STUDENTName *STUDENTNamePtr;

void displayList(STUDENTNamePtr currentPtr);

int main() {
    // Initialize pointer
    STUDENTNamePtr startPtr = NULL;

    // 1st letter of last name N
    STUDENTNamePtr newPtr = (STUDENTNamePtr) malloc(sizeof(STUDENTName));
    newPtr->letter = 'N';
    newPtr->next = NULL;
    startPtr = newPtr;

    // 2nd letter of last name G
    newPtr = (STUDENTNamePtr) malloc(sizeof(STUDENTName));
    newPtr->letter = 'G';
    newPtr->next = NULL;
    if (newPtr->letter < startPtr->letter) {
        newPtr->next = startPtr;
        startPtr = newPtr;
    } else {
        startPtr->next = newPtr;
    }

    // 3rd letter of last name U
    newPtr = (STUDENTNamePtr) malloc(sizeof(STUDENTName));
    newPtr->letter = 'U';
    newPtr->next = NULL;
    if (newPtr->letter < startPtr->letter) {
        newPtr->next = startPtr;
        startPtr = newPtr;
    } else {
        STUDENTNamePtr prevPtr = startPtr;
        STUDENTNamePtr currentPtr = startPtr->next;
        while (currentPtr != NULL && newPtr->letter > currentPtr->letter) {
            prevPtr = currentPtr;
            currentPtr = currentPtr->next;
        }
        prevPtr->next = newPtr;
        newPtr->next = currentPtr;
    }

    // 4th letter of last name Y
    newPtr = (STUDENTNamePtr) malloc(sizeof(STUDENTName));
    newPtr->letter = 'Y';
    newPtr->next = NULL;
    if (newPtr->letter < startPtr->letter) {
        newPtr->next = startPtr;
        startPtr = newPtr;
    } else {
        STUDENTNamePtr prevPtr = startPtr;
        STUDENTNamePtr currentPtr = startPtr->next;
        while (currentPtr != NULL && newPtr->letter > currentPtr->letter) {
            prevPtr = currentPtr;
            currentPtr = currentPtr->next;
        }
        prevPtr->next = newPtr;
        newPtr->next = currentPtr;
    }
    // 5th letter of last name E
    newPtr = (STUDENTNamePtr) malloc(sizeof(STUDENTName));
    newPtr->letter = 'E';
    newPtr->next = NULL;
    if (newPtr->letter < startPtr->letter) {
        newPtr->next = startPtr;
        startPtr = newPtr;
    } else {
        STUDENTNamePtr prevPtr = startPtr;
        STUDENTNamePtr currentPtr = startPtr->next;
        while (currentPtr != NULL && newPtr->letter > currentPtr->letter) {
            prevPtr = currentPtr;
            currentPtr = currentPtr->next;
        }
        prevPtr->next = newPtr;
        newPtr->next = currentPtr;
    }

    // Print the list
    displayList(startPtr);

    // Free the memory
    while (startPtr != NULL) {
        STUDENTNamePtr tempPtr = startPtr;
        startPtr = startPtr->next;
        free(tempPtr);
    }

    return 0;
}

void displayList(STUDENTNamePtr currentPtr) 
{
    printf("Last Name\n");
    while (currentPtr != NULL) {
        printf("%c\n ", currentPtr->letter);
        currentPtr=currentPtr->next;
}
}
