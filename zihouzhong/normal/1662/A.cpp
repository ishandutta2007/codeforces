#include <bits/stdc++.h>
using namespace std;

int T, n, mx[11];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(mx, 0, sizeof(mx));
        while (n--) {
            int b, d;
            scanf("%d %d", &b, &d);
            mx[d] = max(mx[d], b);
        }
        bool flag = 1;
        int s = 0;
        for (int i = 1; i <= 10; i++) {
            s += mx[i];
            if (!mx[i]) flag = 0;
        }
        if (flag) printf("%d\n", s);
        else puts("MOREPROBLEMS");
    }
    return 0;
}