#include <bits/stdc++.h>
#define N 100034
#define K 34
using namespace std;

typedef long long ll;
const ll mod[3] = {900000011, 998244353, 1000000007};
const ll bas[3] = {4493, 8111, 8527};

int S, T, k;
char s[N], t[N];
ll pw[3][N], Ha_s[3][N], Ha_t[3][N];
int f[N][K];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

void hash_pre(){
	int j, i;
	ll *hs, *ht, *p;
	for(j = 0; j < 3; ++j){
		hs = Ha_s[j]; hs[0] = 0;
		ht = Ha_t[j]; ht[0] = 0;
		p = pw[j]; p[0] = 1;
		for(i = 0; i < N; ++i){
			hs[i + 1] = (hs[i] * bas[j] + (s[i] - 'a')) % mod[j];
			ht[i + 1] = (ht[i] * bas[j] + (t[i] - 'a')) % mod[j];
			p[i + 1] = p[i] * bas[j] % mod[j];
		}
	}
}

inline ll getHash(ll (*Hash)[N], int id, int L, int R){ // str[L..R-1]
	ll HA = (Hash[id][R] - Hash[id][L] * pw[id][R - L]) % mod[id];
	return HA < 0 ? HA + mod[id] : HA;
}

inline bool check(int s0, int t0, int len){
	for(int j = 0; j < 3; ++j)
		if(getHash(Ha_s, j, s0, s0 + len) != getHash(Ha_t, j, t0, t0 + len))
			return false;
	return true;
}

int LCP(int s0, int t0){
	if(s[s0] != t[t0]) return 0;
	int L = 1, R = min(S - s0, T - t0), M;
	if(check(s0, t0, R)) return R;
	for(--R; L < R; ) check(s0, t0, M = (L + R + 1) >> 1) ? L = M : R = M - 1;
	return R;
}

int main(){
	int i, j, len, lcp; bool ans = false;
	scanf("%d%s%d%s%d", &S, s, &T, t, &k);
	hash_pre();
	for(i = 0; i < S; ++i)
		for(j = 0; j <= k; ++j){
			up(f[i + 1][j], len = f[i][j]);
			if(len < T && (lcp = LCP(i, len)))
				up(f[i + lcp][j + 1], len + lcp);
		}
	for(j = 0; j <= k; ++j) ans |= (f[S][j] == T);
	puts(ans ? "YES" : "NO");
	return 0;
}