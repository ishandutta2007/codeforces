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

char s[1005][1005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    vvi dist(2, vi(1001, 1e9));
    dist[0][0] = 0;
    vii q(1, pii(0, 0));
    int it = 0;
    while (it < q.size()) {
        pii cur = q[it];
        int d = dist[cur.first][cur.second];
        if (cur.first) {
            for (int i = 0; i < n; ++i) if (s[i][cur.second] == '#' && dist[0][i] > d + 1) {
                dist[0][i] = d + 1;
                q.push_back(pii(0, i));
            }
        } else {
            for (int j = 0; j < m; ++j) if (s[cur.second][j] == '#' && dist[1][j] > d + 1) {
                dist[1][j] = d + 1;
                q.push_back(pii(1, j));
            }
        }
        ++it;
    }
    if (dist[0][n - 1] < 1e8) {
        cout << dist[0][n - 1] << endl;
    } else cout << -1 << endl;
    return 0;
}