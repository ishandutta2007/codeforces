#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, a[N], prime[N], tot;
long long sum[20][N];
bool tag[N];
multiset<long long> s[20];
void solve() {
    cin >> n >> q;
    vector<int> p;
    int x = n;
    for (int i = 1; prime[i] * prime[i] <= n; ++i) {
        if (x % prime[i] == 0) {
            p.emplace_back(prime[i]);
            while (x % prime[i] == 0) {
                x /= prime[i];
            }
        }
    }
    if (x > 1) {
        p.emplace_back(x);
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < (int) p.size(); ++i) {
        s[i].clear();
        int w = n / p[i];
        for (int j = 0; j < w; ++j) {
            sum[i][j] = 0;
        }
        for (int j = 0; j < n; ++j) {
            sum[i][j % w] += a[j];
        }
        for (int j = 0; j < w; ++j) {
            s[i].insert(sum[i][j]);
        }
    }
    long long ans = 0;
    for (int i = 0; i < (int) p.size(); ++i) {
        int w = n / p[i];
        ans = max(ans, 1ll * *(--s[i].end()) * w);
    }
    cout << ans << "\n";
    while (q--) {
        int pos, x;
        cin >> pos >> x;
        --pos;
        long long ans = 0;
        int delta = x - a[pos];
        a[pos] = x;
        for (int i = 0; i < (int) p.size(); ++i) {
            int w = n / p[i];
            s[i].erase(s[i].find(sum[i][pos % w]));
            sum[i][pos % w] += delta;
            s[i].insert(sum[i][pos % w]);
            ans = max(ans, 1ll * *(--s[i].end()) * w);
        }
        cout << ans << "\n";
    }
}
int main() {
    for (int i = 2; i < N; ++i) {
        if (!tag[i]) {
            prime[++tot] = i;
            for (int j = 2; i * j < N; ++j) {
                tag[i * j] = true;
            }
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}