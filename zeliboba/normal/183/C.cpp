#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
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

vvi gr;
vvi grs;
vi col;
int k = 0;
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int f(int c) {
    if (k == 0)
        return c;
    return (c % k + k) % k;
}

const int MAX = 1e9;

void dfs (int v, int c) {
//    cerr << v << endl;
    if (col[v] == -MAX) {
        col[v] = c;
        for (int i = 0; i < gr[v].size(); ++i)
            dfs(gr[v][i], c + grs[v][i]);
    } else if (f(col[v]) != f(c)) {
//        cerr << v << " " << col[v] << " " << c << endl;
        k = gcd(k, abs(col[v] - c));
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    grs.resize(n);
    col.assign(n, -MAX);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        gr[a].push_back(b);
        grs[a].push_back(1);
        gr[b].push_back(a);
        grs[b].push_back(-1);
    }
    for (int i = 0; i < n; ++i) if (col[i] == -MAX)
        dfs(i, 0);
    if (k)
        cout << k << endl;
    else cout << n << endl;
    return 0;
}