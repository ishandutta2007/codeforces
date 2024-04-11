#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <complex>
using namespace std;

typedef long long ll;

const int MN = 20;
const int MS = 1<<MN;
const ll MD = 1e9+7;
int d[MS] = {};
ll f[MS*2] = {};
int main() {
    f[0] = 1;
    for (int i = 1; i < MS*2; i++) {
        f[i] = f[i-1]*2%MD;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        d[u]++;
    }
    for (int i = 0; i < MN; i++) {
        for (int j = 0; j < MS; j++) {
            if (!(j&(1<<i))) {
                d[j]+=d[j|(1<<i)];
            }
        }
    }
    ll res = 0;
    for (int i = 0; i < MS; i++) {
        int u = (__builtin_popcount(i)%2) ? -1 : 1;
        res += u*f[d[i]];
        res %= MD;
    }
    res = (res%MD+MD)%MD;
    cout << res << endl;
    return 0;
}