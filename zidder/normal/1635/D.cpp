#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 1000000007;

const int N = 200005;
int ans[N];


int slv(int x) {
	int c = 0;
	while (x) {
		x /= 2;
		c++;
	}
	// a + b <= p
	// a = 0 to p
	// b = 0 to [(p - a) / 2]
	// SUM C[a+b][a]
	// fibo
	return ans[c];
}

void solve(int test_ind){
	int n;
	int p;
	cin >> n >> p;
	ans[p + 1] = 0;
	for (int i=p;i>=0;--i){
		(ans[i] = (1 + ans[i+1] + ans[i+2])) %= MOD;
	}
	vector<long long> a(n);
	for (int i=0;i<n;++i) scanf("%lld", &a[i]);
	sort(a.begin(), a.end());

	set<long long> b;
	
	auto insrt = [&](long long x){
		int y = x;
		while (y) {
			if (y % 2 == 1) {
				y /= 2;
				if (b.count(y)) return;
				continue;
			}
			if (y % 4 == 0) {
				y /= 4;
				if (b.count(y)) return;
				continue;
			}
			break;
		} 
		b.insert(x);
	};
	for (long long i: a) insrt(i);
	int ans = 0;
	for (long long i: b) {
		(ans += slv(i)) %= MOD;
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