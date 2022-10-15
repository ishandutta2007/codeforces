#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 500010;
int T, n, a[maxn], f[maxn], c[maxn];
ll s[maxn];
vector<ll> V;

void ins(int p, int v) {
    for (p++; p <= V.size(); p += p & -p) c[p] = max(c[p], v);
}

int query(int p) {
    int mx = -1e9;
    for (p++; p; p -= p & -p) mx = max(mx, c[p]);
    return mx;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            s[i] = s[i - 1] + a[i];
        }
        V = vector<ll>(s, s + n + 1);
        sort(V.begin(), V.end());
        fill(c, c + V.size() + 1, -1e9);
        map<ll, int> mp;
        for (int i = 0; i <= n; i++) {
            if (i) f[i] = f[i - 1] + (a[i] > 0 ? 1 : (a[i] == 0 ? 0 : -1));
            if (mp.count(s[i])) f[i] = max(f[i], f[mp[s[i]]]);
            int j = lower_bound(V.begin(), V.end(), s[i]) - V.begin();
            f[i] = max(f[i], i + query(j - 1));
            ins(j, f[i] - i), mp[s[i]] = i;
        }
        printf("%d\n", f[n]);
    }
    return 0;
}