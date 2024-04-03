// Son Nguyen - 103234103//
// COS10007 Assignment 1//
// Question 3//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//structure 
struct Train{
	int id;
	time_t schedule;
	struct Train* next;
};
//rng on train id 
void constructTrainID(struct Train* arr, int size){
	int i;
	for (i = 0; i < size; i++){
		arr[i].id = rand() % (200 - 100 + 1) + 100;
	}
}
// rng on train schelude (time)
void constructTrainSchedule(struct Train* arr, int size){
	int i;
	for (i = 0; i < size; i++){
		arr[i].schedule = time(NULL) + rand()%9999;
	}
}
// displayList to print out train details 
void displayTrainInfo(struct Train* arr, int size){
	printf("Train information:\n");
	printf("ID\t\t\t\tSchedule\n");
	int i;
	for (i = 0; i < size; i++){
		printf("%d\t\t\t%s\n", arr[i].id, ctime(&arr[i].schedule));

	}
}
// checking sche
void scheduleTrain(struct Train* arr, int size){
	int i, j;
	struct Train temp; 
	for (i = 0; i< size-1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j].schedule < arr[j+1].schedule)
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}	
		}
	}
}
// earliest arrival 
void departEarliestTrain(struct Train* arr, int *size){
	struct Train *head = NULL;
        int i;
        for (i = 0; i < *size; i++)
        {
                arr[i].next = head;
                head = &arr[i];
        }
// check if any train 
	if (head == NULL){
		printf("No trains available to depart");
	}
	printf("Train %d has departed from the station at %s",head->id, ctime(&head->schedule));
	head = head->next;
	*size -= 1;	
}
// latest arrival 
void departLastTrain(struct Train* arr, int *size){
	struct Train* head = &arr[0];
	struct Train* cur = head;
	int i;
	for (i = 1; i < *size; i++)
	{
		cur->next = &arr[i];
		cur = cur->next;
	}
	cur->next = NULL;
	// check latest time departed
	printf("Train %d has departed from the station. Its scheduled time is %s",head->id, ctime(&head->schedule));
	head = head->next;
	for (i = 0; i < *size-1; i++)
	{
		arr[i] = arr[i+1];
	}
	*size -= 1;
}
// menu to print 
int main(){
	srand(time(NULL));
	int size = 10;
	struct Train TrainArr[size];
	constructTrainID(TrainArr, size);
	constructTrainSchedule(TrainArr, size);
	displayTrainInfo(TrainArr, size);	
	scheduleTrain(TrainArr, size);
	departEarliestTrain(TrainArr, &size);
	departLastTrain(TrainArr,&size);
	return 0;
}
