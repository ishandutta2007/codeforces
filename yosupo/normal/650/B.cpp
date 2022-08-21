#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

const int MN = 500500;
int n;
ll a, b, T;
string s;


int solve() {
    ll ti[MN];
    ti[0] = 0;
    for (int i = 0; i < n; i++) {
        ti[i+1] = ti[i] + a + 1;
        if (s[i] == 'w') ti[i+1] += b;        
    }
    int ans = 0;
    ll t = T;
    for (int i = n-1; i >= 0; i--) {
        t -= 1;
        if (s[i] == 'w') t -= b;
        if (i < n-1) t -= 2*a;
        int lu = upper_bound(ti, ti+n+1, t) - ti - 1;
        if (lu < 0) break;
        ans = max(ans, lu + n - i);
    }
    return min(ans, n);
}



int main() {
    cin >> n;
    cin >> a >> b >> T;
    cin >> s;
    reverse(s.begin(), s.end());
    int ans = solve();
    reverse(s.begin(), s.end()-1);
    ans = max(ans, solve());
    cout << ans << endl;
    return 0;
}