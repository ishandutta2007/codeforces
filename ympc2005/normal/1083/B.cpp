#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int n;

ll ans, m;

char s[N], t[N];

int main() {
    scanf("%d%lld%s%s", &n, &m, s + 1, t + 1);
    ll len = 0, pre;
    ans = n;

    for (int i = 1; i <= n; i++) {
        pre = len + 1;
        len *= 2;
        len -= s[i] == 'b';
        len += t[i] == 'b';

        if (len + 1 >= m) {
            ans += (m - pre)*(n - i + 1);
            break;
        }

        ans += (len + 1 - pre)*(n - i + 1);
    }

    printf("%lld\n", ans);
}