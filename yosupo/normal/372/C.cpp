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
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll MN = 150500;
const int MM = 310;
int dp[MM][MN]; 
int deq[MN*2];
int main() {
    int n, m, d;
    cin >> n >> m >> d;
    ll res = 0;
    ll bt = -MN;
    vector<P> v;
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        res += b;
        v.push_back(P(a, t));
    }
    for (int i = 0; i < m; i++) {
        P p = v[i];
        ll a = p.first, tt = p.second;
        int t = min(MN, (tt-bt)*d);
        bt = tt;
        int l = 0, r = 0;
        for (int j = 0; j < t; j++) {
            while (l < r && dp[i][deq[r-1]] >= dp[i][j]) r--;
            deq[r] = j; r++;
        }
        for (int j = 0; j < MN; j++) {
            if (j+t < MN) {
                while (l < r && dp[i][deq[r-1]] >= dp[i][j+t]) r--;
                deq[r] = j+t; r++;
            }
            while (deq[l] < j-t) l++;
            dp[i+1][j] = abs(j-a)+dp[i][deq[l]];
        }
    }
    int u = MN*MM*2;
    for (int i = 0; i < MN; i++) {
        u = min(u, dp[m][i]);
    }
    cout << res-u << endl;
    return 0;
}