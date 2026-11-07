#include <stdio.h> // Ngôn ngữ C
#include <math.h>

#define MAX 100

typedef int item

typedef struct {
    item data[MAX];
    int size; // Số lượng phần tử hiện tại
} List;

void init(List *L) {
	(*L).size = 0;
}

int isEmpty(List L) {
	return (L.size == 0);
}

int isFull(List L) {
	return (L.size == (MAX - 1));
}

int search(List L, item x) {
    for (int i = 0; i < L.size; i++) {
        if (L.data[i] == x) return i;
    }
    return -1;
}

int findLastX(List L, item x) {   
    for (int i = L.size - 1; i >= 0; i--) { // Duyệt từ cuối danh sách về đầu danh sách
        if (L.data[i] == x) return i;
    }
    return -1; // Không tìm thấy x trong danh sách
}

void insertK(List *L, int k, item x) {
    if (isFull(*L)) {
        printf("Danh sach day!\n");
        return;
    }
    if (k < 0 || k > L->size) {
        printf("Vi tri %d khong hop le!\n", k);
        return;
    }
    for (int i = L->size; i > k; i--) {
        L->data[i] = L->data[i - 1];
    }
    L->data[k] = x;
    L->size++;
}

void deleteK(List *L, int k) {
    if (isEmpty(*L)) {
        printf("Danh sach rong!\n");
        return;
    }
    if (k < 0 || k >= L->size) {
        printf("Vi tri %d khong hop le!\n", k);
        return;
    }
    for (int i = k; i < L->size - 1; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->size--;
}

void deleteX(List *L, item x) {
	if (isEmpty(*L)) {
        printf("Danh sach rong!\n");
		return;
    }
    int pos = search(*L, x);
	if (pos < 0) {
		printf("Phan tu %d khong ton tai!\n", x);
		return;
    }
    while (pos >= 0) {
        deleteK(L, pos);
        pos = search(*L, x); 
    }
}

void input(List *L) {
	int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
		if (!isFull(*L)) {
			printf("Nhap phan tu thu %d: ", i);
			scanf("%d", &L->data[L->size]);
			L->size++;
		} else printf("Danh sach day!\n");
    }
}

void display(List L) {
    for (int i = 0; i < L.size; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int countPrime(List L) { // Đếm phần tử là số nguyên tố
    int count = 0;
    for (int i = 0; i < L.size; i++) {
        if (isPrime(L.data[i])) count++;
    }
    return count;
}

void splitListEvenOdd(List L, List *Even, List *Odd) { // Tách danh sách chẵn lẻ
    init(Even);
    init(Odd);
    for (int i = 0; i < L.size; i++) {
        if (L.data[i] % 2 == 0) {
            Even->data[Even->size] = L.data[i];
			Even->size++;
        } else {
            Odd->data[Odd->size] = L.data[i];
			Odd->size++;
        }
    }
}

void mergeList(List L1, List L2, List *LResult) {
    init(LResult); // Khởi tạo danh sách kết quả rỗng   
    for (int i = 0; i < L1.size; i++) { // Chép phần tử từ L1 vào LResult
        if (!isFull(*LResult)) {
            LResult->data[LResult->size] = L1.data[i];
            LResult->size++;
        }
    }    
    for (int i = 0; i < L2.size; i++) { // Chép phần tử từ L2 vào LResult
        if (!isFull(*LResult)) {
            LResult->data[LResult->size] = L2.data[i];
            LResult->size++;
        } else {
            printf("Danh sach ket qua da day!\n");
            break;
        }
    }
}