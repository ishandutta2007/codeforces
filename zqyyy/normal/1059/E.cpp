#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
struct Edge{int to,nxt;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y){
    e[++s_e]={y,head[x]},head[x]=s_e;
}
int n,L,f[N][17],w[N];
int dp[N],mx[N];
ll S,s[N][17];
void dfs(int x){
    for(int i=1;i<=16;i++){
	f[x][i]=f[f[x][i-1]][i-1];
	s[x][i]=s[x][i-1]+s[f[x][i-1]][i-1];
    }
    mx[x]=-1;
    for(int i=head[x];i;i=e[i].nxt){
	int y=e[i].to;
	dfs(y),dp[x]+=dp[y];
	mx[x]=max(mx[x],mx[y]-1);
    }
    if(~mx[x])return;
    dp[x]++,mx[x]=0;ll sum=0;int u=x;bool lim=1;
    for(int i=16;~i;i--){
	if(lim && !(L>>i&1))continue;
	if(s[u][i]+sum<=S)sum+=s[u][i],u=f[u][i],mx[x]|=1<<i;
	else lim=0;
    }
    mx[x]--;
}
int main(){
    n=read(),L=read(),S=read();
    for(int i=1;i<=n;i++){
	w[i]=s[i][0]=read();
	if(w[i]>S)puts("-1"),exit(0);
    }
    for(int i=2;i<=n;i++)add_e(f[i][0]=read(),i);
    dfs(1);
    printf("%d\n",dp[1]);
    return 0;
}