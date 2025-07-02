#include <stdio.h>
#include <string.h>

int preprocess(char *str, char *t) {
    int len = strlen(str);
    t[0] = '^';
    for (int i = 0; i < len; i++) {
        t[2 * i + 1] = '#';
        t[2 * i + 2] = str[i];
    }
    t[2 * len + 1] = '#';
    t[2 * len + 2] = '$';
    t[2 * len + 3] = '\0';
    return 2 * len + 3;
}

void manacher(char *str) {
    char t[202];
    int p[202];
    int n = preprocess(str, t);
    int center = 0, right = 0;

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;

        if (i < right)
            p[i] = (p[mirror] < (right - i)) ? p[mirror] : (right - i);
        else
            p[i] = 0;

        while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
            p[i]++;

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    printf("Longest Palindromic Substring is: ");
    for (int i = start; i < start + maxLen; i++)
        printf("%c", str[i]);
    printf("\n");
}

int main() {
    char str[] = "babad";
    manacher(str);
    return 0;
}
