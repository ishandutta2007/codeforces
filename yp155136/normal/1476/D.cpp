#include <bits/stdc++.h>
using namespace std;

const int N = 300006;
const int NN = 2 * N;

struct DJS {
    int p[NN];
    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            p[i] = i;
        }
    }
    int Find(int x) {
        return p[x] == x ? x : p[x] = Find(p[x]);
    }
    void Union(int x, int y) {
        p[ Find(x) ] = Find(y);
    }
} djs;

set<int> st[NN];

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        s = " " + s;
        djs.init(2 * n + 2);
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'L') {
                djs.Union(i + 1, i + (n + 1));
                djs.Union(i + (n + 1), i + 1);
            }
            else {
                djs.Union(i, (i + 1) + (n + 1));
                djs.Union((i + 1) + (n + 1), i);
            }
        }
        for (int i = 1; i <= 2 * (n + 1); ++i) {
            st[i].clear();
        }
        for (int i = 1; i <= 2 * (n + 1); ++i) {
            st[ djs.Find(i) ].insert(i % (n + 1));
        }
        for (int i = 1; i <= n + 1; ++i) {
            cout << st[djs.Find(i)].size() << " \n"[i == n + 1];
        }
    }
}