#include <stdio.h>
#include <stdlib.h>

// 1. Định nghĩa cấu trúc item
typedef struct {
    int value;
} item;

// 2. Định nghĩa cấu trúc một nút (Node) trong Stack
typedef struct Node {
    item data;
    struct Node *next;
} Node;

// 3. Định nghĩa cấu trúc Stack (chỉ cần quản lý con trỏ Top)
typedef struct {
    Node *top;
} Stack;

// Hàm khởi tạo ngăn xếp rỗng
void initStack(Stack *s) {
    s->top = NULL;
}

// Kiểm tra ngăn xếp rỗng
int isEmpty(Stack *s) {
    return s->top == NULL;
}

// Hàm tạo một nút mới
Node* createNode(item x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm 1 phần tử vào đỉnh ngăn xếp (Push)
void push(Stack *s, item x) {
    Node *newNode = createNode(x);
    newNode->next = s->top; // Nút mới trỏ đến nút top hiện tại
    s->top = newNode;       // Cập nhật nút mới thành top
}

// Hàm lấy 1 phần tử ra khỏi đỉnh ngăn xếp (Pop)
item pop(Stack *s) {
    item tempValue;
    if (isEmpty(s)) {
        printf("Stack rong, khong the lay phan tu!\n");
        return Inf;
    }   
    Node *tempNode = s->top;
    tempValue = tempNode->data;    
    s->top = s->top->next; // Chuyển top xuống nút bên dưới
    free(tempNode);        // Giải phóng bộ nhớ của nút vừa lấy ra   
    return tempValue;
}

// Hàm tính số phần tử trong Stack (doDai)
int doDai(Stack s) {
    int count = 0;
    Node *current = s.top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Hàm input: Nhập dữ liệu cho ngăn xếp
void input(Stack *s) {
    int n;
    item temp;
    printf("Nhap so luong phan tu muon dua vao Stack: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &temp.value);
        push(s, temp);
    }
}

// Hàm output: Hiển thị dữ liệu trong ngăn xếp
void output(Stack s) {
    if (isEmpty(&s)) {
        printf("Stack dang rong.\n");
        return;
    }
    Node *current = s.top;
    printf("Cac phan tu trong Stack (tu Top xuong Bottom):\n");
    while (current != NULL) {
        printf("| %d |\n", current->data.value);
        current = current->next;
    }
    printf("-----\n");
}

void pushBottom(Stack *s, item x) {  
    Stack tempStack;
    initStack(&tempStack);
	item i;
    while (!isEmpty(s)) { // Bốc hết từ s sang tempStack
        i = pop(s);
		push(&tempStack, i);
    }    
    push(s, x); // Đẩy x vào đáy (Stack s lúc này đang rỗng)        
    while (!isEmpty(&tempStack)) { // Đổ ngược lại từ tempStack về s
        i = pop(&tempStack);
		push(s, i);
    }
}

item popBottom(Stack *s) {
    item result, i;
    if (isEmpty(s)) {
        printf("Stack rong!\n");
        return Inf;
    }
    Stack tempStack;
    initStack(&tempStack);
    while (s->top > 0) {
        i = pop(s);
		push(&tempStack, i); // 1. Chuyển toàn bộ phần tử sang Stack tạm cho đến khi chỉ còn 1 phần tử cuối
    }
    result = pop(s); // 2. Lấy phần tử cuối cùng (phần tử đáy)
    while (!isEmpty(&tempStack)) {
        i = pop(&tempStack);
		push(s, i); // 3. Đổ ngược lại từ Stack tạm về Stack chính để giữ nguyên thứ tự ban đầu
    }
    return result;
}

void insertAt(Stack *s, item x, int k) {
    if (k < 1 || k > doDai(*s) + 1) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    Stack tempStack;
    initStack(&tempStack);        
    int count = 0;
	item i;
    while (!isEmpty(s) && count < k) { // Lấy các phần tử ra cho đến trước vị trí k
        i = pop(s);
		push(&tempStack, i);
        count++;
    }        
    push(s, x); // Thêm phần tử x vào      
    while (!isEmpty(&tempStack)) { // Trả lại các phần tử cũ
        i = pop(&tempStack);
		push(s, i);
    }
}

item popAt(Stack *s, int k) {
    item result, i;
    if (isEmpty(s) || k < 0 || k > s->top) {
        printf("Vi tri khong hop le hoac Stack rong!\n");
        return Inf;
    }
    Stack tempStack;
    initStack(&tempStack);
    int count = 0;  
    while (count < k) {
        i = pop(s);
		push(&tempStack, i); // 1. Chuyển các phần tử nằm trên vị trí k sang Stack tạm
        count++;
    }   
    result = pop(s); // 2. Lấy phần tử mục tiêu tại vị trí k
    while (!isEmpty(&tempStack)) {
        i = pop(&tempStack);
		push(s, i); // 3. Đổ các phần tử từ Stack tạm quay lại Stack chính
    }
    return result;
}

void decimalToBinary(int n) {
    Stack s;
    initStack(&s);
    item temp;   
    if (n == 0) {
        printf("Ket qua nhi phan: 0\n");
        return;
    }
    int original = n;
    while (n > 0) {
        temp.value = n % 2; // Lấy số dư
        push(&s, temp);
        n = n / 2;
    }
    printf("So %d chuyen sang nhi phan la: ", original);
    while (!isEmpty(&s)) {
        printf("%d", pop(&s).value);
    }
    printf("\n");
}