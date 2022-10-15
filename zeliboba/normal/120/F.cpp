#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

vvi gr;
vi was;

pii dfs (int v) {
    if (was[v] == -1) {
        was[v] = 0;
        pii best(-1, v);
        for (int i = 0; i < gr[v].size(); ++i) {
            best = max(best, dfs(gr[v][i]));
        }
        best.first += 1;
        return best;
    } else return pii(-3, 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, res = 0;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int n;
        cin >> n;
        gr.assign(n, vi());
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        was.assign(n, -1);
        int b1 = dfs(0).second;
        was.assign(n, -1);
        res += dfs(b1).first;
    }
    cout << res << endl;
    return 0;
}