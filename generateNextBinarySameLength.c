#include <stdio.h>
#include <string.h>

void nextBinary(char *binary) {
    int len = strlen(binary);
    int i;

    for (i = len - 1; i >= 0; i--) {
        if (binary[i] == '0') {
            binary[i] = '1';
            for (int j = i + 1; j < len; j++) {
                binary[j] = '0';
            }
            printf("Dãy nhị phân kế tiếp: %s\n", binary);
            return;
        }
    }
    printf("Không có dãy nhị phân kế tiếp cùng độ dài với dãy nhị phân đã cho\n");
}

int main() {
    char binary[100];
    printf("Nhập dãy nhị phân: ");
    scanf("%s", binary);
    nextBinary(binary);
    return 0;
}