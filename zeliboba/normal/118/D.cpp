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
#include <memory.h>
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

const int mod = 100000000;

int d(int x) {
    if (x < mod)
        return x;
    else return x - mod;
}

int res[201][101][101][2];
int main() {
    int kk[2], nn[2];
    cin >> nn[0] >> nn[1] >> kk[0] >> kk[1];
    memset(res, 0, sizeof(res));
    res[0][0][0][0] = 1;
    int sub[2];
    for (int i = 1; i <= nn[0] + nn[1]; ++i) {
        for (int n = 0; n <= min(nn[0], i - 1); ++n) for (int last = 0; last < 2; ++last) for (int newlast = 0; newlast < 2; ++newlast) for (int k = 0; k < 11; ++k) {
            sub[newlast] = 1;
            sub[1 - newlast] = 0;
            if (last == newlast) {
                if (k + 1 <= kk[last] && n + sub[0] <= nn[0] && (i - n - sub[0]) <= nn[1]) {
                    //assert(i << n + sub[0] << " " << k + 1 << " " << newlast << endl;
                    res[i][n + sub[0]][k + 1][newlast] = d(res[i][n + sub[0]][k + 1][newlast] + res[i - 1][n][k][last]);
                    //cerr << i - 1 << " " << n << " " << k << " " << last << endl << endl;
                }
            } else {
                if (n + sub[0] <= nn[0] && (i - n - sub[0]) <= nn[1]) {
//                    cerr << "daf\n";
//                    cerr << i << " " << n + sub[0] << " " << 1 << " " << newlast << endl;
//                    cout << res[i][n + sub[0]][1][newlast] << " " << res[i - 1][n][k][last] << endl;
                    res[i][n + sub[0]][1][newlast] = d(res[i][n + sub[0]][1][newlast] + res[i - 1][n][k][last]);
//                    cerr << res[i][n + sub[0]][1][newlast] << endl;
//                    cerr << res[1][0][1][1] << endl;
//                    cerr << i - 1 << " " << n << " " << k << " " << last << endl << endl;
                }
            }
        }
    }
//    cerr << res[3][2][1][0] << endl;
//    cerr << res[4][2][1][1] << endl;
//    cerr << res[5][2][1][0] << " " << res[5][2][1][1] << " " << res[5][2][2][1] << endl;
    int sum = 0;
    for (int last = 0; last < 2; ++last) for (int k = 0; k < 11; ++k)
        sum = d(sum + res[nn[0] + nn[1]][nn[0]][k][last]);
    cout << sum << endl;
    return 0;
}