#include<bits/stdc++.h>
#define maxn 801000
using namespace std;
struct edge{
	int r,nxt;
}e[maxn<<1],ve[maxn<<1];
int n,vis[maxn],to[maxn],q[maxn],cvis[maxn],tp,head[maxn],vhead[maxn],dp[maxn],esz,vsz,m;
void exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
	} else exgcd(b,a%b,y,x),y-=a/b*x;
}
void push_back(int u,int v){
	ve[++vsz].r=v;ve[vsz].nxt=vhead[u];
	vhead[u]=vsz;dp[u]++;
}
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
}
int dfs(int u){
	if(cvis[u])return dp[u];
	cvis[u]=1;
	int mx=0,x;
	for(int t=head[u];t;t=e[t].nxt)
		if((x=dfs(e[t].r))>mx)mx=x,to[u]=e[t].r;
	return dp[u]=dp[u]+mx;
}
int get(int x,int y,int m){
	int a,b,g=__gcd(x,__gcd(y,m));
	exgcd(x/g,m/g,a,b);
	return (1ll*y/g*a%m+m)%m;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;++i)
		scanf("%d",&x),vis[x]=1;
	for(int i=1,g;i<m;++i)if(!vis[i]){
		push_back(g=__gcd(i,m),i);
		if(!cvis[g])cvis[g]=true,q[++tp]=g;
	}
	sort(q+1,q+tp+1);
	for(int i=1;i<=tp;++i)
		for(int j=i+1;j<=tp;++j)
			if(q[j]%q[i]==0)addedge(q[i],q[j]);	
	memset(cvis,0,sizeof(cvis));
	int ans=0,lans=0;
	for(int i=1;i<=tp;++i)
		if(dfs(q[i])>ans)ans=dfs(lans=q[i]);
	if(!vis[0])ans++;
	printf("%d\n",ans);
	int lst=0,p=1;
	for(;lans;lans=to[lans])
		for(int t=vhead[lans];t;t=ve[t].nxt)
			printf("%d ",lst?get(lst,ve[t].r,m):ve[t].r),lst=ve[t].r;
	if(!vis[0])printf("0");
}