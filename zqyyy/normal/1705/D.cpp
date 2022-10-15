#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n, p, q, a[N], b[N];
char str[N];
inline void work() {
	n=read(), p=0, q=0;
	scanf("%s", str+1); char c=str[1], d=str[n];
	for (int i=1; i<n; i++) if (str[i]^str[i+1]) a[++p]=i;
	scanf("%s", str+1);
	for (int i=1; i<n; i++) if (str[i]^str[i+1]) b[++q]=i;
	if (c!=str[1] || d!=str[n] || p!=q) puts("-1");
	else {
		ll ans=0;
		for (int i=1; i<=p; i++) ans+=abs(a[i]-b[i]);
		printf("%lld\n", ans);	
	}
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