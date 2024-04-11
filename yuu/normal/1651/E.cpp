#include <bits/stdc++.h>
using namespace std;
int n;
bool done[3001];
vector<int> g[3001];
vector<int> order;
void dfs(int u) {
    order.push_back(u);
    done[u] = 1;
    for (int v : g[u])
        if (!done[v]) {
            dfs(v);
        }
}
int64_t ans;
void must_have(int u, int v, int &max_l, int &min_r, int &max_L, int &min_R) {
    if (u > v) swap(u, v);
    max_l = min(max_l, u);
    min_r = max(min_r, u);
    max_L = min(max_L, v);
    min_R = max(min_R, v);
}

int triangle(int n) { return n * (n + 1) / 2; }

int get(int max_l, int min_r) {
    if (max_l > n) max_l -= n;
    if (min_r > n) min_r -= n;
    // l <= maxl
    // r >= minr
    // l <= r
    if (max_l <= min_r)
        return max_l * (n - min_r + 1);
    else {
        return max_l * (n - min_r + 1) - triangle(max_l - min_r - 1);
    }
}

int get_range(int max_L, int min_R, int min_LR, int max_LR) {
    if (min_LR > max_LR) return 0;
    max_L = min(max_L, max_LR);
    min_R = max(min_R, min_LR);
    // min_LR <= L <= max_L
    // min_R <= R <= max_LR
    // L <= R
    if (max_L < min_LR) return 0;
    if (min_R > max_LR) return 0;
    if (max_L <= min_R) {
        return (max_L - min_LR + 1) * (max_LR - min_R + 1);
    } else {
        return (max_L - min_LR + 1) * (max_LR - min_R + 1) - triangle(max_L - min_R - 2);
    }
}

void must_not_have(int b, int d, int max_l, int min_r, int max_L, int min_R) {
    // L, R must have:
    // L <= max_L
    // R >= min_R
    // L, R do not contain b, d
    if (b > d) swap(b, d);
    int64_t choose_right = get_range(max_L, min_R, n + 1, b - 1);
    choose_right += get_range(max_L, min_R, b + 1, d - 1);
    choose_right += get_range(max_L, min_R, d + 1, n * 2);
    ans -= choose_right * get(max_l, min_r);
}

void make() {
    for (int i = 0; i < order.size(); i += 2) {  // first vertex
        int u = order[i];
        int prev_u = order[(i + order.size() - 1) % order.size()];
        int max_l = u;
        int min_r = u;
        int max_L = n * 2;
        int min_R = n + 1;
        int old, v = u;
        for (int j = i + 1; j != i; (j += 1) %= order.size()) {
            old = v;
            v = order[j];
            must_have(v, old, max_l, min_r, max_L, min_R);
            if (j % 2 == 0) {
                must_not_have(prev_u, order[j + 1], max_l, min_r, max_L, min_R);
            }
        }
    }
}

// everytime i has at least 1 edge
void make_single(int i) {
    int a = g[i][0];
    int b = g[i][1];
    int64_t total = triangle(n);
    if (a > b) swap(a, b);

    total -= triangle(a - n - 1);
    total -= triangle(b - a - 1);
    total -= triangle(n * 2 - b);
    total *= i;
    total *= (n - i + 1);
    ans += total;
}

void solve() {
    cin >> n;
    for (int i = 1, x, y; i <= n * 2; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        if (!done[i]) {
            order.clear();
            dfs(i);
            make();
        }
    for (int i = 1; i <= n; i++) make_single(i);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}