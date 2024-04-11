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

int n;
int f (const string &s, const string &t) {
    int l = 0, r = 0;
    while (l < n && s[l] == t[l]) ++l;
    while (r < n && s[n-r-1] == t[n-r-1]) ++r;
    while (l + 1 < n && s[l] == t[l+1]) ++l;
    if (l + r >= n-1) return 1;
    else return 0;
}

int main() {
    string s,t;
    cin >> n >> s >> t;
    int res = f(s, t) + f(t, s);
    cout << res << endl;
    return 0;
}