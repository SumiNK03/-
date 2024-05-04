
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode { // 노드 타입을 구조체로 정의한다.
	element data;
	struct ListNode* link;
} ListNode;

// 맨 앞에 노드 삽입
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* insert_last(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	ListNode* last_node = head;
	p->data = value;
	p->link = NULL;
	if (head == NULL) { // 만약 리스트가 비어있다면
		head = p;
		return head;
	}
	//그게 아니라면 현재의 마지막 노드를 찾음
	while (last_node->link != NULL) {
		last_node = last_node->link;
	}
	last_node->link = p;
	return head;
}


// 맨 앞의 노드를 삭제
ListNode* remove_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// pre가 가리키는 노드의 다음 노드를 삭제한다.
ListNode* remove(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

ListNode* remove_last(ListNode* head) { // 맨 끝의 노드를 삭제
	if (head == NULL)
		return NULL;
	if (head->link == NULL) { // 리스트에 노드가 하나만 있는 경우
		free(head);
		return NULL;
	}
	ListNode* current = head; // 첫 번째 노드부터 시작
	ListNode* pre = NULL; // 마지막 노드의 전 노드
	//마지막 노드, 끝에서 두번째 노드를 찾음
	while (current->link != NULL) {
		pre = current;
		current = current->link;
	}
	pre->link = NULL;
	free(current);// 마지막 노드 메모리 해제
	return head; // 변경된 리스트의 헤드 반환
}

// return h1 + h2
ListNode* connect(ListNode* h1, ListNode* h2) {
	ListNode* i = h1;
	for (; i->link != NULL; i = i->link);
	i->link = h2;
	return h1;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}


int main(void) {
	ListNode* head1 = NULL;
	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);

	ListNode* head2 = NULL;
	head2 = insert_first(head2, 40);
	head2 = insert_first(head2, 50);
	print_list(head2);

	head1 = connect(head1, head2);
	print_list(head1);

	return 0;
}
