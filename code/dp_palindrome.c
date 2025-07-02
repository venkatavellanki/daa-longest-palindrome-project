#include <stdio.h>
#include <string.h>

void longestPalSubstr(char *str) {
    int n = strlen(str);
    int table[n][n];
    memset(table, 0, sizeof(table));
    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        table[i][i] = 1;

    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; ++k) {
        for (int i = 0; i < n - k + 1; ++i) {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = 1;
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    printf("Longest Palindromic Substring is: ");
    for (int i = start; i <= start + maxLength - 1; ++i)
        printf("%c", str[i]);
    printf("\n");
}

int main() {
    char str[] = "babad";
    longestPalSubstr(str);
    return 0;
}
