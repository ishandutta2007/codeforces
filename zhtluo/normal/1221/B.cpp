#include <bits/stdc++.h>

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            printf("%c", i + j & 1 ? 'W' : 'B');
        puts("");
    }
}