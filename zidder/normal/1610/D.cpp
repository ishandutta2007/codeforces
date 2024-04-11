#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const long long MOD = 1000000007;

long long binpow(long long a, long long p){
	return p?binpow(a*a%MOD, p>>1) * (p&1?a:1)%MOD:1;
}

void solve(int test_ind){
	int n;
	cin >> n;
	vector<long long> a(n);
	vector<int> ps(31);
	for (int i=0;i<n;++i){
		scanf("%lld", &a[i]);
		for (int j = 30;j>=0;--j){
			if (a[i] % (1ll << j) == 0){
				ps[j]++;
				break;
			}
		}
	}
	
	long long ans = (binpow(2, ps[0]) + MOD - 1) % MOD * binpow(2, n - ps[0]) % MOD;
	n -= ps[0];
	for (int j=1;j<=30;++j){
		if (ps[j] == 0) continue;
		(ans += ((binpow(2, ps[j] - 1) + MOD - 1) % MOD) * binpow(2, n - ps[j]) % MOD) %= MOD;
		n -= ps[j];
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}