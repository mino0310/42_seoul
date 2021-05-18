#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gnl/get_next_line.h"

// typedef int element;

// typedef struct StackNode {
// 	element data;
// 	struct StackNode *next;
// } StackNode;

// typedef struct {
// 	StackNode *top;
// } LinkedStackType;

// void init(LinkedStackType *s)
// {
// 	s->top = NULL;
// }

// int is_empty(LinkedStackType *s)
// {
// 	return (s->top == NULL);
// }

// void push_a(LinkedStackType *a, LinkedStackType *b)
// {
// 	if (!(*b->top)) {
// 		write("Error\n");
// 		exit(0);
// 	}
// 	if (!(*a->top)) {
// 		write("Error\n");
// 		exit(0);
// 	}
// 	if (*a->top) {
// 		StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
// 		temp->data = b->top->data;
// 		temp->next = a->top;
// 		a->top = temp; 
// 	}
// 	b->top = b->top->next;
// }

// void push_b(LinkedStackType *a, LinkedStackType *b) {
// 	push_a(b, a);
// }

// void print_stack(LinkedStackType *s)
// {
// 	for (StackNode *p = s->top; p != NULL; p = p->next)
// 	{
// 		printf("%d->", p->data);
// 	}
// 	printf("NULL  \n");
// }

// element pop(LinkedStackType *s)
// {
// 	if (is_empty(s)) {
// 		fprintf(stderr, "스택이 비어 있음 \n");
// 		exit(1);
// 	}
// 	else {
// 		StackNode *temp = s->top;
// 		int data = temp->data;
// 		s->top = s->top->next;
// 		free(temp);
// 		return data;
// 	}
// }

// element peek(LinkedStackType *s)
// {
// 	if (is_empty(s)) {
// 		fprintf(stderr, "스택이 비어 있음 \n");
// 		exit(1);
// 	}
// 	else {
// 		return s->top->data;
// 	}
// }


int arr[500];
int top = -1;
void push(int a) {
	arr[++top] = a;
}
void pop() {
	top--;
}
int peek() {
	return arr[top];
}
int empty() {
	return (top == -1);
}
int size() {
	return (top + 1);
}
void print_all()
{
	int i = 0;
	while (size()) {
		write(1, &arr[i], 4);
	}
}

int main(int argc, char **argv)
{
	int input[500];

	if (argc < 2) {
		write(1, "input more argument\n", 20);
	}

	int i = 1;
	while (i < argc) {
		scanf("%d", &input[i]);
	}
	




	// LinkedStackType a, b;
	// char *
	// //init(&a);
	// //init(&b);
	// while ()
	
	
	

	return 0;
}
