#include <bits/stdc++.h>
using namespace std;

int T, l, r;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &l, &r);
        int ans = r % l;
        if ((r + 2) / 2 >= l && (r + 2) / 2 <= r) ans = max(ans, r % ((r + 2) / 2));
        printf("%d\n", ans);
    }
    return 0;
}