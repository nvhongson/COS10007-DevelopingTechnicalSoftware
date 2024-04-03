#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct personTag{
    char name[20];
    int age;
};

struct officialTag{
    int deptId;
    char cmpName[20];
    double salary;
};

struct employeeTag{
    struct personTag personalInfo;
    struct officialTag officialInfo;
    struct employeeTag *next;
};

struct Node{
    struct employeeTag data;
    struct Node *next;
};

void readFile(struct Node** headNode){
    FILE * fptr;
    if ((fptr = fopen("employee.txt", "r")) == NULL){
        printf("file does not exist. Exiting the program.");
        exit(1);
    }

    char firstLine[100];
    fgets(firstLine, 100, fptr);

    struct Node* node = NULL;
    node = (struct Node*)malloc(sizeof(struct Node));

    while(fscanf(fptr, "%s    %d      %d      %s      %lf", node->data.personalInfo.name, &node->data.personalInfo.age, &node->data.officialInfo.deptId, node->data.officialInfo.cmpName, &node->data.officialInfo.salary) == 5){
	struct Node* prev = NULL;
        struct Node* cur = *headNode;

        while(cur != NULL && strcmp(cur->data.personalInfo.name, node->data.personalInfo.name) < 0){
            prev = cur;
            cur = cur->next;
        }

        if(prev == NULL){
            node->next = *headNode;
            *headNode = node;
        }
        else{
            prev->next = node;
	    node->next = cur;
        }
	node = (struct Node*)malloc(sizeof(struct Node));
    }
    fclose(fptr);
}

void displayEmployees(struct Node* node){
     printf("Employee Information:\nName\t\tAge\t\tID\t\tCompany\t\tSalary\n");	
     while (node != NULL){
	printf("%s\t\t%d\t\t%d\t\t%s\t\t%.2f\n", node->data.personalInfo.name, node->data.personalInfo.age, node->data.officialInfo.deptId, node->data.officialInfo.cmpName, node->data.officialInfo.salary);
	node = node->next;
     }
    
}

int Menu(){
    printf("\n\nPlease select one of the following menu options:\n");
    printf("(1) Display employee's details\n"
	   "(2) Search for an employee's salary\n"
	   "(3) Find the details of employee with the largest salary\n"
	   "(4) Find the details of all employees having salary less than 5000\n"
	   "(5) Find the average salary of a company\n"
	   "(6) Add new employee to the record\n"
	   "(7) Quit program\n");
    int option;
    int errorChecking;
    errorChecking = scanf("%d", &option);
    while(errorChecking != 1){
	printf("invalid input. Please enter a number\n");
	while (getchar() != '\n'){}
	errorChecking = scanf("%d", &option);
    }
    return option;
}

void searchEmployee(struct Node* node, char *name){
    int Found = 0;
    while (node != NULL){
	if (strcmp(node->data.personalInfo.name, name) == 0){
		if (Found == 0){
			printf("\nName\t\tAge\t\tID\t\tCompany\t\tSalary\n");
		}
		printf("%s\t\t%d\t\t%d\t\t%s\t\t%.2f\n", node->data.personalInfo.name, node->data.personalInfo.age, node->data.officialInfo.deptId, node->data.officialInfo.cmpName, node->data.officialInfo.salary);
	   	Found = 1;
	}
	node = node->next;
    }
    if (Found == 0){
	printf("Employee not found\n");
    }
}

void findMaximum(struct Node* node){
	int maxSal = 0;
	struct Node* maxSalNode = (struct Node*)malloc(sizeof(struct Node));
	while (node != NULL){
		if (node->data.officialInfo.salary > maxSal){
			maxSal = node->data.officialInfo.salary;
			maxSalNode = node;
		}
		node = node->next;
	}
	node = maxSalNode;
	printf("\nName\t\tAge\t\tID\t\tCompany\t\tSalary\n");
	printf("%s\t\t%d\t\t%d\t\t%s\t\t%.2f\n", node->data.personalInfo.name, node->data.personalInfo.age, node->data.officialInfo.deptId, node->data.officialInfo.cmpName, node->data.officialInfo.salary);
}

void lowerSalary(struct Node* node){
	printf("Details of all employees with salary less than 5000 are listed below:\n");
	printf("Name\t\tAge\t\tID\t\tCompany\t\tSalary\n");
	while (node != NULL){
		if (node->data.officialInfo.salary < 5000){
			printf("%s\t\t%d\t\t%d\t\t%s\t\t%.2f\n", node->data.personalInfo.name, node->data.personalInfo.age, node->data.officialInfo.deptId, node->data.officialInfo.cmpName, node->data.officialInfo.salary);
		}
		node = node->next;
	}
}

void averageSalary(struct Node* node, char* compN){
	double total = 0.0;
	int count = 0;
	while (node != NULL){
		if (strcmp(node->data.officialInfo.cmpName,compN) == 0){
			count += 1;
			total += node->data.officialInfo.salary;	
		}
		node = node->next; 
	}
	if (count == 0){
		printf("Company not found in the database\n");
	}
	else{
		printf("The average salary of all employees of %s is %.2f", compN, total/count);
	}
}

void updateFile(){
	FILE *fptr;
	char name[20], cmpName[20];
	int age, deptId;
	double salary;

    	if ((fptr = fopen("employee.txt", "a")) == NULL){
        	printf("file does not exist. Exiting the program.");
        	exit(1);
    	}
	printf("Enter the name of the employee: ");
	scanf("%s", name);
	printf("Enter the age of the employee: ");
	scanf("%d", &age);
	printf("Enter the department ID of the employee: ");
	scanf("%d", &deptId);
	printf("Enter the name of the company the employee works at: ");
	scanf("%s", cmpName);
	printf("Enter the salary of the employee: ");
	scanf("%lf", &salary);
	fprintf(fptr, "%s	%d	%d	%s	%.2f\n", name, age, deptId, cmpName, salary);
	fclose(fptr);
}
void emptyList(struct Node** node){
	struct Node* cur = *node;
	struct Node* nex;
	while (cur != NULL){
		nex = cur->next;
		free(cur);
		cur = nex;
	}
	*node = NULL;
}
int main(){
    printf("Welcome to the Employee Details Database Menu!\n");
    struct Node* head = NULL;
    readFile(&head);
    int op = Menu();
    while (op != 7){
    	switch(op){
		case 1:
			displayEmployees(head);
			break;
		case 2:
			printf("Input the name of the employee you wish to find:\n");
			char Name[20];
			scanf("%s", Name);
			searchEmployee(head, Name);
			break;
		case 3:
			findMaximum(head);	
			break;
		case 4:
			lowerSalary(head);
			break;
		case 5:	
			printf("Input the name of the company you wish to look up:\n");
			char companyName[20];
			scanf("%s", companyName);
			averageSalary(head, companyName);
			break;
		case 6:
			updateFile();
			emptyList(&head);
			readFile(&head);
			displayEmployees(head);
			break;
		default:
			printf("Incorrect option, try again\n");
			break;
	} 
    	op = Menu();
	printf("\n");
    } 
    printf("Goodbye!\n");
    return 0;
}

