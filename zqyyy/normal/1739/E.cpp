#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7, mod=998244353, inf=0x3f3f3f3f;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int n, f[N][2][2]; //row, is turn
char s[2][N];
inline void clear() {}
inline void work() {
	n=read(), scanf("%s%s", s[0]+1, s[1]+1);
	memset(f, 0xc0, sizeof f);
	f[1][0][0]=0; if (s[1][1]&1) f[1][1][1]=1;
	for (int i=2; i<=n; i++)
		for (int j=0; j<2; j++)
			for (int k=0; k<2; k++) {
				int v=f[i-1][j][k]; if (v<0) continue;
				for (int l=0; l<=s[0][i]-'0'; l++)
					for (int o=0; o<=s[1][i]-'0'; o++) {
						if (k && ((j && l) ||  (!j && o))) continue;
						if (!j && !k) ckmax(f[i][o][o], v+l+o);
						else if (!j && k) {
							if (o) ckmax(f[i][1][1], v+1);
							else ckmax(f[i][0][0], v+l);
						} else if (j && !k) {
							ckmax(f[i][!l][l], v+l+o);
						} else {
							if (l) ckmax(f[i][0][1], v+1);
							else ckmax(f[i][1][0], v+o); 
						}
					}
			}
//	for (int i=1; i<=n; i++, puts(""))
//		for (int j=0; j<2; j++)
//			for (int k=0; k<2; k++) cout<<f[i][j][k]<<" \n"[k==1];
	int ans=0;
	for (int i=0; i<2; i++) for (int j=0; j<2; j++) ckmax(ans, f[n][i][j]);
	cout<<ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=1;
	while (test--) work(), clear();
	return 0;
}