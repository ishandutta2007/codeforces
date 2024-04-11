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

char s[505][505];
char s1[505][505];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[n - i - 1]);
        for (int j = 0; j < m; ++j) {
            if (s[n - i - 1][j] == '*')
                s[n - i - 1][j] = 1;
            else s[n - i - 1][j] = 0;
        }
    }
    ll res = 0;
    for (int i = 0; i < n; ++i)
        memcpy(s1[i], s[i], m + 1);
    for (int mask = 0; mask < 16; ++mask) {
        for (int i = 0; i < n; ++i)
            memcpy(s[i], s1[i], m + 1);
        char sh[2][2];
        for (int t1 = 0; t1 < 2; ++t1) for (int t2 = 0; t2 < 2; ++t2) {
            sh[t1][t2] = 0;
            if ((mask & (1 << (2 * t1 + t2))))
                sh[t1][t2] = 1;
        }
        for (int l = 1; l <= min(n, m); l *= 2) {
    /*        if (l == 2) {
                cerr << (int)s[2][9] << " " << (int)s[4][9] << " " << endl;
                cerr << (int)s[2][7] << " " << (int)s[4][7] << " " << endl;
            }*/
            for (int i = 0; i <= n - l; ++i) for (int j = 0; j <= m - l; ++j) {
    //            cerr << l << " " << i << " " << j << endl;
    //            if (l == 2)
    //                cerr << (int)s[4][9] << endl;
                if (l >= 4 && (s[i][j] == 0 || mask == 15 && s[i][j] == 1)) {
//                    cerr << l << " " << i << " " << j << endl;
                    ++res;
                }
                if (i >= l && j >= l) {
/*                    if (mask == 8) {
                        cerr << l << " " << i - l << " " << j - l << endl;
                        cerr << (int)s[i][j - l] << " " << (int)s[i][j] << " " << endl;
                        cerr << (int)s[i - l][j - l] << " " << (int)s[i - l][j] << " " << endl;
                    }*/
                    if (s[i][j] == 1 && s[i - l][j - l] == 1 && s[i][j - l] == 1 && s[i - l][j] == 1) {
                        s[i - l][j - l] = 1;
                    } else if (s[i - l][j - l] == sh[0][0] && s[i][j - l] == sh[1][0] && s[i - l][j] == sh[0][1] && s[i][j] == sh[1][1]) {
                        s[i - l][j - l] = 0;
                    } else s[i - l][j - l] = 2;
//                    if (mask == 8)
//                        cerr << l << " " << i - l << " " << j - l << " " << (int)s[i - l][j - l] << endl;
                } 
            }
        }
    }
    cout << res << endl;
    return 0;
}