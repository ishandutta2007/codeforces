#include <bits/stdc++.h>
using namespace std;

int T, a, b, xors[300010];

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= 300000; i++) {
        xors[i] = i ^ xors[i - 1];
    }
    while (T--) {
        scanf("%d %d", &a, &b);
        int ans = a;
        if (b == xors[a - 1]) ans += 0;
        else if ((b ^ xors[a - 1]) == a) ans += 2;
        else ans += 1;
        printf("%d\n", ans);
    }
    return 0;
}