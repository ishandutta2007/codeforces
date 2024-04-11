#include <bits/stdc++.h>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
int n,ans,h[N],f[N],g[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++)h[i]=read();
	for(int i=1;i<=n;i++)f[i]=min(f[i-1]+1,h[i]);
	for(int i=n;i;i--)g[i]=min(g[i+1]+1,h[i]);
	for(int i=1;i<=n;i++)ans=max(ans,min(f[i],g[i]));
	return cout<<ans,0;
}