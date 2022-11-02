#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

ll n, k, p[N];

int m, ans;

int main() {
    scanf("%lld%d%lld", &n, &m, &k);

    for (int i = 1; i <= m; i++) {
        scanf("%lld", &p[i]);
    }

    for (int l = 1, r; l <= m; l = r + 1) {
        ans++, r = l;

        while (r < m && (p[r + 1] - l)/k == (p[l] - l)/k) {
            r++;
        }
    }

    printf("%d\n", ans);
}