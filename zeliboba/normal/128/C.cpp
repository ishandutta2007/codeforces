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
#include <memory.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

const ll mod = 1000000007;
int res[1001][1001];

int main() {
    memset(res, 0, sizeof(res));
    for (int i = 1; i < 1001; ++i)
        res[i][0] = 1;
    for (int k = 1; k <= 1000; ++k) {
        ll s = 0;
        for (int i = k + 1; i < 1001; ++i) {
            s = (s + res[i - 2][k - 1]) % mod;
            res[i][k] = (res[i - 1][k] + s) % mod;
        }
    }
    int n, m, k;
    cin >> n >> m >> k;
    cout << (res[n][k] * (ll)res[m][k]) % mod << endl;
    return 0;
}