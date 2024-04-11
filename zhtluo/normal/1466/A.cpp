#include <bits/stdc++.h>

int T, N;
int A[1000];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
        std::set<int> s;
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                s.insert(std::abs(A[j] - A[i]));
        printf("%d\n", (int) s.size());
    }
}