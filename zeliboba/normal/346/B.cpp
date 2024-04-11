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

short d[101][101][101];
int prev[101][101][101];
bool take[101][101][101];

int main() {
    string a,b,c;
    cin >> a >> b >> c;
    vi was(256);
    for (int i = 0; i < c.size(); ++i) was[c[i]] = 1;
    vvi sc(c.size(), vi(256));
    for (int i = 0; i < sc.size(); ++i) {
        for (int j = 0; j < 256; ++j) {
            if (!was[j]) {
                sc[i][j] = 0;
            } else {
                for (int l = i+1; l > 0; --l) if (c[l-1] == j) {
                    bool ok = 1;
                    for (int t = l - 2; t >= 0; --t) if (c[t] != c[i+1-l+t]) {
                        ok = 0;
                        break;
                    }
                    if (ok) {
                        sc[i][j] = l;
                        break;
                    }
                }
            }
        }
    }
//    cout << sc[0]['q'] << ' ' << sc[1]['q'] << ' ' << sc[2]['q'] << endl;
    memset(d, 0, sizeof(d));
    memset(prev, 0, sizeof(prev));
    memset(take, 0, sizeof(take));
    for (int i = 0; i <= a.size(); ++i) for (int j = 0; j <= b.size(); ++j) {
        for (int l = 0; l < c.size(); ++l) {
            if (i + 1 <= a.size()) {
                if (d[i+1][j][l] < d[i][j][l]) {
                    d[i+1][j][l] = d[i][j][l];
                    prev[i+1][j][l] = i*101*101+j*101+l;
                    take[i+1][j][l] = 0;
                }
            }
            if (j + 1 <= b.size()) {
                if (d[i][j+1][l] < d[i][j][l]) {
                    d[i][j+1][l] = d[i][j][l];
                    prev[i][j+1][l] = i*101*101+j*101+l;
                    take[i][j+1][l] = 0;
                }
            }
            if (i + 1 <= a.size() && j + 1 <= b.size() && a[i] == b[j]) {
                int r = sc[l][a[i]];
                if (r < c.size() && d[i+1][j+1][r] < d[i][j][l] + 1) {
                    d[i+1][j+1][r] = d[i][j][l] + 1;
                    prev[i+1][j+1][r] = i*101*101+j*101+l;
                    take[i+1][j+1][r] = 1;
                }
            }
        }
    }
    int ma = 0, best = 0;
    for (int i = 0; i < c.size(); ++i) {
        if (d[a.size()][b.size()][i] > ma) {
            ma = d[a.size()][b.size()][i];
            best = i;
        }
    }
    string res = "";
    int i = a.size(), j = b.size(), l = best;
    while (d[i][j][l]) {
//        cerr << i << ' ' << j << endl;
        if (take[i][j][l]) {
            res += a[i-1];
        }
        int t = prev[i][j][l];
        l = t % 101;
        j = (t / 101) % 101;
        i = t / 101 / 101;
    }
    reverse(res.begin(), res.end());
    if (res.empty()) {
        cout << 0 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}