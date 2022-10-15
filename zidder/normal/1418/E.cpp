// https://codeforces.com/problemset/problem/1418/E

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 998244353;

long long binpow(long long a, long long p){
    return p?binpow(a*a%MOD, p>>1)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a){
    return binpow(a, MOD-2);
}

void solve(int test_ind){
	int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for (int i=0;i<n;++i) scanf("%d", &d[i]);
    sort(d.begin(), d.end());
    vector<long long> psum(n+1);
    for (int i=0;i<n;++i) (psum[i+1] = psum[i] + d[i]) %= MOD;
    set<pair<long long, int> > ds;
    for (int i=0;i<n;++i) ds.emplace(d[i], i);

    for (int i=0;i<m;++i){
        int a, b;
        scanf("%d%d", &a, &b);
        auto it = ds.upper_bound({b, -1});
        int c;
        if (it == ds.end()) c = 0;
        else c = n - it->second;
        long long ans = 0;
        if (c >= a) {
            (ans += (MOD - psum[it->second] + psum[n]) % MOD * (c-a) % MOD * bininv(c) % MOD) %= MOD;
            // c - a + 1  / c+1
            (ans += psum[it->second] * (c-a+1) % MOD * bininv(c+1) % MOD) %= MOD;
        }
        printf("%lld\n", ans);
    }
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}