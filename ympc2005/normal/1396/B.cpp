#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N], T;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        int sum = 0, mx = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
            mx = max(mx, a[i]);
        }

        printf("%s\n", (mx > sum - mx || (sum&1)) ? "T" : "HL");
    } 
}