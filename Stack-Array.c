#include <stdio.h>

#define MAX 100 // Sức chứa tối đa của ngăn xếp

// 1. Định nghĩa cấu trúc item
typedef struct {
    int value;
} item;

// 2. Định nghĩa cấu trúc Stack
typedef struct {
    item data[MAX];
    int top; // Chỉ số của phần tử trên cùng
} Stack;

// Hàm khởi tạo ngăn xếp
void initStack(Stack *s) {
    s->top = -1; // -1 nghĩa là ngăn xếp đang rỗng
}

// Kiểm tra ngăn xếp đầy
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Kiểm tra ngăn xếp rỗng
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Hàm thêm 1 phần tử vào ngăn xếp (Push)
void push(Stack *s, item x) {
    if (isFull(s)) {
        printf("Ngan xep da day (Stack Overflow)!\n");
        return;
    }
    s->top++;
    s->data[s->top] = x;
}

// Hàm lấy 1 phần tử ra khỏi ngăn xếp (Pop)
item pop(Stack *s) {
    item temp;
    if (isEmpty(s)) {
        printf("Ngan xep rong (Stack Underflow)!\n");
        return Inf;
    }
    temp = s->data[s->top];
    s->top--;
    return temp;
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
        printf("Ngan xep dang rong.\n");
        return;
    }
    printf("Cac phan tu trong Stack (tu Top xuong Bottom): \n");
    for (int i = s.top; i >= 0; i--) {
        printf("| %d |\n", s.data[i].value);
    }
    printf("-----\n");
}

void pushBottom(Stack *s, item x) {
    if (isFull(s)) {
        printf("Ngan xep day, khong the them vao day!\n");
        return;
    }   
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
    if (isFull(s)) {
        printf("Stack day!\n");
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