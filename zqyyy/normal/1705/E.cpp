#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __uint128_t ulll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7, M=1563;
int n, Q, a[N];
ulll b[2000];
inline void inc(int p, int x) {
	ulll v=b[p]; b[p]+=(ulll)1<<x;
	if (v>b[p]) inc(p+1, 0);
}
inline void dec(int p, int x) {
	ulll v=b[p]; b[p]-=(ulll)1<<x;
	if (v<b[p]) dec(p+1, 0);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(), Q=read();
	for (int i=1; i<=n; i++) a[i]=read(), inc(a[i]>>7, a[i]&127);
	while (Q--) {
		int i=read();
		dec(a[i]>>7, a[i]&127);
		a[i]=read();
		inc(a[i]>>7, a[i]&127);
		for (int i=M; ~i; i--)
			if (b[i]) {
				for (int j=127; ~j; j--)
					if (b[i]>>j&1)  {printf("%d\n", i<<7|j); break;}
				break;
			}
	}
	return 0;
}