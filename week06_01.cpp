
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 overflow\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// 삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 underflow\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// 가장 큰 값을 return 하는 함수
element max(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 underfolw\n");
		exit(1);
	}
	int max = s->data[0];
	for (int i = 1; i <= s->top; i++) {
		if (s->data[i] > max)
			max = s->data[i];
	}

	return max;
}

// 가장 작은 값을 return 하는 함수
element min(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 underfolw\n");
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
	//printf("테스트 케이스 수 입력 : ");
	scanf("%d", &testCase);
	for (int test = 0; test < testCase; test++) {
		init_stack(&s);
		int n = 0;
		//printf("질의 수 입력 : ");
		scanf("%d", &n);

		int i = 0;
		while (i < n) {
			int a = 0;
			int x = 0;
			//printf("1개 또는 2개의 인자 입력 : ");
			scanf("%d", &a);
			if (a == 1)
				scanf("%d", &x);

			if (a == 1) {
				push(&s, x);
				//printf("최솟값 최댓값 : %d %d\n", min(&s), max(&s));
				printf("%d %d\n", min(&s), max(&s));
			}
			else if (a == 2) {
				pop(&s);
			}
			else {
				printf("첫번째 인자로 1 또는 2를 입력해야 합니다.\n");
				continue;
			}
			i++;
		}
	}
	return 0;
}
