#include <stdio.h>

#define MAX 100 // Sức chứa tối đa của hàng đợi

// Định nghĩa struct item
typedef struct {
    int value;
} item;

// Định nghĩa cấu trúc Queue
typedef struct {
    item data[MAX];
    int front;
    int rear;
    int size; // Số lượng phần tử hiện tại
} Queue;

// Hàm khởi tạo hàng đợi
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Kiểm tra hàng đợi đầy
int isFull(Queue *q) {
    return q->size == MAX;
}

// Kiểm tra hàng đợi rỗng
int isEmpty(Queue *q) {
    return q->size == 0;
}

// Hàm thêm 1 phần tử vào hàng đợi (Enqueue)
void enqueue(Queue *q, item x) {
    if (isFull(q)) {
        printf("Hang doi da day!\n");
        return;
    }
	if (q->rear < MAX - 1) {
		q->rear++;
		q->data[q->rear] = x;
		q->size++;
	} else {
		printf("Cuoi hang doi da den vi tri toi da!\n");
		return;  
	}
}

// Hàm lấy 1 phần tử ra khỏi hàng đợi (Dequeue)
item dequeue(Queue *q) {
    item temp;
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return Inf;
    }
	temp = q->data[q->front];
	if (q->size == 1) {
		initQueue(&q);
		return temp;
	}
	if (q->front < MAX - 1) {		
		q->front++;
		q->size--;
		return temp;
	} else {
		printf("Dau hang doi da den vi tri toi da!\n");
		return Inf;
	}
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
    printf("Cac phan tu trong Queue (tu front den rear): ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.data[i].value);
    }
    printf("\nSize hien tai: %d\n", q.size);
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