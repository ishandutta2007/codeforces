#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;

ll a[N];

void go() {
    int n; scanf("%d", &n);
    ll sum = 0;
    ll val = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        sum += a[i];
        val ^= a[i];
    }
    printf("2\n");
    ll ans1 = val;;
    sum += val;
    printf("%lld %lld\n", ans1, sum);
    /*for (int i = 1; i < n; ++i) {
        if (abs(a[i] - a[i + 1]) >= 2) {
            puts("YES");
            printf("%d %d\n", i, i + 1);
            return;
        }
    }
    puts("NO");*/
}

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        go();
    }
}