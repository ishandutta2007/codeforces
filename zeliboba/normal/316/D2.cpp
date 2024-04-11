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
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
const int mod = 1000000007;

int main() {
    vl fac(100000, 1);
    for (int i = 1; i < fac.size(); ++i)
        fac[i] = fac[i-1] * i % mod;
    int n = 500;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x == 1)
            ++a;
        else ++b;
    }
    vvl d(n + 1, vl(n + 1));
    d[0][0] = 1;
    for (int i = 0; i <= min(n,a); ++i) for (int j = 0; j <= min(b, n-i); ++j) if (i+j) {
        if (i >= 1) {
            d[i][j] += d[i-1][j];
            ll mul = 1;
            for (int l = 1; l <= j; ++l) {
                mul = mul * (j-l+1) % mod;
                d[i][j] += d[i-1][j-l] * mul % mod;
            }
            if (i >= 2) {
                ll mul = i-1;
                for (int l = 0; l <= j; ++l) {
                    d[i][j] += d[i-2][j-l] * mul % mod * (l+1) % mod;
                    mul = mul * (j-l) % mod;
                }
            }
        } else {
            ll mul = 1;
            for (int l = 0; l <= j-1; ++l) {
                d[i][j] += d[i][j-1-l] * mul % mod;
                mul = mul * (j-1-l) % mod;
            }
        }
        d[i][j] %= mod;
    }
    cout << d[a][b] << endl;
    return 0;
}