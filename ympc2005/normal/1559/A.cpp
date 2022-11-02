#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int T, n, a[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), a[1] &= a[i];
        
        printf("%d\n", a[1]);
    }
}