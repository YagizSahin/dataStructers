#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};
struct Node* head;
struct Node* getNewNode(int x) {
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void InsertAtHead(int x) {
	struct Node* newNode = getNewNode(x);
	if (head==NULL)
	{
		head = newNode;
		return;
	}
	else
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}
void Print() {
	struct Node* temp = head;
	printf("Forward: ");
	while (temp!=NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void reversePrint() {
	struct Node* temp = head;
	if (temp==NULL)
	{
		return;
	}
	else
	{
		while (temp->next!=NULL)
		{
			temp = temp->next;
		}
		printf("reverse: ");
		while (temp!=NULL)
		{
			printf("%d", temp->data);
			temp = temp->prev;
		}
		printf("\n");
	}
}
void main() {
	head = NULL;
	InsertAtHead(6); Print(); reversePrint();
	InsertAtHead(7); Print(); reversePrint();
	
}