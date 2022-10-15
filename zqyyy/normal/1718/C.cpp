#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7;
int n, m, Q, d[222], a[N];
vector<ll>sum[222];
struct Heap {
	priority_queue<ll>q1, q2;
	inline void clear() {while (!q1.empty()) q1.pop(); while (!q2.empty()) q2.pop();}
	inline void push(ll x) {q1.push(x);}
	inline void erase(ll x) {q2.push(x);}
	inline void upd() {while (!q2.empty() && q1.top()==q2.top()) q1.pop(), q2.pop();}
	inline ll top() {return upd(), q1.top();}
}q[222];
inline void work() {
	n=read(), Q=read();
	for (int i=1; i<=n; i++) a[i]=read();
	for (int i=1; i<=m; i++) sum[i].clear(), q[i].clear();
	m=0;
	for (int i=n-1; i; i--) 
		if (n%i==0) {
			bool fl=true;
			for (int j=1; j<=m; j++)
				if (d[j]%i==0) {fl=false; break;}
			if (!fl) continue;
			d[++m]=i, sum[m].resize(i);
			for (int j=1; j<=i; j++) {
				ll res=0;
				for (int k=j; k<=n; k+=i) res+=a[k];
				sum[m][j%i]=res, q[m].push(res);
			}
		}
	auto query=[&]() {
		ll ans=0;
		for (int i=1; i<=m; i++)
			ckmax(ans, q[i].top()*d[i]);
		printf("%lld\n", ans);
	};
	query();
	while (Q--) {
		int p=read(), x=read(), v=x-a[p]; a[p]=x;
		for (int i=1; i<=m; i++) {
			int b=p%d[i];
			q[i].erase(sum[i][b]);
			sum[i][b]+=v, q[i].push(sum[i][b]);
		}
		query();
	}
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	int test=read();
	while (test--) work();
	return 0;
}