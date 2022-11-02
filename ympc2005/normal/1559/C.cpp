#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int n, T, a[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        int pos = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);

            if (!a[i])
                pos = i;
        }

        if (!pos) {
            printf("%d ", n + 1);

            for (int i = 1; i <= n; i++)
                printf("%d ", i);
            
            puts("");
            continue;
        }

        for (int i = 1; i <= pos; i++)
            printf("%d ", i);
        
        printf("%d ", n + 1);

        for (int i = pos + 1; i <= n; i++)
            printf("%d ", i);
        
        puts("");
    }
}