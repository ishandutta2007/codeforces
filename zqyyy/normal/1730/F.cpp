#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=5007, inf=0x3f3f3f3f;
int n, K, p[N], pos[N], f[2][513];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), K=read();
	for (int i=1; i<=n; i++) p[i]=read(), pos[p[i]]=i;
	memset(f, 0x3f, sizeof f); int inv=0;
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++) if (pos[i]>pos[j]) inv++;
	f[0][0]=inv; int o=0;
	for (int i=1; i<=n; i++) {
		o^=1;
		for (int s=0; s<(1<<(K+1)); s++) {
			int &v=f[o^1][s]; if (v==inf) continue;
			if (s&1) {ckmin(f[o][s>>1], v), v=inf; continue;}
			for (int j=0, lim=min(K, n-i); j<=lim; j++) {
				if (s>>j&1) continue;
				int t=s|1<<j, val=v;
				for (int k=j+1; k<=lim; k++) {
					if (~s>>k&1) continue;
					if (pos[i+k]<pos[i+j]) val--;
					else val++;
				}
				ckmin(f[o^1][t], val);
			}
			v=inf;
		}
	}
	printf("%d\n", f[o][0]);
	return 0;
}