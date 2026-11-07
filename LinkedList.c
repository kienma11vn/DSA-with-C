#include <stdio.h>
#include <stdlib.h>

typedef int item;
struct Node {
    item data;
    struct Node* next;
};
typedef struct Node *List;

void init(List *L) {
    *L = NULL;
}

int isEmpty(List L) {
	return (L == NULL);
}

List createNode(item x) {
    List p = (List)malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    return p;
}

int doDai(List L) {
	List ds = L;
	int i = 0;
	while (ds != NULL) {
		ds = ds->next;
		i++;
	}
	return i;
}	

void insertLast(List *L, item x) {
    List p = createNode(x);
    if (*L == NULL) {
        *L = p;
    } else {
        List ds = *L;
        while (ds->next != NULL) {
            ds = ds->next;
        }
        ds->next = p;
    }
}

void input(List *L) {
    int n;
    item x;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\tNhap phan tu thu %d: ", i + 1);
        scanf("%d", &x);
        insertLast(L, x);
    }
}

void insertFirst(List *L, item x) {
	List p = createNode(x);
	if (*L == NULL) *L = p;
	else {
		p->next = *L;
		*L = p;
	}
}

void insertK(List *L, item x, int k) {	
	if (k < 1 || k >= doDai(*L) + 2) {
		printf("Vi tri %d khong hop le!/n", k);
		return;
	}	
	List p, ds = *L;
	if (k == 1) insertFirst(L, x);
	else if (k > 1 && k <= doDai(L)) {
		p = createNode(x);
		int i = 1;
		while (ds != NULL && i != k - 1) {
			ds = ds->next;
			i++;
		}
		p->next = ds->next;
		ds->next = p;
	} else {
		p = createNode(x);
		while (ds->next != NULL) ds = ds->next;
		ds->next = p;
	}
}

void display(List L) {
    printf("Danh sach lien ket: ");
    List ds = *L;
    while (ds != NULL) {
        printf("%d -> ", ds->data);
        ds = ds->next;
    }
    printf("NULL\n");
}

int search(List L, item x) {
	struct Node* temp = L;
	int i = 1;
	while (temp != NULL) {
		if (temp->data == x) return i;
		temp = temp->next;
		i++;
	}
	return -1;
}	

int findLastX(List L, item x) {
    struct Node* temp = L;
    int index = 1;
    int lastPos = -1;   
    while (temp != NULL) {
        if (temp->data == x) {
            lastPos = index;
        }
        temp = temp->next;
        index++;
    }
    return lastPos;
}

void deleteFirst(List *L, item *x) {
	if (*L == NULL) return;
	Node* p = *L;
	*x = L->data;
	*L = p->next;
	free(p);
}

void deleteK(List *L, item *x, int k) {
	if (k < 1 || k > doDai(L)) {
		printf("Vi tri %d khong hop le!/n", k);
		return;
	}
	if (k == 1) deleteFirst(L, x);
	List p, ds = *L;
	int i = 1;
	while (ds != NULL && i != k - 1) {
		ds = ds->next;
		i++;
	}
	p = ds->next;
	*x = p->data;
	ds->next = p->next;
}

float avgNegative(List L) {
    long tong = 0;
    int dem = 0;
    List ds = L;
    while (ds != NULL) {
        if (ds->data < 0) {
            tong += ds->data;
            dem++;
        }
        ds = ds->next;
    }
    if (dem == 0) return 0;
    return (float) tong / dem;
}

void splitEvenOdd(List L, List *LEven, List *LOdd) {
    init(LEven);
    init(LOdd);
    List temp = L;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            insertLast(LEven, temp->data);
        } else {
            insertLast(LOdd, temp->data);
        }
        temp = temp->next;
    }
}

void mergeList(List L1, List L2, List *LResult) {
    init(LResult); // Khởi tạo danh sách kết quả là NULL      
    List temp = L1; // Duyệt và chèn các phần tử của L1 vào LResult
    while (temp != NULL) {
        insertLast(LResult, temp->data); // Sử dụng hàm chèn cuối đã có
        temp = temp->next;
    }        
    temp = L2; // Duyệt và chèn tiếp các phần tử của L2 vào LResult
    while (temp != NULL) {
        insertLast(LResult, temp->data);
        temp = temp->next;
    }
}