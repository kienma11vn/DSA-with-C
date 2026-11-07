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

void insertNode(Tree *t, item x) {
    if (*t == NULL) {
        *t = createNode(x);
    } else {
        if (x < (*t)->data) {
            insertNode(&((*t)->left), x);
        } else if (x > (*t)->data) {
            insertNode(&((*t)->right), x);
        }
    }
}

void inputTree(Tree *t) {
    item x;
    printf("\nBat dau nhap du lieu cho cay nhi phan:\n");
    while (1) {
        printf("\tNhap mot so nguyen chan (nhap so le de dung): ");
        scanf("%d", &x);        
        if (x % 2 != 0) {
            printf("Da nhap so le. Ket thuc nhap du lieu vao cay nhi phan tim kiem.\n");
            break;
        }
        insertNode(t, x);
    }
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

Node* searchNode(Tree t, item x) {
    if (t == NULL || t->data == x) {
        return t;
    }
    if (x < t->data) {
        return searchNode(t->left, x);
    }
    return searchNode(t->right, x);
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

Node* findMin(Tree t) {
    if (t == NULL) return NULL;
    Node* current = t;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* findMax(Tree t) {
    if (t == NULL) return NULL;
    Node* current = t;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

void printEvenNodes(Tree t) {
    if (t != NULL) {
        printEvenNodes(t->left);   // Duyệt bên trái
        if (t->data % 2 == 0) {    // Kiểm tra điều kiện số chẵn
            printf("%d ", t->data);
        }
        printEvenNodes(t->right);  // Duyệt bên phải
    }
}

void printOddNodes(Tree t) {
    if (t != NULL) {
        printOddNodes(t->left);    // Duyệt bên trái
        if (t->data % 2 != 0) {    // Kiểm tra điều kiện số lẻ
            printf("%d ", t->data);
        }
        printOddNodes(t->right);   // Duyệt bên phải
    }
}

void deleteLeaf(Tree *t, item x) {
    if (*t == NULL) return;

    if (x < (*t)->data) {
        deleteLeaf(&((*t)->left), x);
    } else if (x > (*t)->data) {
        deleteLeaf(&((*t)->right), x);
    } else {
        // Đã tìm thấy nút x
        if (isLeaf(*t)) {
            free(*t);
            *t = NULL;
            printf("\nDa xoa nut la %d", x);
        } else {
            printf("\nNut %d khong phai la nut la!", x);
        }
    }
}

void deleteNodeWithOneChild(Tree *t, item x) {
    if (*t == NULL) return;

    if (x < (*t)->data) {
        deleteNodeWithOneChild(&((*t)->left), x);
    } else if (x > (*t)->data) {
        deleteNodeWithOneChild(&((*t)->right), x);
    } else {
        // Đã tìm thấy nút x
        Node* p = *t;
        if ((*t)->left == NULL && (*t)->right != NULL) { // Chi co con phai
            *t = (*t)->right;
            free(p);
        } else if ((*t)->left != NULL && (*t)->right == NULL) { // Chi co con trai
            *t = (*t)->left;
            free(p);
        } else {
            printf("\nNut %d khong co dung 1 con!", x);
        }
    }
}

int deleteNode(Tree *t, item x) {
    if (*t == NULL) return 0;
    if (x < (*t)->data) return deleteNode(&((*t)->left), x);
    if (x > (*t)->data) return deleteNode(&((*t)->right), x);
    Node* tam = *t;
    if ((*t)->left == NULL) {
        *t = (*t)->right;
        free(tam);
    } else if ((*t)->right == NULL) {
        *t = (*t)->left;
        free(tam);
    } else {
        Node* minRight = findMin((*t)->right);
        (*t)->data = minRight->data;
        deleteNode(&((*t)->right), minRight->data);
    }
    return 1;
}