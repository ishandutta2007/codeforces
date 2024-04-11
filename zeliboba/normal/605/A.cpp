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

vi f(vector<int> a, bool strict = true)
{
    vi res;
    int n = a.size();
    if (n == 0) 
        return res;
    vector<pair<int, int> > L(n);
    vi P(n, -1);
    int c = 1;
    L[0] = make_pair(a[0], 0);
    for (int i = 1; i < n; ++i) {
        pair<int, int> cur = make_pair(a[i], i);
        int ps = upper_bound(L.begin(), L.begin() + c, cur) - L.begin();
        if (strict && (ps > 0 && L[ps - 1].first == a[i])) 
            continue;
        if (ps > 0) 
            P[i] = L[ps - 1].second;
        L[ps] = cur;
        if (ps == c) 
            ++c;
    }
    for (int l = L[c - 1].second; l >= 0; l = P[l]) 
        res.push_back(l);
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      --a[i];
      b[a[i]] = i;
    }
    int cnt = 1, ma = 1;
    for (int i = 1; i < a.size(); ++i) {
      if (b[i] > b[i-1]) ++cnt;
      else cnt = 1;
      ma = max(ma, cnt);
    }
/*    for (int i = 1; i < a.size(); ++i) {
      if (a[i] == a[i-1] + 1) ++cnt;
      else cnt = 1;
      ma = max(ma, cnt);
    }*/
    cout << n - ma << endl;
    return 0;
}