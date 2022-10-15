#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 1000000007;

long long binpow(long long a, long long p){
	return p?binpow(a*a%MOD, p>>1)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a){
	return binpow(a, MOD-2);
}

void solve(int test_ind){
	int n, m, rb, cb, rd, cd, p;
	cin >> n >> m >> rb >> cb >> rd >> cd >> p;
	rb--;cb--;rd--;cd--;
	long long prob = p;
	(prob *= bininv(100)) %= MOD;
	long long ans = 0;
	long long cp = 1;
	long double ansd = ans, cpd = cp, probd = p;
	probd /= 100;
	int r, c;
	r = rb;
	c = cb;
	bool first = true;
	int dr = 1, dc = 1;
	int cnt = 0;
	if (dr + r >=n || dr + r < 0) dr *= -1;
	if (dc + c >=m || dc + c < 0) dc *= -1;
	int idr = dr, idc = dc;
	while (first || r != rb || c != cb || dr != idr || dc != idc){
		if (c == cd || r == rd){
			(ans += prob * cp % MOD * cnt % MOD) %= MOD;
			ansd += probd * cpd * cnt;
			(cp *= (1 + MOD - prob) % MOD) %= MOD;
			cpd *= 1 - probd;
		}
		first = false;
		cnt++;
		r += dr;
		c += dc;
		if (dr + r >=n || dr + r < 0) dr *= -1;
		if (dc + c >=m || dc + c < 0) dc *= -1;
	}
	// 1/2: 0
	// 1/4: 1
	// 1/8: 5
	// 1/16: 6
	// 1/32: 7
	// answer = (1-cp): ans, cp * (1-cp): ans + cnt, ... cp^k * (1-cp): ans + cnt * k
	// 1 / (1-x) =  1 + x + x^2 +...
	// 0 + x + 2x^2 + 3x^3 = x * (1 + x + x^2 + x^3+...)'
	// x / (1 - x)^2
	ans = (ans + cp * cnt % MOD) % MOD * bininv((1 + MOD - cp%MOD)%MOD) % MOD;
	ansd = (ansd + cpd * cnt) / (1 - cpd);
	printf("%lld\n", ans);
	// printf("%.13Lf\n", ansd);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}