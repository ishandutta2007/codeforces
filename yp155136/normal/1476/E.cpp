#include <bits/stdc++.h>
using namespace std;

const int N = 100006;

vector<int> G[N];
int deg[N];

void add_edge(int from, int to) {
    ++deg[to];
    G[from].push_back(to);
}

string p[N];

bool is_match(string a, string b) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == '_' || b[i] == '_') continue;
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    map<string, int> mp;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        mp[ p[i] ] = i;
    }
    for (int i = 1; i <= m; ++i) {
        string s; int x; cin >> s >> x;
        if (!is_match(s, p[x])) {
            cout << "NO" << endl;
            return 0;
        }
        for (int mask = 0; mask < (1 << k); ++mask) {
            string tmp = s;
            for (int j = 0; j < k; ++j) {
                if (((1 << j) & mask) != 0) {
                    tmp[j] = '_';
                }
            }
            if (tmp == p[x]) continue;
            auto iter = mp.find(tmp);
            if (iter == mp.end()) continue;
            add_edge(x, iter->second);
        }
    }
    queue<int> que;
    vector<int> sol;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) que.push(i);
    }
    while (!que.empty()) {
        int t = que.front(); que.pop();
        sol.push_back(t);
        for (int i: G[t]) {
            --deg[i];
            if (deg[i] == 0) que.push(i);
        }
    }
    if (sol.size() == n) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << sol[i] << " \n"[i == n - 1];
        }
    }
    else {
        cout << "NO" << endl;
    }
}