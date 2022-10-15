#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 1000000007;

bool in(long long a, long long b, long long d, long long n) {
	if (a < b || a > b - d + d * n) return false;
	if ((a-b) % d) return false;
	return true;
}

void solve(int test_ind){
	long long b, q, y;
	cin >> b >> q >> y;
	long long c, r, z;
	cin >> c >> r >> z;
	c -= b;
	b = 0;
	long long be = b - q + y * q, ce = c - r + r * z;
	if (ce > be || c < b || (c-b) % q != 0 || r % q != 0) {
		cout << 0 << endl;
		return;
	}
	if (!in(ce + r, b, q, y) || !in(c-r, b, q, y)) {
		cout << -1 << endl;
		return;
	}

	long long ans = 0;

	auto calc = [&](long long i){
		long long lft;
		// (c - ik) % q == 0
		lft = q / __gcd(q, i);
		(ans += lft * lft % MOD) %= MOD;
	};

	for (int i=1;i*i<=r;++i) {
		// r = lcm(q, i)
		if (r == q * i / __gcd(q, (long long)i)) {
			calc(i);
		}
		int i1 = r / i;
		if (i != i1 && r == q * i1 / __gcd(q, (long long)i1)) {
			calc(i1);
		}
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}