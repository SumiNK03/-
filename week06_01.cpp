
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// ���� �Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� overflow\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// ���� �Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� underflow\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// ���� ū ���� return �ϴ� �Լ�
element max(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� underfolw\n");
		exit(1);
	}
	int max = s->data[0];
	for (int i = 1; i <= s->top; i++) {
		if (s->data[i] > max)
			max = s->data[i];
	}

	return max;
}

// ���� ���� ���� return �ϴ� �Լ�
element min(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� underfolw\n");
		exit(1);
	}
	int min = s->data[0];
	for (int i = 1; i <= s->top; i++) {
		if (s->data[i] < min)
			min = s->data[i];
	}

	return min;
}

int main() {
	StackType s;
	init_stack(&s);
	
	int testCase = 0;
	//printf("�׽�Ʈ ���̽� �� �Է� : ");
	scanf("%d", &testCase);
	for (int test = 0; test < testCase; test++) {
		init_stack(&s);
		int n = 0;
		//printf("���� �� �Է� : ");
		scanf("%d", &n);

		int i = 0;
		while (i < n) {
			int a = 0;
			int x = 0;
			//printf("1�� �Ǵ� 2���� ���� �Է� : ");
			scanf("%d", &a);
			if (a == 1)
				scanf("%d", &x);

			if (a == 1) {
				push(&s, x);
				//printf("�ּڰ� �ִ� : %d %d\n", min(&s), max(&s));
				printf("%d %d\n", min(&s), max(&s));
			}
			else if (a == 2) {
				pop(&s);
			}
			else {
				printf("ù��° ���ڷ� 1 �Ǵ� 2�� �Է��ؾ� �մϴ�.\n");
				continue;
			}
			i++;
		}
	}
	return 0;
}
