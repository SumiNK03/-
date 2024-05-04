
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode { // ��� Ÿ���� ����ü�� �����Ѵ�.
	element data;
	struct ListNode* link;
} ListNode;

// �� �տ� ��� ����
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	strcpy(p->data, value);
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	strcpy(p->data, value);
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* insert_last(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	ListNode* last_node = head;
	strcpy(p->data, value);
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

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data);
	printf("NULL \n");
}


int main() {
	ListNode* head = NULL;
	head = insert_first(head, (char*)"APPLE");
	print_list(head);
	head = insert_first(head, (char*)"KIWI");
	print_list(head);
	head = insert_first(head, (char*)"BANANA");
	print_list(head);

	return 0;
}
