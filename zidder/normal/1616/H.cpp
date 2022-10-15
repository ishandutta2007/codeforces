#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const long long MOD = 998244353;

long long binpow(long long a, long long p){
	return p?binpow(a*a%MOD, p>>1)*(p&1?a:1)%MOD:1;
}

struct Node{
	int l=0;
	int r=0;
	int c=0;
	Node(int l=0, int r=0, int c=0):l(l), r(r), c(c){}
} T[31 * 150000 + 10];

int tind = 2;

void add(int a){
	int ind = 1;
	for (int i=30;i>=0;--i){
		T[ind].c++;
		if (a & (1 << i)){
			if (T[ind].r == 0){
				T[ind].r = tind++;
			}
			ind = T[ind].r;
		} else {
			if (T[ind].l == 0){
				T[ind].l = tind++;
			}
			ind = T[ind].l;
		}
	}
	T[ind].c++;
}

inline long long f(long long c1, long long c2){
	return (binpow(2, c1 + c2) - binpow(2, c1) - binpow(2, c2) + 2 * MOD + 1) % MOD;
}

long long slv2(int x, int ind1, int ind2, int p){
	long long ans = 0;
	if (p == -1) {
		// cout << "-1:" << (ind1==ind2) << " " << T[ind1].c << " " << T[ind2].c << " " << ans << endl;
		if (ind1 != ind2) (ans += f(T[ind1].c, T[ind2].c)) %= MOD;
		else (ans += binpow(2, T[ind1].c) + MOD - 1) %= MOD;
		// cout << ans << endl;
		return ans % MOD;
	}
	if ((x&(1<<p))>0){
		// cout << p << " 1: " << (ind1==ind2) << " " << T[ind1].c << " " << T[ind2].c << " " << ans << endl;
		if (ind1 != ind2){
			if (T[ind1].l && T[ind2].l) (ans += f(T[T[ind1].l].c, T[T[ind2].l].c)) %= MOD;
			if (T[ind1].r && T[ind2].r) (ans += f(T[T[ind1].r].c, T[T[ind2].r].c)) %= MOD;
		} else {
			if (T[ind1].l) (ans += binpow(2, T[T[ind1].l].c) + MOD - 1) %= MOD;
			if (T[ind1].r) (ans += binpow(2, T[T[ind1].r].c) + MOD - 1) %= MOD;
		}
		// cout << ans << endl;
		if (ind1 == ind2){
			if (T[ind1].l && T[ind2].r) (ans += slv2(x, T[ind1].l, T[ind2].r, p-1)) %= MOD;
		} else {
			long long v1=0, v2=0;
			if (T[ind1].l && T[ind2].r) v1 = slv2(x, T[ind1].l, T[ind2].r, p-1);
			if (T[ind1].r && T[ind2].l) v2 = slv2(x, T[ind1].r, T[ind2].l, p-1);
			(ans += v1 * ((binpow(2, T[T[ind1].r].c) + binpow(2, T[T[ind2].l].c) + MOD - 1) % MOD) % MOD) %= MOD;
			(ans += v2 * ((binpow(2, T[T[ind1].l].c) + binpow(2, T[T[ind2].r].c) + MOD - 1) % MOD) % MOD) %= MOD;
			(ans += v1 * v2 % MOD) %= MOD;
		}
	} else {
		// cout << p << " 0: " << (ind1==ind2) << " " << T[ind1].c << " " << T[ind2].c << endl;
		if (T[ind1].l && T[ind2].l) (ans += slv2(x, T[ind1].l, T[ind2].l, p-1)) %= MOD;
		if (T[ind1].r && T[ind2].r) (ans += slv2(x, T[ind1].r, T[ind2].r, p-1)) %= MOD;
	}
	return ans % MOD;
}

void slv(int x, int ti, int ind, int p=30){
	if (p >= ti){
		if (T[ind].l) slv(x, ti, T[ind].l, p-1);
		if (T[ind].r) slv(x, ti, T[ind].r, p-1);
		return;
	}
	slv2(x, ind, ind, p);
}

void solve(int test_ind){
	// 0: 0^0 or 1^1 maybe
	// 1: 0^0 or 1^1 for sure or 0^1 or 1^0 maybe
	int n, x;
	cin >> n >> x;
	for (int i=0;i<n;++i){
		int a;
		scanf("%d", &a);
		add(a);
	}

	long long ans = slv2(x, 1, 1, 30);
	cout << ans << endl;
	// int ti=30;
	// for (ti=30;ti>=0;--ti){
	// 	if (x&(1<<ti)) break;
	// }
	// ++ti;
	// ans = 0;
	// slv(x, ti, 1);
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}