#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Data Struct 
struct Node{
    char TVName[50];
    struct Node* next;
};
typedef struct{
    struct Node* head;
    struct Node* tail;
} Queue;
//set pointer to NULL
void init(Queue* q){
    q->head = NULL;
    q->tail = NULL;
}
//Queue Data Struct
void enqueue(Queue *q, char* data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->TVName, data);
    new_node->next = NULL;
    if (q->head == NULL){
        q->head = new_node;
        q->tail = new_node;
    }
    else{
        q->tail->next = new_node;
        q->tail = new_node;
    }

}
// Dequeue Operation
char* dequeue(Queue *q){
    if (q->head == NULL){
        return NULL;
    }
    char* data = malloc(sizeof(char) * (strlen(q->head->TVName) + 1));
    strcpy(data, q->head->TVName);
    struct Node* tempNode = q->head;
    q->head = q->head->next;
    free(tempNode);
    if (q->head == NULL){
        q->tail = NULL;
    }

    return data;
}
//Data Struct for Array
typedef struct{
    char* TVStack[100];
    int top;
} Stack;

void initStack(Stack* s){
    s->top = -1;
}
void push(Stack* s, char* TVName){
    if (s->top != 99){
        s->TVStack[++(s->top)] = strdup(TVName);
    }    
}
char* pop(Stack* s){
    if (s-> top != -1){
        return s->TVStack[(s->top)--];
    }
    return NULL;
}
char* top(Stack* s){
    if (s->top == -1){
        return "None\n";
    }
    else{
        return s->TVStack[s->top];
    }
}
// read file 
void readTVs(struct Node** headNode) {
    FILE *fptr;
    if ((fptr = fopen("TVs.txt", "r")) == NULL) {  
        printf("Invalid file, exiting program.");
        exit(1);
    }
    struct Node* node;
    int ID;
    int isEmpty = 1;
    while (!feof(fptr)) {
        node = (struct Node*)malloc(sizeof(struct Node));
        if (fscanf(fptr, "%d", &(ID)) == EOF) { 
            break;
        }
        isEmpty = 0;
        fscanf(fptr, " %[^\n]s", node->TVName);
        struct Node* prev = NULL;
        struct Node* cur = *headNode;
        while (cur != NULL && strcasecmp(cur->TVName, node->TVName) < 0) {
            prev = cur;
            cur = cur->next;
        }
        if (prev == NULL) {
            node->next = *headNode;
            *headNode = node;
        }
        else {
            prev->next = node;
            node->next = cur;
        }
    }
    fclose(fptr);
    if (isEmpty) { 
        printf("File is empty, exiting program.");
        exit(1);
    }
}
// Menu
int menu(){
    int option;
    printf("Select from the following menu options:\n");
    printf("1: Display the current stock of TVs\n");
    printf("2: Add a new TV to stock\n");
    printf("3: Display next order information\n");
    printf("4: Display all orders\n");
    printf("5: Add order to queue\n");
    printf("6: Process the next order\n");
    printf("7: Cancel last order\n");
    printf("8: Display info of last order\n");
    printf("9: Update TV file\n");
    printf("10: Quit program\n\n");
    int errorCheck;
    errorCheck = scanf("%d", &option);
    while (errorCheck != 1){
        printf("Invalid input, try again\n");
        while (getchar() != '\n'){}
        errorCheck = scanf("%d", &option);
    }
    return option;


}
// Insert TV into List 
void insertTVintoList(struct Node** headNode, char* TVName){
        struct Node* prev = NULL;
        struct Node* cur = *headNode;
        while (cur != NULL && strcasecmp(cur->TVName, TVName) < 0){
            prev = cur;
            cur = cur->next;
        }
        struct Node* newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        strcpy(newNode->TVName, TVName);
        if (prev == NULL){
            newNode->next = *headNode;
            *headNode = newNode;
        }
        else{
            prev->next = newNode;
            newNode->next = cur;
        }
}
//Display TV List
void displayTVList(struct Node* node){
    printf("Current Stock of TVs are listed below: \n\n");
    struct Node* cur = node;
    while (cur != NULL){
        printf("%s\n", cur->TVName);
        cur = cur->next;
    }
}
// Display Next Order 
void displayNextOrder(Queue *q){
    if (q->head == NULL){
        printf("The order-list is currently empty.\n");
    }
    else{
        printf("The next order in the list is %s\n", q->head->TVName);
    }
}
// Display All Order
void displayAllOrders(Queue *q){
    if (q->head == NULL){
        printf("The order-list is currently empty.\n");
    }
    else{
        struct Node* node = q->head;
        printf("Orders to be executed:\n");
        while (node != NULL){
            printf("%s\n", node->TVName);
            node = node->next;
        }
    }
}
// Dequeue next TV from queue
void ProcessNextOrder(Queue *q, Stack* s, struct Node** headNode){
    char *TVName = dequeue(q);
    if (TVName != NULL){
        struct Node* cur = *headNode;
        struct Node* prev = NULL;
        while (cur != NULL && strcasecmp(cur->TVName, TVName) != 0){
            prev = cur;
            cur = cur->next;
        }
        if (cur != NULL){
            if (prev == NULL){
                *headNode = cur->next;
            }
            else{
                prev->next = cur->next;
            }
            push(s, cur->TVName);
            free(cur);
            printf("Order successfully processed!\n");
        }
        else{
            printf("TV not found in List\n");
        }
    }
    else{
        printf("There are no orders to process.\n");
    }
    
}
// Update file 
void updateTVFile(struct Node* headNode){
    FILE *fptr;
    if ((fptr = fopen("TVs.txt", "w")) == NULL){  
        printf("Invalid file, exiting program.");
        exit(1);
    }
    if (headNode == NULL){
        printf("No TV availiable currently.");
        return;
    }
    struct Node* cur = headNode;
    while (cur->next != NULL){
        fprintf(fptr, "%s\n", cur->TVName);
        cur = cur->next;
    }
    fprintf(fptr, "%s", cur->TVName);
    fclose(fptr);
}
// Main Function
int main(){
    struct Node *head = NULL;
    Queue OrderQueue;
    Stack PrevOrders;
    initStack(&PrevOrders);
    init(&OrderQueue);
    readTVs(&head);
    int option = menu();
    while (option != 10){
        switch(option){
            case 1:
                displayTVList(head);
                break;
            case 2:
                printf("Input the name of the TV: ");
                char TVName[50];
                while (getchar() != '\n') {}
                fgets(TVName, 50, stdin);
                TVName[strcspn(TVName, "\n")] = '\0';
                insertTVintoList(&head, TVName);
                printf("TV successfully added to the list!");
                break;
            case 3:
                displayNextOrder(&OrderQueue);
                break;
            case 4:
                displayAllOrders(&OrderQueue);
                break;
            case 5:
                printf("Enter the name of the TV you would like to purchase: ");
                while (getchar() != '\n'){}
                fgets(TVName, 50, stdin);
                TVName[strcspn(TVName, "\n")] = '\0';
                enqueue(&OrderQueue, TVName);
                printf("Order successfully placed!\n");
                break;
            case 6:
                ProcessNextOrder(&OrderQueue, &PrevOrders, &head);
                break;
            case 7:
                char* prevOrderName = pop(&PrevOrders);
                if (prevOrderName != NULL){
                    insertTVintoList(&head, prevOrderName);
                    printf("Order cancelled successfully\n");
                }
                else{
                    printf("There are no previous orders\n");
                }
                break;
            case 8:
                printf("The previously processed order is %s\n", top(&PrevOrders));
                break;
            case 9:
                updateTVFile(head);
                printf("TVs.txt updated successfully!\n");
                break;
            default:
                printf("Incorrect option. Try again.\n");
                break;
        }
        printf("\n");
        option = menu();
    }
    printf("Exiting program.\n");
    return 0;
}