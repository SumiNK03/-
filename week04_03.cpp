
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode { // ��� Ÿ���� ����ü�� �����Ѵ�.
	element data;
	struct ListNode* link;
} ListNode;

// �� �տ� ��� ����
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
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
	if (head == NULL) { // ���� ����Ʈ�� ����ִٸ�
		head = p;
		return head;
	}
	//�װ� �ƴ϶�� ������ ������ ��带 ã��
	while (last_node->link != NULL) {
		last_node = last_node->link;
	}
	last_node->link = p;
	return head;
}


// �� ���� ��带 ����
ListNode* remove_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* remove(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

ListNode* remove_last(ListNode* head) { // �� ���� ��带 ����
	if (head == NULL)
		return NULL;
	if (head->link == NULL) { // ����Ʈ�� ��尡 �ϳ��� �ִ� ���
		free(head);
		return NULL;
	}
	ListNode* current = head; // ù ��° ������ ����
	ListNode* pre = NULL; // ������ ����� �� ���
	//������ ���, ������ �ι�° ��带 ã��
	while (current->link != NULL) {
		pre = current;
		current = current->link;
	}
	pre->link = NULL;
	free(current);// ������ ��� �޸� ����
	return head; // ����� ����Ʈ�� ��� ��ȯ
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
