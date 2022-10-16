#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_A = 1e7;
int p[MAX_A + 1];
void prepare() {
    for (int i = 2; i <= MAX_A; i++)
        if (p[i] == 0)
            for (int j = i; j <= MAX_A; j += i)
                if (p[j] == 0) p[j] = i;
    p[1] = 1;
    for (int i = 2; i <= MAX_A; i++) {
        int prime = p[i];
        int j = i / prime;
        if (j % prime)
            p[i] = p[j] * prime;
        else
            p[i] = p[j / prime];
    }
}
int last[MAX_A];
int n, k;
int a[200001];
int f[200001];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        int prev = last[p[a[i]]];
        if (prev) f[i] = max(f[i], f[prev] + 1);
        last[p[a[i]]] = i;
    }
    cout << f[n] << '\n';
    for (int i = 1; i <= n; i++) last[p[a[i]]] = 0;
}
int main() {
    prepare();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}