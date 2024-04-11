#include <bits/stdc++.h>
using namespace std;
int n, k;
string c;
int l[200001];
int r[200001];
int p[200001];
bool should_duplicate[200001];
bool duplicated[200001];
vector<int> order;
void dfs(int u) {
    if (l[u]) dfs(l[u]);
    order.push_back(u);
    if (r[u]) dfs(r[u]);
}
vector<int> ancestors;
int marked_depth;
void mark(int u, bool allow_duplicate) {
    ancestors.push_back(u);
    if (l[u]) mark(l[u], allow_duplicate);
    marked_depth = min(marked_depth, (int)ancestors.size());
    if ((allow_duplicate) && (!duplicated[u]) && (should_duplicate[u])) {
        if (ancestors.size() - marked_depth <= k) {
            for (int i = marked_depth; i < ancestors.size(); i++) {
                assert(!duplicated[ancestors[i]]);
                duplicated[ancestors[i]] = 1;
                k--;
            }
            marked_depth = ancestors.size();
        }
    }
    if (r[u]) mark(r[u], duplicated[u]);
    marked_depth = min(marked_depth, (int)ancestors.size());
    ancestors.pop_back();
}

void solve() {
    cin >> n >> k >> c;
    c = '0' + c;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        p[l[i]] = p[r[i]] = i;
    }
    dfs(1);
    // for (auto&& x : order) cerr << x << '\n';
    for (int i = ((int)order.size()) - 2; i >= 0; i--) {
        if (c[order[i]] < c[order[i + 1]])
            should_duplicate[order[i]] = 1;
        else if ((c[order[i]] == c[order[i + 1]]) && should_duplicate[order[i + 1]])
            should_duplicate[order[i]] = 1;
    }
    // for (auto&& x : order) cerr << should_duplicate[x] << '\n';
    mark(1, true);
    // for (auto&& x : order) cerr << duplicated[x] << '\n';
    for (auto&& x : order) {
        cout << c[x];
        if (duplicated[x]) cout << c[x];
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}