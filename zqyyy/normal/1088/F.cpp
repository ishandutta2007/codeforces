#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=5e5+7,inf=0x3f3f3f3f;
struct Edge{int to,nxt;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y){
	e[++s_e]={y,head[x]},head[x]=s_e;
}
int n,rt,a[N],f[N][20];
ll ans;
void dfs(int x,int fa){
	if(fa){
		f[x][0]=fa;
		ll res=a[fa];int i;
		for(i=1;i<=19;i++){
			f[x][i]=f[f[x][i-1]][i-1];
			if(!f[x][i])break;
			res=min(res,1ll*(i+1)*a[f[x][i]]);
		}
		ans+=min(res,1ll*(i+1)*a[rt])+a[x];
	}
	for(int i=head[x],y;i;i=e[i].nxt)
		if((y=e[i].to)!=fa)dfs(y,x);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),a[0]=inf;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,x,y;i<n;i++)x=read(),y=read(),add_e(x,y),add_e(y,x);
	for(int i=1;i<=n;i++)if(a[i]<a[rt])rt=i;
	dfs(rt,0),printf("%lld\n",ans);
	return 0;
}