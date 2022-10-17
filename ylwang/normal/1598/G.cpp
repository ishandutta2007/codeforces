// PLEASE, COM AND HACK ME AGAIN!
#include <bits/stdc++.h>
using namespace std;

namespace PrimeJudger {
	#define int __int128
	const int Test[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	int pow(int a, int p, int mod) {
		int base = 1;
		for(; p; p >>= 1, a = a * a % mod) 
			if(p & 1) base = base * a % mod;
		return base % mod;
	}
	int Query(int P) {
		if(P == 1 || (P > 2 && P % 2 == 0) ) return 0;
		int t = P - 1, k = 0;
		while(!(t & 1)) k++, t >>= 1;
		for(int i = 0; i < 6; i++) {
			if(P == Test[i]) return 1;
			int a = pow(Test[i], t, P), nxt = a;
			for(int j = 1; j <= k; j++) {
				nxt = a * a % P;
				if(nxt == 1 && a != 1 && a != P - 1) return 0;
				a = nxt;
			}
			if(a != 1) return 0;
		}
		return 1;
	}	
	#undef int 
}
#define Isprime(P) PrimeJudger::Query(P)
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
const int N = 7e5 + 5;
int n, m; char s[N], t[N];
int z[N * 2];
void getZ(char *s, int *z, int n) {
	memset(z, 0, sizeof(n + 1)); 
	z[1] = n;
	for(int i = 2, l = 0, r = 0; i <= n; i++) {
		if(i <= r) z[i] = min(z[i - l + 1], r - i + 1);
		while(i + z[i] <= n && s[z[i] + 1] == s[i + z[i]]) z[i]++;
		if(i + z[i] - 1 > r) r = i + z[i] - 1, l = i; 
	}
}
int Rnd(int l, int r) {return rnd() % (r - l + 1) + l;}
int getPrime(int l, int r) {
	int x = Rnd(l, r);
	while(!Isprime(x))
		x = Rnd(l, r);
	return x; 
}
const int P[6] = {getPrime(1e4, 1e9), getPrime(1e12, 1e13), getPrime(1e12, 1e13), getPrime(1e12, 1e13), getPrime(1e12, 1e13), getPrime(1e13, 1e14)};
struct ele {
	int a[6]; int &operator [] (int x) { return a[x]; }
	ele(){} ele(int x) { for(int i = 0; i < 6; i++) a[i] = x; }
	ele operator + (ele b) {
		ele ans; for(int i = 0; i < 6; i++) ans[i] = (a[i] + b[i]) % P[i]; 
		return ans;
	}
	ele operator - (ele b) {
		ele ans; for(int i = 0; i < 6; i++) ans[i] = (a[i] - b[i] + P[i]) % P[i]; 
		return ans;
	}
	ele operator * (ele b) {
		ele ans; for(int i = 0; i < 6; i++) ans[i] = (__int128) a[i] * b[i] % P[i]; 
		return ans;
	}
	ele operator + (const unsigned int &b) {
		ele ans; for(int i = 0; i < 6; i++) ans[i] = (a[i] + b) % P[i]; 
		return ans;
	}
	ele operator * (const unsigned int &b) {
		ele ans; for(int i = 0; i < 6; i++) ans[i] = (__int128) a[i] * b % P[i]; 
		return ans;
	}
	bool operator == (ele b) {
		for(int i = 0; i < 6; i++) if(a[i] != b[i]) return 0;
		return 1;	
	}
}pw[N], hs[N], valx;
ele ghsh(int l, int r) {
	return hs[r] - hs[l - 1] * pw[r - l + 1];
}
void chk(int l, int r, int L, int R) {
	if(l > r || L > R || l < 1 || R > n) return;
	if(ghsh(l + m + 1, r + m + 1) + ghsh(L + m + 1, R + m + 1) == valx) {
		printf("%lld %lld\n%lld %lld\n", l, r, L, R);
		exit(0);	
	}
}
signed main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	scanf("%s", t + 1); m = strlen(t + 1);
	for(int i = 1; i <= n; i++) t[m + 1 + i] = s[i]; getZ(t, z, n + 1 + m); getZ(t, z, n + 1 + m); 
	pw[0] = ele(1); for(int i = 1; i <= n + m + 1; i++) hs[i] = hs[i - 1] * 10 + (t[i] - '0'), pw[i] = pw[i - 1] * 10; 
	valx = hs[m];	
	for(int i = m - 1; i <= n; i++) { // a is in the front
		if(i >= m) {
			int lcp = z[i - m + 1 + m + 1];
			chk(i - m + 1, i, i + 1, i + m - lcp);
			chk(i - m + 1, i, i + 1, i + m - lcp + 1);
			chk(i - m + 1, i, i + 1, i + m - lcp - 1);
		}
		chk(i - m + 2, i, i + 1, i + m - 1);
	}
	for(int i = 1; i <= n - m + 1; i++) { // b is in the front
		if(i + m - 1 <= n) {
			int lcp = z[i + m + 1];
			chk(i - m + lcp, i - 1, i, i + m - 1);
			chk(i - m + lcp + 1, i - 1, i, i + m - 1);
			chk(i - m + lcp - 1, i - 1, i, i + m - 1);
		}
		chk(i - m + 1, i - 1, i, i + m - 2);
	}
	assert(0);
	return 0;
}
/*
6724346775336763344646345654634456737536356367343567753377634557564556547345667475473663555555555555555555555555555555555555555555541
55555555555555555555555555555555555555555555

*/