#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 998244353;

long long binpow(long long a, long long p) {
    return p?binpow(a*a%MOD, p>>1)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a){
    return binpow(a, MOD-2);
}

vector<vector<int> > coefs(2001, vector<int>(2001));

void solve(int test_ind){
	int n, m, k;
    cin >> n >> m >> k;
    if (m == 1){
        cout << binpow(n, k) << endl;
        return;
    }
    int c = binpow(m/2, n);
    int x = ((m+1)/2) * bininv(m/2) % MOD;
    int p = binpow(1+x, n);
    int ans = 0;
    for (int i=1;i<=k;++i){
        // cout << i << " " << coefs[k][i] << endl;
        p = p * 1ll * (n-i+1) % MOD;
        p = p * 1ll * x % MOD;
        p = p * bininv(1 + x) % MOD;
        // if (p) cout << i << " " << p << endl;
        ans = (ans + coefs[k][i] * 1ll * p) % MOD;
    }
    cout << ans * 1ll * c % MOD << endl;
}

int main(){
    coefs[0][0] = 1;
    for (int i=1;i<=2000;++i){
        for (int j=1;j<=2000;++j){
            coefs[i][j] = (coefs[i-1][j] * 1ll * j + coefs[i-1][j-1]) % MOD; // * n! / (n-j)!
        }
    }


	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}