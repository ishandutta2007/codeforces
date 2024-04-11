#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n, m, id[N];
ll s[N];
inline void work() {
	n=read(), m=read();
	for (int i=1; i<=n; i++) {
		s[i]=0; ll res=0; id[i]=i;
		for (int j=1; j<=m; j++) res+=read(), s[i]+=res;
	}
	sort (id+1, id+n+1, [&](int x, int y) {return s[x]<s[y];});
	printf("%d %lld\n", id[1], s[id[2]]-s[id[1]]);
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