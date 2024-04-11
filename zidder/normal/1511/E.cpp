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

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (int i=0;i<n;++i) cin >> v[i];
	vector<int> val(n + m);
	int i2 = bininv(2);
	val[0] = val[1] = 0;
	for (int i=2;i<val.size();++i) {
		long long vl = i2 * 1ll * val[i-1] % MOD;
		(vl += i2 * 1ll * i2 % MOD * val[i-2] % MOD) %= MOD;
		(vl += i2 * 1ll * i2 % MOD * (val[i-2]+1) % MOD) %= MOD;
		val[i] = vl;
	}

	int cnt = 0;
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) cnt += v[i][j] == 'o';
	long long pw = binpow(2, cnt);

	long long ans = 0;
	for (int i=0;i<n;++i){
		int c = 0;
		for (int j=0;j<m;++j) {
			if (v[i][j] == 'o') c++;
			else {
				ans = (ans + val[c]) % MOD;
				c = 0;
			}
		}
		ans = (ans + val[c]) % MOD;
	}
	for (int j=0;j<m;++j){
		int c = 0;
		for (int i=0;i<n;++i) {
			if (v[i][j] == 'o') c++;
			else {
				ans = (ans + val[c]) % MOD;
				c = 0;
			}
		}
		ans = (ans + val[c]) % MOD;
	}
	cout << ans * pw % MOD << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}