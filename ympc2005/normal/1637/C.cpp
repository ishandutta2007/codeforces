#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 1e5 + 10;

int n, a[N], T;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        ll sum = 0;
        int cnt = 0, tot = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 2; i < n; i++) {
            sum += a[i];
            cnt += a[i]&1;
            tot += a[i] == 1;
        }

        if (cnt < n - 2 || (tot < n - 2 && cnt > 1)) {
            printf("%lld\n", (sum + cnt)/2);
        } else {
            puts("-1");
        }
    }
}