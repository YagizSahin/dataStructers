#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
void ekle(struct Node* head, int x) {
	struct Node* iter = head;
	if (head==NULL)
	{
		struct Node* temp = malloc(sizeof(struct Node));
		temp->data = x;
		head = temp;
		head->next = head;
	}
	while (iter->next!=head)
	{
		iter = iter->next;
	}
	iter->next= malloc(sizeof(struct Node));
	iter->next->data = x;
	iter->next->next = head;

}
struct Node* siraliEkle(struct Node* head, int x) {
	if (head==NULL)
	{
		head = malloc(sizeof(struct Node));
		head->next = head;
		head->data = x;
		return head;
	}
	if (head->data>x)
	{
		struct Node* temp = malloc(sizeof(struct Node));
		temp->next = head;
		temp->data = x;
		struct Node* iter = head;
		while (iter->next != head)
		{
			iter = iter->next;
		}
		iter->next = temp;
		return temp;
		
	}
	else 
	{
		struct Node* iter = head;
		while (iter->next!=head&&iter->next->data <x)
		{
			iter = iter->next;
		}
		struct Node* temp = malloc(sizeof(struct Node));
		temp->next = iter->next;
		iter->next = temp;
		temp->data = x;
		return head;
	}
	
	
}
struct Node* sil(struct Node* head, int x) {
	struct Node* temp;
	struct Node* iter = head;
	if (head->data==x)
	{
		while (iter->next != head)
		{
			iter = iter->next;
		}
		iter->next = head->next;
		free(head);
		return iter->next;
	}
	while (iter->next!=head&&iter->next->data != x)
	{
		iter = iter->next;
	}
	if (iter->next==head)
	{
		printf("sayi bulunamadi\n");
		return head;
	}
	temp = iter->next;
	iter->next= iter->next->next;
	free(temp);
	return head;
	
}

void yazdir(struct Node* head) {
	struct Node* iter = head;
	printf("%d--->", iter->data);
	iter = iter->next;
	while (iter!=head)
	{
		printf("%d--->", iter->data);
		iter = iter->next;
	}
	printf("\n");
}
int main() {
	struct Node* head;
	head = NULL;
	head= siraliEkle(head, 400);
	head=siraliEkle(head, 40);
	head=siraliEkle(head, 4);
	head = siraliEkle(head, 450);
	head = siraliEkle(head, 50);
	yazdir(head);
	head=sil(head,50);
	yazdir(head);
	head = sil(head, 999);
	yazdir(head);
	head = sil(head, 4);
	yazdir(head);
	head = sil(head, 450);
	yazdir(head);

}