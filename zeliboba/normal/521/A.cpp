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
const int mod = 1000000007;

ll mpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vi v(4);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') ++v[0];
        else if (s[i] == 'C') ++v[1];
        else if (s[i] == 'G') ++v[2];
        else ++v[3];
    }
    sort(v.begin(), v.end());
    int c = 1;
    for (int i = 2; i >= 0; --i) if (v[i] == v[3]) ++c;
    cout << mpow(c, n) << endl;
    return 0;
}