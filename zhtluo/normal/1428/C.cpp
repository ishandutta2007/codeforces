#include <bits/stdc++.h>

int l;
char s[210000];
char stack[210000];
int size = 0;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf(" %s", s);
        l = strlen(s);
        size = 0;
        for (int i = 0; i < l; ++i) {
            stack[size++] = s[i];
            if (size >= 2 && stack[size - 2] == 'A' && stack[size - 1] == 'B') size -= 2;
            if (size >= 2 && stack[size - 2] == 'B' && stack[size - 1] == 'B') size -= 2;
        }
        printf("%d\n", size);
    }
}