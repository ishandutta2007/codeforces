#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
const int N=1e5+7;
int n, m, K, a[N];
inline void work() {
	n=read(), m=read(), K=read();
	for (int i=1; i<=K; i++) a[i]=read();
	if (*max_element(a+1, a+K+1)>=(ll)n*m) {puts("Yes"); return; }
	ll sum=0; bool fl=false;
	for (int i=1; i<=K; i++) {
		int x=a[i]/n;
		if (x>1) sum+=x, fl|=x>2;
	}
	if (sum>=m && (fl || (sum-m)%2==0)) {puts("Yes"); return; }
	sum=0, fl=false;
	for (int i=1; i<=K; i++) {
		int x=a[i]/m;
		if (x>1) sum+=x, fl|=x>2;
	}
	if (sum>=n && (fl || (sum-n)%2==0)) {puts("Yes"); return; }
	puts("No");
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}