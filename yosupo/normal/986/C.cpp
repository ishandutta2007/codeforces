#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

const int MN = 22;
const int MSK = (1<<MN) - 1;
bool hav[1<<MN];
bool vis_single[1<<MN];
bool vis[1<<MN];

void dfs(int p);
void dfs_single(int p) {
    assert(hav[p]);
    if (vis_single[p]) return;
    vis_single[p] = true;
    dfs(MSK ^ p);
}

void dfs(int p) {
    if (vis[p]) return;
    vis[p] = true;
    if (hav[p]) dfs_single(p);
    for (int ph = 0; ph < MN; ph++) {
        if (!(p & (1<<ph))) continue;
        dfs(p ^ (1<<ph));
    }
}

int main() {
    int dummy, m;
    assert(scanf("%d %d", &dummy, &m));
    for (int i = 0; i < m; i++) {
        int x;
        assert(scanf("%d", &x));
        hav[x] = true;
    }

    int ans = 0;
    for (int i = 0; i < (1<<MN); i++) {
        if (!hav[i] || vis_single[i]) continue;
        dfs_single(i);
        ans++;
    }
    cout << ans << endl;
    return 0;
}