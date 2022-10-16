#include <bits/stdc++.h>
#define pdebug(x) cerr << __LINE__ << ": " << #x << " = " << x << '\n'
using namespace std;
int n;
string s;
int a[1000001];
int b[1000001];
int p[1000001];
int f[1000001];
vector<pair<int, int>> pos[1000001];

class segment_tree {
  public:
    using pointer = segment_tree*;
    pointer left, right;
    int l, r, m;
    int val;
    segment_tree(int l, int r) : l(l), r(r), m((l + r) / 2), val(n), left(nullptr), right(nullptr) {
        if (l != r) {
            left = new segment_tree(l, m);
            right = new segment_tree(m + 1, r);
        }
    }
    void update(int u, int v, int a) {
        if (l > v || r < u) return;
        if (u <= l && v >= r)
            val = min(val, a);
        else {
            left->update(u, v, a);
            right->update(u, v, a);
        }
    }
    void get(int best = n) {
        best = min(best, val);
        if (l == r)
            f[l] = best;
        else {
            left->get(best);
            right->get(best);
        }
    }
};
segment_tree* tree;

void add_query(int x, int y, int p) {
    // pdebug(x);
    // pdebug(y);
    // pdebug(p);
    tree->update(x, y, p);
}

void make(vector<pair<int, int>>& pos) {
    for (int i = 1; i < pos.size(); i++) pos[i].second += pos[i - 1].second;
    stack<int> temp;
    for (int i = ((int)pos.size()) - 1; i >= 0; i--) {
        while ((!temp.empty()) && (pos[i].second <= pos[temp.top()].second)) temp.pop();
        int best = temp.empty() ? (n + 1) : pos[temp.top()].first;
        // for i in [pos[i].first + 1, pos[i+1].first - 1]: r[i] = min (r[i], best - 1)
        // pdebug(pos[i].first);
        if (i + 1 >= pos.size())
            add_query(pos[i].first + 1, n, best - 1);
        else
            add_query(pos[i].first + 1, pos[i + 1].first, best - 1);
        temp.push(i);
    }

    while ((!temp.empty()) && (0 <= pos[temp.top()].second)) temp.pop();
    int best = temp.empty() ? (n + 1) : pos[temp.top()].first;
    add_query(1, pos[0].first, best - 1);
}

void solve() {
    for (int i = 2; i <= 1000000; i++)
        if (p[i] == 0)
            for (int j = i; j <= 1000000; j += i)
                if (p[j] == 0) p[j] = i;

    cin >> n;
    tree = new segment_tree(1, n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin>>s;
    for (int i = 1; i <= n; i++)
        if (s[i - 1] == '*')
            b[i] = 1;
        else
            b[i] = -1;

    for (int i = 1; i <= n; i++) {
        int x = a[i];
        while (x > 1) {
            int k = p[x];
            pos[k].emplace_back(i, 0);
            while (x % k == 0) {
                pos[k].back().second += b[i];
                x /= k;
            }
        }
    }
    for (int i = 1; i <= 1000000; i++)
        if (!pos[i].empty()){
            // pdebug(i);
            make(pos[i]);
        }

    tree->get();
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) ans += (f[i] - i + 1);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}