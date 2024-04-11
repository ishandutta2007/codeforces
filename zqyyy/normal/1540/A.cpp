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
int n,d[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)d[i]=read();
	sort(d+1,d+n+1);
	ll ans=d[n]-d[1];
	for(int i=1;i<=n;i++)ans+=1ll*(n-i-(i-1))*d[i];
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}