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

int main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) a.push_back(a[i]);
    ll res = 0;    
    for (int d = 1; d < n; ++d) if (n % d == 0) {
        vi ma(d);
        vi phi(n/d + 1);
        phi[1] = 1;
        for (int i = 2; i < phi.size(); ++i) {
            phi[i] = phi[i-1];
            if (__gcd(i, n/d) == 1) ++phi[i];
        }
        for (int i = 0; i < d; ++i) for (int j = i; j < n; j += d) ma[i] = max(ma[i], a[j]);
        int cnt = 0;
        for (int i = 2*n - 1; i >= 0; --i) {
            if (a[i] < ma[i%d]) cnt = 0;
            else ++cnt;
            if (i < n) {
                res += phi[min(cnt / d, n / d)];
            }
        }
    }
    cout << res << endl;
    return 0;
}