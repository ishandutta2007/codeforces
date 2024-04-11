#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n, q;
const int maxn = 2e5 + 5;
typedef long long LL;
const LL mod = 998244353LL;
int p[maxn];

LL qpow(LL a, LL n){
	LL ret = 1;
	while(n > 0){
		if(n & 1){
			ret = ret * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

LL st[maxn][20];
LL pre[maxn];
LL inv[maxn];
LL pow100[maxn];

LL INV(LL val){
	return qpow(val, mod - 2);
}

LL cal(int l, int r){
	LL ret1 = pow100[r - l] % mod;
	LL ret2 = inv[r - 1] * pre[l - 1] % mod;
	return ret1 * ret2 % mod;
}	
	
void init(){
	for(int i = 1;i <= n;i++){
		st[i][0] = 100 * INV(p[i]) % mod;
	}	
	for(int j = 1; (1 << j) <= n;j++){
		for(int i = 1;i + (1 << j) - 1 <= n;i++){
			int len = (1 << j);
			int halflen = len / 2;
			int l = i, mid = i + halflen, r = i + len;
			st[i][j] = cal(mid, r) * st[i][j - 1] + st[mid][j - 1];
			st[i][j] %= mod;
		}
	}
}

LL sum(int l, int r){
	int len = r - l;
	LL ans = 0;
	for(int i = 0;i < 20;i++){
		if(len & (1 << i)){
			int mid = l + (1 << i);
			ans = cal(l, mid) * ans + st[l][i];
			ans = ans % mod;
			l = mid;
		}
	}
	return ans;
}


int main(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		scanf("%d", &p[i]);
	}
	pre[0] = 1;
	pow100[0] = 1;
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i - 1] * p[i] % mod;
		inv[i] = INV(pre[i]);
		pow100[i] = pow100[i - 1] * 100 % mod;
	}
	init();
	LL ans = sum(1, n + 1);
	set<int> s;
	s.insert(1);
	s.insert(n + 1);
	for(int i = 1;i <= q;i++){
		int u;
		scanf("%d", &u);
		if(s.count(u)){
			auto r = s.upper_bound(u);
			auto l = s.lower_bound(u);
			l--;
			ans = (ans - sum(*l, u) + mod - sum(u, *r) + sum(*l, *r) + mod) % mod;
			s.erase(u);
		}else{
			auto r = s.upper_bound(u);
			auto l = r;
			l--;
			ans = (ans + sum(*l, u) + sum(u, *r) - sum(*l, *r) + mod) % mod;
			s.insert(u);
		}
		cout << ans << endl;
	}	
	return 0;	
}