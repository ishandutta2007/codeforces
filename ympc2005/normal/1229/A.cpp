#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 7005;

int n, d[N];

ll a[N], b[N], ans;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && (a[j]&a[i]) == a[i]) {
                d[i]++;
            }
        }
    }

    queue <int> q;

    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int i = 1; i <= n; i++) {
            if (u != i && (a[i]&a[u]) == a[i]) {
                if (!--d[i]) {
                    q.push(i);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (d[i]) {
            ans += b[i];
        }
    }

    printf("%lld\n", ans);
}