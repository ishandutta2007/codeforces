#include <bits/stdc++.h>
#define N 100005
using namespace std;

typedef long long ll;
typedef pair <ll, int> pil;
const ll mod = 1000000007;

struct matrix{
	ll a[3][3];
	matrix () {memset(a, 0, sizeof a);}
	matrix operator * (const matrix &B) const {
		matrix C; int i, j, k;
		for(i = 0; i < 3; ++i) for(j = 0; j < 3; ++j) {for(k = 0; k < 3; ++k)
			C.a[i][j] += a[i][k] * B.a[k][j]; C.a[i][j] %= mod;}
		return C;
	}
};

int n, cnt = 0;
ll r, la, f[10], u[10], D;
pil s[N];
matrix E, F, G;

ll PowerMod(ll a, ll n, ll c = 1) {for(; n; n >>= 1, a = a * a % mod) if(n & 1) c = c * a % mod; return c;}

matrix MPM(matrix a, ll n, matrix c) {for(; n; n >>= 1, a = a * a) if(n & 1) c = c * a; return c;}

inline void modify(int x) {u[x >= 0 ? x : -x] += (x >= 0 ? 1 : -1);}

int main(){
	int _1, i; ll _2, _3;
	scanf("%d%lld", &n, &r);
	for(i = 0; i < n; ++i){
		scanf("%d%lld%lld", &_1, &_2, &_3);
		s[cnt++] = pil(_2 - 1, _1);
		s[cnt++] = pil(_3, -_1);
	}
	s[cnt++] = pil(r, 0);
	sort(s, s + cnt);
	f[1] = la = 1;
	E.a[0][0] = E.a[1][1] = E.a[2][2] = 1;
	G.a[0][0] = G.a[0][1] = G.a[1][0] = G.a[1][1] = G.a[1][2] = G.a[2][1] = G.a[2][2] = 1;
	for(i = 0; i < cnt; ++i){
		D = s[i].first - la;
		if(D){
			switch((!u[1] << 1 | !u[2]) << 1 | !u[3]){
				case 0: f[0] = f[1] = f[2] = 0; break;
				case 1: f[2] += f[1]; f[0] = f[1] = 0; break;
				case 2: f[1] += f[0] + f[2]; f[0] = f[2] = 0; break;
				case 3: {
					f[2] += f[1]; f[1] = f[0] + f[2]; f[0] = 0; if(D == 1) break;
					f[1] = f[2] = PowerMod(2, D - 2, f[1] + f[2]); break;
				}
				case 4: f[0] += f[1]; f[1] = f[2] = 0; break;
				case 5: f[0] += f[1]; f[2] += f[1]; f[1] = 0; break;
				case 6: {
					f[0] += f[1]; f[1] = f[0] + f[2]; f[2] = 0; if(D == 1) break;
					f[0] = f[1] = PowerMod(2, D - 2, f[0] + f[1]); break;	
				}
				case 7: {
					F = MPM(G, D, E); ll _f[3] = {f[0], f[1], f[2]};
					f[0] = F.a[0][0] * _f[0] + F.a[0][1] * _f[1] + F.a[0][2] * _f[2];
					f[1] = F.a[1][0] * _f[0] + F.a[1][1] * _f[1] + F.a[1][2] * _f[2];
					f[2] = F.a[2][0] * _f[0] + F.a[2][1] * _f[1] + F.a[2][2] * _f[2]; break;
				}
			}
			f[0] %= mod; f[1] %= mod; f[2] %= mod;
		}
		modify(s[i].second); la = s[i].first;
//		printf("%lld: %lld %lld %lld\n", la, f[0],f[1],f[2]);
	}
	printf("%lld\n", f[1]);
	return 0;
}