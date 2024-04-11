#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

const int N = 2006;
ll dp[N];
ll tmp[N];

int main () {
    int n,m,k;
    cin >> n >> m >> k;
    for (int i=1;i<=n;++i) {
        if (i == 1) {
            dp[0] = m;
        }
        else {
            for (int j=0;j<N;++j) {
                tmp[j] = 0;
            }
            for (int j=0;j<=k;++j) {
                tmp[j] += dp[j]*(1);
                tmp[j+1] += dp[j]*(m-1);
            }
            for (int j=0;j<N;++j) {
                dp[j] = tmp[j]%mod;
            }
        }
    }
    cout << dp[k] << endl;
}