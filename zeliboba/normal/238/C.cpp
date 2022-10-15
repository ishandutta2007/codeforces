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
#include <complex>
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

vvi gr, cost;
vi resd, resu;

void dfsd(int v, int pr, int forb) {
    if (resd[v] == -1) {
        resd[v] = 0;
        for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != forb && gr[v][i] != pr) {
            dfsd(gr[v][i], v, forb);
            resd[v] += resd[gr[v][i]] + cost[v][i];
        }
    }
}

void dfsu(int v, int forb, int pr, int c, int &mi) {
    if (resu[v] == -1) {
        resu[v] = resd[v];
        if (pr != -1)
            resu[v] = resu[pr] + 1 - 2 * c;
        mi = min(mi, resu[v]);
        for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != forb && gr[v][i] != pr) {
            dfsu(gr[v][i], forb, v, cost[v][i], mi);
        }
    }
}

void out(const vi &v) {
    for (int i = 0; i < v.size(); ++i)
        cerr << v[i] << " ";
    cerr << endl;
}

int main() {
    int n;
    cin >> n;
    gr.resize(n);
    cost.resize(n);
    vii e(n-1);
    for (int i = 0; i < n - 1; ++i) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        e[i] = pii(a, b);
        gr[a].push_back(b);
        gr[b].push_back(a);
        cost[a].push_back(0);
        cost[b].push_back(1);
    }
    int mi = n - 1;
    for (int l = 0; l < n - 1; ++l) {
        resd.assign(n, -1);
        resu.assign(n, -1);
        int mi1 = n - 1;
        int mi2 = n - 1;
        dfsd(e[l].first, -1, e[l].second);
        dfsd(e[l].second, -1, e[l].first);
//        out (resd);
        dfsu(e[l].first, e[l].second, -1, 0, mi1);
        dfsu(e[l].second, e[l].first, -1, 0, mi2);
//        out (resu);
//        cerr << mi1 << " " << mi2 << endl;
        mi = min(mi, mi1 + mi2);
    }
    cout << mi << endl;
    return 0;
}