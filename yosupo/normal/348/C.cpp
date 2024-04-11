#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MN = 101000;
const int MM = 101000;
const int BS = 300;
ll d[MM], e[MM];
ll a[MN];
vector<int> s[MM];
vector<int> bv;
vector<int> g[MM];
bool isBig[MM];
int main() {
    ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        if (k > BS) {
            bv.push_back(i);
            isBig[i] = true;
        }
        for (int j = 0; j < k; j++) {
            int u;
            cin >> u; u--;
            d[i]+=a[u];
            s[i].push_back(u);
        }
        sort(s[i].begin(), s[i].end());
    }
    int bs = bv.size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < bs; j++) {
            int d = bv[j];
            int u = 0;
            for (int k = 0; k < s[i].size(); k++) {
                if (binary_search(s[d].begin(), s[d].end(), s[i][k])) u++;
            }
            g[i].push_back(u);
        }
    }
    for (int i = 0; i < q; i++){
        char c; int k;
        cin >> c >> k; k--;
        if (c == '+') {
            ll x;
            cin >> x;
            for (int j = 0; j < bs; j++) {
                d[bv[j]] += x*g[k][j];
            }
            if (isBig[k]) {
                e[k] += x;
            } else {
                for (int j = 0; j < s[k].size(); j++) {
                    a[s[k][j]] += x;
                }
            }
        } else {
            if (isBig[k]) {
                cout << d[k] << endl;
            } else {
                ll r = 0;
                for (int j = 0; j < bs; j++) {
                    r += e[bv[j]]*g[k][j];
                }
                for (int j = 0; j < s[k].size(); j++) {
                    r += a[s[k][j]];
                }
                cout << r << endl;
            }
        }
    }
    return 0;
}