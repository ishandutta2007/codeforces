#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=((r<<1)+(r<<3)+(c&15)),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
struct Edge{int to,nxt;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y){
	e[++s_e]={y,head[x]},head[x]=s_e;
}
int n,K,dep[N],f[N],len[N],son[N];
bool is[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa)continue;
		dfs(y,x);
		if(len[y]>len[son[x]])son[x]=y;
	}
	is[son[x]]=1,len[x]=len[son[x]]+1;
}
int tot,a[N];
inline ll F(int x){return 1ll*x*(n-x);}
inline ll G(int x){
	if(x<n/2)return F(n/2);
	return F(x);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n=read(),K=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add_e(x,y),add_e(y,x);	
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		if(!is[i])a[++tot]=len[i];
	sort(a+1,a+tot+1,greater<int>());
	ll ans=-1e18,sum=0;
	for(int i=1;i<=min(K,tot);i++)sum+=a[i],ans=max(ans,F(i)-G(sum));
	if(K>tot){
		for(int i=tot+1;i<=K;i++)ans=max(ans,F(i));	
	}
	printf("%lld\n",ans);
    return 0;
}