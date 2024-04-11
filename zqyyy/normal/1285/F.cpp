#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() {
	static char *p1, *p2, buf[1<<20];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<20, stdin), p1==p2?EOF:*p1++):*p1++;
}
inline int read() {
	int f=1, r=0; char c=getc();
	while (!isdigit(c)) f^=c=='-', c=getc();
	while (isdigit(c)) r=r*10+c-48, c=getc();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1e5+7;
int n, a[N], s_p, pr[N], v[N], mu[N];
vector<int>fac[N], vec[N], Fac[N];
inline void init(int n) {
	mu[1]=1;
	for (int i=2; i<=n; i++) {
		if (!v[i]) v[i]=i, pr[++s_p]=i, mu[i]=-1;
		for (int j=1; j<=s_p && i*pr[j]<=n; j++) {
			v[i*pr[j]]=pr[j];
			if (i%pr[j]==0) break;
			mu[i*pr[j]]=-mu[i];
		}
	}
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j+=i) fac[j].push_back(i);
	for (int i=1; i<=n; i++)
		if (mu[i]) for (int j=i; j<=n; j+=i) Fac[j].push_back(i);
}
int tp, stk[N], cnt[N];
ll ans;
inline bool chk(int x) {
	int sum=0;
	for (int y:Fac[x]) sum+=mu[y]*cnt[y];
	return sum>0;
}
inline void work(int now, vector<int>&vec) {
	if ((int)vec.size()<=1) return;
	for (int i=1; i<=vec[0]; i++) cnt[i]=0;
	bool fl=false;
	for (int x:vec) {
		while (tp) {
			int y=stk[tp];
			for (int z:Fac[y]) cnt[z]--;
			if (chk(x)) tp--;
			else {
				for (int z:Fac[y]) cnt[z]++;
				break;
			}
		}
		if (tp && chk(x)) ckmax(ans, (ll)now*x*stk[tp]), fl=true;
		if (!fl) {
			for (int y:Fac[x]) cnt[y]++;
			stk[++tp]=x;
		} else if (!tp) break;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	sort(a+1, a+n+1), n=unique(a+1, a+n+1)-a-1, ans=a[n], init(a[n]);
	for (int i=n; i; i--)
		for (int x:fac[a[i]]) vec[x].push_back(a[i]/x);
	for (int d=a[n]; d; d--) work(d, vec[d]);
	printf("%lld\n", ans);
	return 0;
}