#include <stdio.h>

void generateBinary(int n, char *arr, int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            printf("%c", arr[i]);
        }
        printf("\n");
        return;
    }
    
    arr[index] = 'A'; // 0
    generateBinary(n, arr, index + 1);
    
    arr[index] = 'B'; // 1
    generateBinary(n, arr, index + 1);
}

int main() {
    int n;
    printf("Nhập độ dài xâu nhị phân AB: ");
    scanf("%d", &n);
    
    char arr[n];
    printf("Các xâu nhị phân AB có độ dài %d bao gồm: \n", n);
    generateBinary(n, arr, 0);
    
    return 0;
}