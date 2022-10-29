#include <bits/stdc++.h>
using namespace std;

const int N = 2006;

vector<int> G[N];
int ans[N];
int cnt[N];
int sz[N];

vector<int> sons;

void dfs1(int now) {
    sons.push_back(now);
    for (int i: G[now]) {
        dfs1(i);
    }
}

void dfs(int now) {
    //cout << "now = " << now << endl;
    sz[now] = 1;
    for (int i: G[now]) {
        dfs(i);
        sz[now] += sz[i];
    }
    if (sz[now] - 1 < cnt[now]) {
        puts("NO");
        exit(0);
    }
    if (sz[now] == 1) {
        ans[now] = 1;
        return;
    }
    sons.clear();
    for (int i: G[now]) {
        dfs1(i);
    }
    vector<int> v = sons;
    sort(v.begin(), v.end(), [](const int &x, const int &y) {
        return ans[x] < ans[y];
    });
    int pre = 0;
    int sz = (int)v.size();
    int ptr = 1;
    for (int i = 0; i < sz; ++i) {
        if (pre == cnt[now]) {
            ans[now] = (++ptr);
        }
        ans[ v[i] ] = (++ptr);
        ++pre;
    }
    if (pre == cnt[now]) {
        ans[now] = (++ptr);
    }
    //cout << "now = " << now << " , ptr = " << ptr << endl;
}

int main () {
    int n; scanf("%d", &n);
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        if (x == 0) {
            root = i;
        }
        else {
            G[x].push_back(i);
        }
        cnt[i] = y;
    }
    dfs(root);
    puts("YES");
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", ans[i], " \n"[i == n]);
    }
}