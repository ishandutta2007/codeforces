#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct fenwick_tree {
    vector<int> c;
    fenwick_tree(int n) : c(n + 1) {}

    void add(int p, int v) {
        for (p++; p < c.size(); p += p & -p) c[p] += v;
    }
    int sum(int p) {
        int s = 0;
        for (; p; p -= p & -p) s += c[p];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) {
        cin >> x;
    }
    partial_sum(a.begin(), a.end(), a.begin());
    auto b = a;
    sort(b.begin(), b.end() - 1);
    if (b[0] < 0 || n > 1 && b[n - 2] > b[n - 1]) {
        cout << "-1\n", exit(0);
    }
    map<ll, vector<int>> mp;
    for (int i = b.size() - 1; ~i; i--) {
        mp[b[i]].push_back(i);
    }
    fenwick_tree bit(a.size());
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        int j = mp[a[i]].back();
        ans += i - bit.sum(j), bit.add(j, 1);
        mp[a[i]].pop_back();
    }
    cout << ans << "\n";
    return 0;
}