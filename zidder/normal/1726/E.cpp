#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 998244353;

long long binpow(long long a, long long p){
    return p?binpow(a*a%MOD, p>>1)*(p&1?a:1ll)%MOD:1;
}

long long bininv(long long a){
    return binpow(a, MOD-2);
}

const int N = 300005;

// 1, 1, 2, 4, 12, 32, 100

int fact[2*N];
int ifact[2*N];
int c[N];

void solve(int test_ind){
	int n;
    cin >> n;

    int ans = 0;
    for (int k=0;k<=n;k+=4){
        int coef = fact[n-k/2] * 1ll * ifact[k/2] % MOD * ifact[n-k] % MOD;
        ans = (ans + (coef * 1ll * fact[k/2]) % MOD * 1ll * ifact[k/4] % MOD * c[n-k] % MOD)%MOD;
    }
    cout << ans << endl;
}

int main(){
    fact[0] = 1;
    for (int i=1;i<2*N;++i) fact[i] = fact[i-1] * 1ll * i % MOD;
    for (int i=0;i<2*N;++i) ifact[i] = bininv(fact[i]);
    c[0] = 1;
    c[1] = 1;
    for (int i=1;i<N;++i) {
        c[i] = (c[i-1] + (i - 1) * 1ll * c[i-2]) % MOD;
    }
    int t;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}