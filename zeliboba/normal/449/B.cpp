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
typedef pair<ll, int> pil;
typedef pair<double, double> pdd;
typedef vector<string> vs;

class E {
public:
    int to;
    ll w;
    E(int to1, ll w1) {
        to = to1;
        w = w1;
    }
};

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<E> > gr(n);
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        --a; --b;
        gr[a].push_back(E(b, c));
        gr[b].push_back(E(a, c));
    }
    const int MAX = 1e15;
    vl d(n, MAX);
    vi need(n, 0);
    d[0] = 0;
    for (int i = 0; i < k; ++i) {
        int a,b;
        scanf("%d%d", &a, &b);
        --a;
        d[a] = min(d[a], (ll)b);
        need[a] = 1;
    }
    set<pil> q;
    for (int i = 0; i < n; ++i)
        q.insert(pil(d[i], i));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        if (d[v] >= MAX) continue;
        for (int i = 0; i < gr[v].size(); ++i) {
            int nx = gr[v][i].to;
            if (d[nx] >= d[v] + gr[v][i].w) {
                need[nx] = 0;
            }
            if (d[nx] > d[v] + gr[v][i].w) {
                q.erase(pil(d[nx], nx));
                d[nx] = d[v] + gr[v][i].w;
                q.insert(pil(d[nx], nx));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        k -= need[i];
    }
    cout << k << endl;
    return 0;
}