#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int T, n;

char a[N], b[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%s", &n, a + 1);

        int ans = n;

        for (int i = 1; i <= n; i++)
            b[i] = a[i];
        
        sort(a + 1, a + n + 1);

        for (int i = 1; i <= n; i++)
            ans -= a[i] == b[i];
        
        printf("%d\n", ans);
    }
}