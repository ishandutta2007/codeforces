#include <bits/stdc++.h>
using namespace std;

const int N = 1006;

set<int> G[N];

int ask(int a, int b, bool gao = false) {
    cout << "? " << a << ' ' << b << endl;
    int ret; cin >> ret;
    if (ret == a) {
        cout << "! " << a << endl;
        exit(0);
    }
    if (ret == b) {
        cout << "! " << b << endl;
        exit(0);
    }
    if (gao || G[ret].size() == 2) {
        cout << "! " << ret << endl;
        exit(0);
    }
    return ret;
}

int tar1, tar2, root;
bool vis[N];

vector<int> dels;

bool dfs(int now) {
    bool ret = false;
    if (now == tar1 || now == tar2) {
        ret = true;
    }
    vis[now] = true;
    for (int i: G[now]) {
        if (!vis[i]) {
            bool gao = dfs(i);
            if (gao) {
                if (now == root) {
                    dels.push_back(i);
                }
                ret = true;
            }
        }
    }
    return ret;
}

void byebye(int now) {
    vis[now] = true;
    for (int i: G[now]) {
        if (i == root || vis[i]) continue;
        byebye(i);
    }
    G[now].clear();
}

int main () {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        G[x].insert(y);
        G[y].insert(x);
    }
    while (true) {
        vector<int> deg1;
        for (int i = 1; i <= n; ++i) {
            if (G[i].size() == 1) {
                deg1.push_back(i);
            }
        }
        if ((int)deg1.size() == 2) {
            ask(deg1[0], deg1[1], true);
        }
        int u = deg1[0], v = deg1[1];
        int lca = ask(u, v);
        tar1 = u, tar2 = v;
        memset(vis, 0, sizeof(vis));
        root = lca;
        dels.clear();
        dfs(lca);
        memset(vis, 0, sizeof(vis));
        vis[root] = true;
        for (int i: dels) {
            byebye(i);
            G[root].erase(i);
        }
    }
}