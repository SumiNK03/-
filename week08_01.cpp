#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

#define MAX_QUEUE_SIZE 5

typedef std::string string;
typedef char* element; // ����� Ÿ��
typedef struct QueueNode { // ť�� ����� Ÿ��
	element data;
	struct QueueNode* link;
} QueueNode;
typedef struct {
	QueueNode* front, * rear;
} LinkedQueueType;

// ���� �Լ�
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// ť �ʱ�ȭ
void init_queue(LinkedQueueType* q) {
	q->front = NULL;
	q->rear = NULL;
}
// ������� Ȯ��
int is_empty(LinkedQueueType* q) {
	return (q->front == NULL);
}

void queue_print(LinkedQueueType* q) {
	printf(" | ");
	for (QueueNode* p = q->front; p != NULL; p = p->link) {
		printf("%s | ", p->data);
	}
	printf("\n");
}

// ���� �Լ�
void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		error("�޸� �Ҵ� ����");
	temp->data = data; // ������ ����
	temp->link = NULL; // ��ũ �ʵ带 NULL
	if (is_empty(q)) { // ť�� �����̸�
		q->front = temp;
		q->rear = temp;
	}
	else { // ť�� ������ �ƴϸ�
		q->rear->link = temp; // ������ �߿�
		q->rear = temp;
	}
}

// ���� �Լ�
element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {// �������
		error("ť�� ��������Դϴ�.");
	}
	data = temp->data; // �����͸� ������.
	q->front = q->front->link; // front�� �������
	if (q->front == NULL) // ť�� ����ٸ�
		q->rear = NULL;
	free(temp); // ���� �޸� ����
	return data; // ������ ��ȯ
}

// ��Ʈ�� ���� �����ϸ� 1, �Ұ����ϸ� 0�� return 
int possible(LinkedQueueType friends[], LinkedQueueType* list, int fnum) {
	while (true) {
		bool is = false;
		element word = dequeue(list);
		for (int i = 0; i < fnum; i++) {
			if (friends[i].front->data == word) {
				is = true;
				dequeue(&friends[i]);
			}
		}
		if (is == false)
			return 0;
	}
	return 1;
}

int main() {
	LinkedQueueType list;
	init_queue(&list); // ť �ʱ�ȭ

	//�׽�Ʈ ���̽� ��
	int T = 0;
	scanf("%d", &T);

	while (T > 0) {
		//ģ���� ��, ������ �ܾ� ����
		int N = 0;
		int M = 0;
		scanf("%d %d", &N, &M);

		//����
		char str[100] = "";
		scanf("%s", str);
		char* splited = strtok(str, " ");
		for (int i = 0; i < M; i++)
			enqueue(&list, (element)splited[i]);

		//ģ������ ����
		LinkedQueueType friends[100];
		for (int i = 0; i < 100; i++)
			init_queue(&friends[i]);
		for (int i = 0; i < N; i++) {
			int k = 0;
			char str1[100] = "";
			scanf("%d %s", &k, str1);
			char* splited1 = strtok(str1, " ");
			for (int j = 0; j < k; j++)
				enqueue(&friends[i], (element)splited1[j]);
		}

		printf("%d\n", possible(friends, &list, N));

		T--;
	}
	return 0;
}