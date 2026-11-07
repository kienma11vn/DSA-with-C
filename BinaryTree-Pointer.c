#include <stdio.h>
#include <stdlib.h>

typedef int item;

typedef struct Node {
    item data;           
    struct Node* left;
    struct Node* right;
} Node;

typedef Node* Tree;

void initTree(Tree *t) {
    *t = NULL;
}

Node* createNode(item x) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p != NULL) {
        p->data = x;
        p->left = p->right = NULL;
    }
    return p;
}

// Hàm trả về địa chỉ của nút con bên trái
Node* getLeftChild(Node* p) {
    if (p != NULL) return p->left;
    return NULL;
}

// Hàm trả về địa chỉ của nút con bên phải
Node* getRightChild(Node* p) {
    if (p != NULL) return p->right;
    return NULL;
}

void preOrder(Tree t) {
    if (t != NULL) {
        printf("%d ", t->data); // Duyệt Gốc
        preOrder(t->left);      // Duyệt con trái
        preOrder(t->right);     // Duyệt con phải
    }
}

void inOrder(Tree t) {
    if (t != NULL) {
        inOrder(t->left);       // Duyệt con trái
        printf("%d ", t->data); // Duyệt Gốc
        inOrder(t->right);      // Duyệt con phải
    }
}

void postOrder(Tree t) {
    if (t != NULL) {
        postOrder(t->left);
        postOrder(t->right);
        printf("%d ", t->data);
    }
}

// Hàm thêm nút mới vào bên trái của nút cha p
void insertLeft(Node* p, item x) {
    if (p == NULL) {
        printf("Nut cha khong ton tai!\n");
    } else if (p->left != NULL) {
        printf("Nut trai da ton tai!\n");
    } else {
        p->left = createNode(x);
    }
}

// Hàm thêm nút mới vào bên phải của nút cha p
void insertRight(Node* p, item x) {
    if (p == NULL) {
        printf("Nut cha khong ton tai!\n");
    } else if (p->right != NULL) {
        printf("Nut phai da ton tai!\n");
    } else {
        p->right = createNode(x);
    }
}

void inputTree(Tree *t) {
    item x;
    printf("Nhap gia tri node (nhap -1 de bo qua): ");
    scanf("%d", &x);

    if (x == -1) {
        *t = NULL;
        return;
    }

    *t = createNode(x);
    
    printf("Nhap con trai cua %d:\n", x);
    inputTree(&((*t)->left));
    
    printf("Nhap con phai cua %d:\n", x);
    inputTree(&((*t)->right));
}

// Hàm tìm kiếm trả về địa chỉ của Node chứa giá trị x
Node* searchNode(Tree t, item x) {
    if (t == NULL) {
        return NULL;
    }
    
    // Nếu tìm thấy tại gốc
    if (t->data == x) {
        return t;
    }
    
    // Tìm bên trái
    Node* p = searchNode(t->left, x);
    if (p != NULL) {
        return p;
    }
    
    // Nếu bên trái không có, tìm bên phải
    return searchNode(t->right, x);
}

void deleteTree(Tree *t) {
    if (*t == NULL) return;
    
    // Xóa các nhánh con trước (Post-order)
    deleteTree(&((*t)->left));
    deleteTree(&((*t)->right));
    
    // Giải phóng nút hiện tại
    free(*t);
    *t = NULL;
}

void deleteLeft(Node* p) {
    if (p == NULL) {
        printf("Nut cha khong ton tai!\n");
    } else if (p->left == NULL) {
        printf("Khong co nut con ben trai de xoa!\n");
    } else {
        // Xóa toàn bộ nhánh con bên trái
        deleteTree(&(p->left));
        p->left = NULL;
        printf("Da xoa nut con ben trai.\n");
    }
}

void deleteRight(Node* p) {
    if (p == NULL) {
        printf("Nut cha khong ton tai!\n");
    } else if (p->right == NULL) {
        printf("Khong co nut con ben phai de xoa!\n");
    } else {
        // Xóa toàn bộ nhánh con bên phai
        deleteTree(&(p->right));
        p->right = NULL;
        printf("Da xoa nut con ben phai.\n");
    }
}

int isLeaf(Node* p) {
    if (p == NULL) return 0;
    return (p->left == NULL && p->right == NULL);
}

int countLeaves(Tree t) {
    if (t == NULL) return 0;
    if (isLeaf(t)) return 1;
    return countLeaves(t->left) + countLeaves(t->right);
}

int countNodes(Tree t) {
    if (t == NULL) return 0;
    return 1 + countNodes(t->left) + countNodes(t->right);
}

int getHeight(Tree t) {
    if (t == NULL) return 0;
    int leftHeight = getHeight(t->left);
    int rightHeight = getHeight(t->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int sumNodes(Tree t) {
    if (t == NULL) return 0;
    return t->data + sumNodes(t->left) + sumNodes(t->right);
}

// Hàm hỗ trợ tìm nút cha của nút có giá trị x
Node* findParent(Tree t, item x) {
    if (t == NULL || (t->left == NULL && t->right == NULL)) {
        return NULL;
    }

    // Kiểm tra xem con trực tiếp có chứa x không
    if ((t->left != NULL && t->left->data == x) || 
        (t->right != NULL && t->right->data == x)) {
        return t;
    }

    // Tìm ở các nhánh con
    Node* p = findParent(t->left, x);
    if (p != NULL) return p;
    
    return findParent(t->right, x);
}

void deleteNode(Tree *t, item x) {
    if (*t == NULL) return;

    // Trường hợp nút cần xóa là nút gốc
    if ((*t)->data == x) {
        deleteTree(t); // Hàm deleteTree đã có trong code của bạn
        *t = NULL;
        printf("Da xoa nut goc va toan bo cay.\n");
        return;
    }

    // Tìm nút cha của nút cần xóa
    Node* parent = findParent(*t, x);

    if (parent != NULL) {
        if (parent->left != NULL && parent->left->data == x) {
            deleteTree(&(parent->left)); // Xóa toàn bộ nhánh con trái
            parent->left = NULL;
        } else {
            deleteTree(&(parent->right)); // Xóa toàn bộ nhánh con phải
            parent->right = NULL;
        }
        printf("Da xoa nut co gia tri %d.\n", x);
    } else {
        printf("Khong tim thay nut co gia tri %d de xoa.\n", x);
    }
}