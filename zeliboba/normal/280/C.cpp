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

vvi gr;
double res = 0;

void dfs(int v, int pr, int dep) {
    res += 1./dep;
    for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != pr) {
        dfs(gr[v][i], v, dep+1);
    }
}

int main() {
    int n;
    cin >> n;
    gr.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int a,b;
        scanf("%d%d", &a, &b);
        --a;--b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(0, -1, 1);
    printf("%.10lf\n", res);
    return 0;
}