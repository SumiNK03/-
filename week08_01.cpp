#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

#define MAX_QUEUE_SIZE 5

typedef std::string string;
typedef char* element; // 요소의 타입
typedef struct QueueNode { // 큐의 노드의 타입
	element data;
	struct QueueNode* link;
} QueueNode;
typedef struct {
	QueueNode* front, * rear;
} LinkedQueueType;

// 오류 함수
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 큐 초기화
void init_queue(LinkedQueueType* q) {
	q->front = NULL;
	q->rear = NULL;
}
// 비었는지 확인
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

// 삽입 함수
void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		error("메모리 할당 에러");
	temp->data = data; // 데이터 저장
	temp->link = NULL; // 링크 필드를 NULL
	if (is_empty(q)) { // 큐가 공백이면
		q->front = temp;
		q->rear = temp;
	}
	else { // 큐가 공백이 아니면
		q->rear->link = temp; // 순서가 중요
		q->rear = temp;
	}
}

// 삭제 함수
element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {// 공백상태
		error("큐가 공백상태입니다.");
	}
	data = temp->data; // 데이터를 꺼낸다.
	q->front = q->front->link; // front로 다음노드
	if (q->front == NULL) // 큐가 비었다면
		q->rear = NULL;
	free(temp); // 동적 메모리 해제
	return data; // 데이터 반환
}

// 노트가 복원 가능하면 1, 불가능하면 0을 return 
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
	init_queue(&list); // 큐 초기화

	//테스트 케이스 수
	int T = 0;
	scanf("%d", &T);

	while (T > 0) {
		//친구의 수, 문장의 단어 갯수
		int N = 0;
		int M = 0;
		scanf("%d %d", &N, &M);

		//문장
		char str[100] = "";
		scanf("%s", str);
		char* splited = strtok(str, " ");
		for (int i = 0; i < M; i++)
			enqueue(&list, (element)splited[i]);

		//친구들의 문장
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