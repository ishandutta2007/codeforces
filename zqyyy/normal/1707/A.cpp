#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n, m, a[N], b[N];
inline void work() {
	n=read(), m=read();
	for (int i=1; i<=n; i++) a[i]=read();
	int q=0;
	for (int i=n; i; i--) {
		if (a[i]<=q) b[i]=1;
		else if (q<m) b[i]=1, q++;
		else b[i]=0;	
	}
	for (int i=1; i<=n; i++) printf("%d", b[i]); putchar(10);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}