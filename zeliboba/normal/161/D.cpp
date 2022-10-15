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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int n, k;
ll res = 0;
vvi gr;
vi was;

vi dfs (int v, int pr) {
    if (was[v] == 0) {
        was[v] = 1;
        vi d(k + 1, 0);
        d[0] = 1;
        for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != pr) {
            vi ch = dfs(gr[v][i], v);
            for (int j = 0; j < k; ++j) {
                res += ch[j] * (ll)d[k - j - 1];
//                cerr << "add " << ch[j] << " " << d[k - j - 1] << endl;
            }
            for (int j = 0; j < k; ++j) {
                d[j + 1] += ch[j];
            }
        }
  /*      for (int i = 0; i < d.size(); ++i)
            cerr << d[i] << " ";
        cerr << endl << v << " " << res << endl;*/
        return d;
    } else {
        return vi(k + 1, 0);
    }
}

int main() {
    cin >> n >> k;
    gr.resize(n);
    was.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        gr[a - 1].push_back(b - 1);
        gr[b - 1].push_back(a - 1);
    }
    dfs(0, -1);
    cout << res << endl;
    return 0;
}