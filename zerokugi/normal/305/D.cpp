#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
#define REP(i, n) for(int i=0;i<(int)n;i++)
#define REPS(i, n) for(int i=1;i<=(int)n;i++)
#define RREP(i, n) for(int i=n-1;i>=0;i--)
#define RREPS(i, n) for(int i=n;i>0;i--)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const int MOD = 1000000007;
int n, m, k;
ll pow2[1000002];
int f[1000002];
int main(){
	scanf("%d%d%d", &n, &m, &k);
	
	pow2[0] = 1;
	REP(i, n + 1) pow2[i+1] = pow2[i]*2%MOD;
	
	vector<int> v;
	REP(i, m){
		int u, t;
		scanf("%d%d", &u, &t);
		if(u + 1 == t) continue;
		if(u + 1 + k != t){
			cout << 0 << endl;
			return 0;
		}
		v.push_back(u-1);
		f[u-1] = 1;
	}
	sort(v.begin(), v.end());
	if(v.empty()){
		ll ans = 1;
		REP(i, n - k - 1){
			ans = (ans + pow2[min(i + k, n - k - 2) - i]) % MOD;
		}
		cout << ans << endl;
	}else if(v[0] + k + 1 <= v.back()){
		cout << 0 << endl;
	}else{
		ll ans = 1;
		REP(i, n - k - 1){
			// [i, i + k]
			if(i <= v[0] && v.back() <= i + k){
				int kk = min(k, n - i - k - 2) - (upper_bound(ALL(v), i + k) - upper_bound(ALL(v), i));
				ans = (ans + pow2[kk] - f[i]) % MOD;
			}
		}
		cout << (ans + MOD) % MOD << endl;
	}
	return 0;
}