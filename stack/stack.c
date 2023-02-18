#include<stdio.h>
#define MAX_STACK_SIZE 101
int top = -1;
int stack[MAX_STACK_SIZE];

int Push(int n);
int Pop();
int Top();
void isEmpty();
void isFull();
void print();

void main() {
	Push(2); print();
	Push(5); print();
	Pop(); print();
	isEmpty();
	isFull();
}

int Push(int n) {
	if (top == MAX_STACK_SIZE)
	{
		printf("stack overflow");
	}
	else
	{
		stack[++top] = n;
	}
}
int Pop() {
	if (top == -1)
	{
		printf("stack is empty");
	}
	else
	{
		top--;
	}
}
int Top() {
	if (top == -1)
	{
		printf("stack is empty");
	}
	else
	{
		return stack[top];
	}
}
void isEmpty() {
	if (top == -1)
	{
		printf("stack is empty");
	}
}
void isFull() {
	if (top == MAX_STACK_SIZE)
	{
		printf("stack is full");
	}
}
void print() {
	printf("stack: ");
	for (int i = 0; i <= top; i++)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}