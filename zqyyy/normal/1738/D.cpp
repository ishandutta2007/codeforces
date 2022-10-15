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
int n, K, b[N];
vector<int>vec[N];
inline void clear() {}
inline void work() {
	n=read(), K=n;
	for (int i=1; i<=n; i++) b[i]=read();
	for (int i=1; i<=n; i++) if (b[i]<i) {K=i-1; break;}
	printf("%d\n", K);
	for (int i=0; i<=n+1; i++) vec[i].clear();
	int now=count(b+1, b+n+1, 0)?0:n+1, cnt=0;
	for (int i=1; i<=n; i++) vec[b[i]].push_back(i);
	while (cnt<n) {
		cnt+=vec[now].size();
		sort(vec[now].begin(), vec[now].end(), [&](int x, int y) {return vec[x].size()<vec[y].size();});
		for (int x:vec[now]) printf("%d ", x);
		now=vec[now].back();
	}
	puts("");
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work(), clear();
	return 0;
}