#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 300006;
const int P = 2 * N;
const int INF = 0x3f3f3f3f;

struct DJS {
    int p[2 * P], sz[2 * P];
    ll w[2 * P];
    void init() {
        for (int i = 0; i < 2 * P; ++i) {
            p[i] = i;
            sz[i] = 1;
            w[i] = 0;
        }
    }
    int Find(int x) {
        return p[x] == x ? x : p[x] = Find(p[x]);
    }
    void Union(int x, int y) {
        x = Find(x), y = Find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
        w[x] += w[y];
    }
    void set_w(int pos, int val) {
        w[pos] = val;
    }
    ll get_ans(int x) {
        return min( w[Find(x)], w[Find(x + P)] );
    }
} djs;

int a[N];
vector<int> ids[N];

ll cur_ans = 0;

void gao(int i, int x, int y) {
    if (djs.Find(x) == djs.Find(y) || djs.Find(x) == djs.Find(y + P)) return;
    cur_ans -= djs.get_ans(x);
    cur_ans -= djs.get_ans(y);
    if (a[i] == 1) {
        djs.Union(x, y);
        djs.Union(x + P, y + P);
    }
    else {
        djs.Union(x + P, y);
        djs.Union(x, y + P);
    }
    cur_ans += djs.get_ans(x);
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for (int i = 1; i <= n; ++i) {
        a[i] = s[i - 1] - '0';
    }
    djs.init();
    for (int i = 1; i <= k; ++i) {
        int c; cin >> c;
        for (int j = 0; j < c; ++j) {
            int x; cin >> x;
            ids[x].push_back(i);
        }
        djs.set_w(i, 1);
    }
    for (int i = 1; i <= n; ++i) {
        if ((int)ids[i].size() == 1) {
            ++k;
            ids[i].push_back(k);
            djs.set_w(k, INF);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if ((int)ids[i].size() == 2) {
            gao(i, ids[i][0], ids[i][1]);
        }
        cout << cur_ans << '\n';
    }
}