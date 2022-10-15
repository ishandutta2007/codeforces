#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 200005;
const int MOD = 998244353;
int fct[N];
int ST[4 * N];
int fprod = 1;

long long binpow(long long a, long long p){
	return p==0?1:binpow(a*a%MOD, p/2) * (p&1?a:1)%MOD;
}

long long bininv(long long a){
	return binpow(a, MOD-2);
}

void add(int x, int val, int l=0, int r=-1, int v=1){
	if (r == -1) r = N;
	ST[v] += val;
	if (l + 1 == r){
		if (val == 1){
			fprod = fprod * 1ll * ST[v] % MOD;
		} else {
			fprod = fprod * bininv(ST[v] + 1) % MOD;
		}
		return;
	}
	int mid = (l + r) / 2;
	if (x < mid) add(x, val, l, mid, v * 2);
	else add(x, val, mid, r, v * 2 + 1);
}

int lss(int x, int l=0, int r=-1, int v=1){
	if (r == -1) r = N;
	if (x <= l) return 0;
	if (x >= r) return ST[v];
	int mid = (l + r) / 2;
	return lss(x, l, mid, v * 2) + lss(x, mid, r, v * 2 + 1);
}

bool fnd(int x, int l=0, int r=-1, int v=1){
	if (r == -1) r = N;
	if (l + 1 == r) return ST[v];
	int mid = (l + r) / 2;
	if (x < mid) return fnd(x, l, mid, v * 2);
	else return fnd(x, mid, r, v * 2 + 1);
}

void solve(int test_ind){
	fct[0] = fct[1] = 1;
	for (int i=2;i<N;++i){
		fct[i] = fct[i-1] * 1ll * i % MOD;
	}
	int n, m;
	cin >> n >> m;
	vector<int> s(n);
	vector<int> t(m);
	for (int i=0;i<n;++i) scanf("%d", &s[i]);
	for (int i=0;i<m;++i) scanf("%d", &t[i]);
	for (int i=0;i<n;++i) add(s[i], 1);
	int ans = 0;
	for (int i=0;i<m;++i){
		if (n == 0) {
			(++ans)%=MOD;
			break;
		}

		// (n-1)! / a1! * a2! * an!
		(ans += (fct[n-1] * bininv(fprod) % MOD * lss(t[i]) % MOD)) %= MOD;
		if (!fnd(t[i])) break;
		add(t[i], -1);
		n--;
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