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
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

const int M = 200000;
vector<int> gr[2*M + 1];
vector<int> gre[2*M + 1];

vi euler(const vii & edges, int n) {
    for (int i = 0; i < edges.size(); ++i) {
        int a = edges[i].first, b = edges[i].second;
        gr[a].push_back(b);
        gr[b].push_back(a);
        gre[a].push_back(i);
        gre[b].push_back(i);
    }
    vi res;
    vi used(edges.size());
    vi it(n);
    vi was(n);
    for (int first = 0; first < n; ++first) if (!was[first]) {
        stack<int> st, ste;
        st.push (first);
        ste.push (-1);
        while (!st.empty())
        {
            int v = st.top();
            for (; it[v] < gr[v].size(); ++it[v])
                if (used[gre[v][it[v]]] == 0)
                    break;
            if (it[v] == gr[v].size())
            {
                if (ste.top() != -1) res.push_back (ste.top());
                ste.pop();
                st.pop();
            }
            else
            {
                used[gre[v][it[v]]] = 1;
                st.push (gr[v][it[v]]);
                ste.push (gre[v][it[v]]);
                was[gr[v][it[v]]] = 1;
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vi x(n), y(n), cntx(M), cnty(M);
    vii edges;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        --x[i]; --y[i];
        edges.emplace_back(x[i], y[i] + M);
        ++cntx[x[i]];
        ++cnty[y[i]];
    }
    vi oddx, oddy;
    for (int i = 0; i < M; ++i) {
        if (cntx[i] % 2) oddx.push_back(i);
        if (cnty[i] % 2) oddy.push_back(i + M);
    }
    if (oddx.size() > oddy.size()) oddx.swap(oddy);
    for (int i = 0; i < oddx.size(); ++i) edges.emplace_back(oddx[i], oddy[i]);
    for (int i = oddx.size(); i < oddy.size(); ++i) edges.emplace_back(oddy[i], 2*M);
    vi v = euler(edges, 2*M);
    string res(n, 'a');
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < n) res[v[i]] = (i % 2) ? 'b' : 'r';
    }
    cout << res << endl;
    return 0;
}