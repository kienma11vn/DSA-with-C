#include <stdio.h>

void generateBinary(int n, int arr[], int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
        return;
    }
    
    arr[index] = 0;
    generateBinary(n, arr, index + 1);
    
    arr[index] = 1;
    generateBinary(n, arr, index + 1);
}

int main() {
    int n;
    printf("Nhập độ dài dãy nhị phân: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Các dãy nhị phân có độ dài %d bao gồm: \n", n);
    generateBinary(n, arr, 0);
    
    return 0;
}