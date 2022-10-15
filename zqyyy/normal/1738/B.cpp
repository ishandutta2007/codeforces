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
int n, K;
ll a[N], b[N];
inline void clear() {}
#define OK return puts("Yes"), void()
#define GG return puts("No"), void()
inline void work() {
	n=read(), K=read();
	for (int i=1; i<=K; i++) a[i]=read();
	for (int i=1; i<=K; i++) b[i]=a[i]-a[i-1];
	for (int i=3; i<=K; i++) if (b[i]<b[i-1]) GG;
	if (K==1) OK;
	ll lim=b[2], sum=a[1], num=n-K+1;
	ll res=sum-(num-1)*lim;
	puts(res<=lim?"Yes":"No");
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