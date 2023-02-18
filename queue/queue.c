#include<stdio.h>
#define MAX_SIZE 40
int IsEmptyqueue();
int Isfullqueue();
int Frontqueue();
void dequeue();
void printstackqueue();
void enqueue(int);
int rear = -1;
int front = -1;
int arrq[MAX_SIZE];


void enqueue(int sayi) {
	if (rear == MAX_SIZE - 1) {
		printf("queue is full");
	}
	else {
		if (front == -1) {
			front = 0;


		}
		rear = rear + 1;
		arrq[rear] = sayi;
		printstackqueue();
	}
}
void dequeue() {
	if (front == -1 || front > rear) {
		printf("queue is empty");
		front = -1;
		rear = -1;
	}
	else {
		front = front + 1;
		printstackqueue();
	}
}
void printstackqueue() {
	int i;
	for (i = front; i <= rear; i++) {
		printf("%d ", arrq[i]);
	}
	printf("\n ");
}
int main() {
	enqueue(12);
	enqueue(13);
	enqueue(14);
	enqueue(15);
	dequeue();
	printstackqueue();
	return 1;
}