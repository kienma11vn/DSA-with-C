#include <stdio.h>
#include <stdlib.h>

// 1. Định nghĩa cấu trúc dữ liệu item
typedef struct {
    int value;
} item;

// 2. Định nghĩa cấu trúc một nút (Node) trong Queue
typedef struct Node {
    item data;
    struct Node *next;
} Node;

// 3. Định nghĩa cấu trúc Queue quản lý đầu và cuối
typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Hàm khởi tạo hàng đợi rỗng
void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Kiểm tra hàng đợi rỗng
int isEmpty(Queue *q) {
    return q->front == NULL;
}

// Hàm tạo một Node mới
Node* createNode(item x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm 1 phần tử vào cuối hàng đợi (Enqueue)
void enqueue(Queue *q, item x) {
    Node *newNode = createNode(x);
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Hàm lấy 1 phần tử ra khỏi đầu hàng đợi (Dequeue)
item dequeue(Queue *q) {
    item tempValue;
    if (isEmpty(q)) {
        printf("Hang doi rong, khong the lay phan tu!\n");
        return Inf;
    }

    Node *tempNode = q->front;
    tempValue = tempNode->data;
    
    q->front = q->front->next;

    // Nếu sau khi lấy ra mà Queue rỗng thì rear cũng phải NULL
    if (q->front == NULL) {
        initQueue(&q);
    }

    free(tempNode);
    return tempValue;
}

// Hàm tính số phần tử trong Queue (doDai)
int doDai(Queue q) {
    int count = 0;
    Node *current = q.front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Hàm input: Nhập dữ liệu cho hàng đợi
void input(Queue *q) {
    int n;
    item temp;
    printf("Nhap so luong phan tu muon them: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &temp.value);
        enqueue(q, temp);
    }
}

// Hàm output: Hiển thị dữ liệu trong hàng đợi
void output(Queue q) {
    if (isEmpty(&q)) {
        printf("Hang doi dang rong.\n");
        return;
    }
    Node *current = q.front;
    printf("Cac phan tu trong Queue: ");
    while (current != NULL) {
        printf("%d -> ", current->data.value);
        current = current->next;
    }
    printf("NULL\n");
}

void enqueueFront(Queue *q, item x) {
    if (isFull(q)) {
        printf("Hang doi day!\n");
        return;
    }
    Queue tempQ;
    initQueue(&tempQ);

    // Bước 1: Cho phần tử mới vào tempQ trước
    enqueue(&tempQ, x);

    // Bước 2: Chuyển toàn bộ phần tử từ q sang tempQ
    while (!isEmpty(q)) {
        enqueue(&tempQ, dequeue(q));
    }

    // Bước 3: Đưa ngược lại q (hoặc gán q = tempQ)
    *q = tempQ;
}

void insertAt(Queue *q, item x, int k) {
    if (k < 1 || k > q->size + 1) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    if (isFull(q)) {
        printf("Hang doi day!\n");
        return;
    }
    Queue tempQ;
    initQueue(&tempQ);
	item i;
	int count = 0;  
    
    // Chuyển k-1 phần tử sang tempQ
    while (count < k) {
		i = dequeue(q);
        enqueue(&tempQ, i);
		count++;
    }

    // Thêm phần tử mới vào tempQ
    enqueue(&tempQ, x);

    // Chuyển các phần tử còn lại sang tempQ
    while (!isEmpty(q)) {
		i = dequeue(q);
        enqueue(&tempQ, i);
    }

    *q = tempQ;
}

item dequeueRear(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        item empty = {-1}; return empty;
    }

    Queue tempQ;
    initQueue(&tempQ);
	item i;
	
    // Chuyển size-1 phần tử sang tempQ
    while (q->size > 1) {
        i = dequeue(q);
        enqueue(&tempQ, i);
    }

    // Phần tử cuối cùng còn lại trong q
    item lastItem = dequeue(q);

    // Trả lại dữ liệu cho q
    *q = tempQ;

    return lastItem;
}

item dequeueAt(Queue *q, int k) {
    if (isEmpty(q) || k < 1 || k > q->size) {
        printf("Vi tri khong hop le!\n");
        item empty = {-1}; return empty;
    }

    Queue tempQ;
    initQueue(&tempQ);
    item i;

    // Chuyển k-1 phần tử đầu sang tempQ
    int count = 0;  
    while (count < k) {
        i = dequeue(q);
        enqueue(&tempQ, i);
		count++;
    }

    // Lấy phần tử mục tiêu ra
    item target = dequeue(q);

    // Chuyển các phần tử còn lại sang tempQ
    while (!isEmpty(q)) {
        i = dequeue(q);
        enqueue(&tempQ, i);
    }

    *q = tempQ;
    return target;
}