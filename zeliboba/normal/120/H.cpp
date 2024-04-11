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
    
vector<string> add;
map<string, int> id;
vvi gr;
vi was;
vi path;
string small;
int n;

void rec(const string &s, int it, int k, int cur) {
    if (it < s.size() && k) {
        rec(s, it + 1, k, cur);
        small += s[it];
        if (id.count(small) == 0) {
            id[small] = add.size();
            add.push_back(small);
        }
        gr[cur].push_back(n + id[small]);
        rec(s, it + 1, k - 1, cur);
        small.erase(small.size() - 1);
    }
}

bool dfs (int v) {
    if (!was[v]) {
        was[v] = 1;
        for (int i = 0; i < gr[v].size(); ++i) {
            int next = gr[v][i];
            if (path[next] == -1 || dfs(path[next])) {
                path[next] = v;
                path[v] = next;
                return 1;
            }
        }
    } 
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    vector<string> vs(n);
    gr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> vs[i];
        rec(vs[i], 0, 4, i);
    }
/*    for (int i = 0; i < n; ++i) {
        cerr << vs[i] << endl;
        for (int j = 0; j < gr[i].size(); ++j)
            cerr << add[gr[i][j]] << " ";
        cerr << endl;
    }*/
//    gr.resize();
    int cnt = 0;
    path.assign(n + add.size(), -1);
    for (int i = 0; i < n; ++i) {
        was.assign(n + add.size(), 0);
        cnt += (int)dfs(i);
    }
    if (cnt < n) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < n; ++i)
            cout << add[path[i] - n] << endl;
    }
    return 0;
}