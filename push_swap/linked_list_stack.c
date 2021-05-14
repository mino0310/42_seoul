#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int element;

typedef struct StackNode {
	element data;
	struct StackNode *next;
} StackNode;

typedef struct {
	StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s)
{
	s->top = NULL;
}

int is_empty(LinkedStackType *s)
{
	return (s->top == NULL);
}

void push_a(LinkedStackType *a, LinkedStackType *b)
{
	if (!(*b->top)) {
		write("Error\n");
		exit(0);
	}
	if (!(*a->top)) {
		write("Error\n");
		exit(0);
	}
	if (*a->top) {
		StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
		temp->data = b->top->data;
		temp->next = a->top;
		a->top = temp; 
	}
	b->top = b->top->next;
}

void push_b(LinkedStackType *a, LinkedStackType *b) {
	push_a(b, a);
}

void print_stack(LinkedStackType *s)
{
	for (StackNode *p = s->top; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL  \n");
}

element pop(LinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어 있음 \n");
		exit(1);
	}
	else {
		StackNode *temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

element peek(LinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어 있음 \n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}

int main(void)
{
	LinkedStackType a, b;
	init(&a);
	init(&b);
	
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	
	return 0;
}
