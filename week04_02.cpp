
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


void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

//Ư�� ���� item�� ��ȸ�ϸ� Ž���Ѵ�.
void search(ListNode* head, element item) {
	bool find = false;
	print_list(head);
	for (ListNode* i = head; i != NULL; i = i->link) {
		if (i->data == item) {
			find = true;
			break;
		}
	}
	if (find)
		printf("����Ʈ���� %d�� ã�ҽ��ϴ�.", item);
}

int main(void) {
	ListNode* head = NULL;
	head = insert_first(head, 10);
	search(head, 30);
	head = insert_first(head, 20);
	search(head, 30);
	head = insert_first(head, 30);
	search(head, 30);

	return 0;
}
