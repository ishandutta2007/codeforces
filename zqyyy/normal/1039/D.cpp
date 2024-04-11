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
struct Edge{int to,nxt;}e[N];
int s_e,head[N];
inline void add_e(int x,int y){e[++s_e]={y,head[x]},head[x]=s_e;}
int n,B,f[N],g[N],ans[N];
int s_dfn,id[N];
vector<int>G[N];
void dfs1(int x,int fa){
	if(fa)add_e(fa,x);
	for(int y:G[x])if(y^fa)dfs1(y,x);
	id[++s_dfn]=x;
}
inline int work(int k){
	for(int o=1;o<=n;o++){
		int x=id[o];
	    f[x]=g[x]=0;int mx=0,cmx=0;
	    for(int i=head[x],y;i;i=e[i].nxt){
			f[x]+=f[y=e[i].to];
			if(g[y]>mx)cmx=mx,mx=g[y];
			else if(g[y]>cmx)cmx=g[y];
	    }
    	if(mx+cmx+1>=k)g[x]=0,f[x]++;
   		else g[x]=mx+1;
   	}
   	return f[1];
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=read(),B=n<=100?sqrt(n):sqrt(n*log2(n));
    for(int i=1;i<n;i++){
	int x=read(),y=read();
	G[x].push_back(y),G[y].push_back(x);
    }
    dfs1(1,0);
    for(int k=1;k<=B;k++)ans[k]=work(k);
    for(int lst=B+1,w=work(lst);w;w=work(lst)){
	int l=lst+1,r=n;
	while(l<=r){
	    int mid=(l+r)>>1;
	    if(work(mid)==w)l=mid+1;
	    else r=mid-1;
	}
	for(int i=lst;i<=r;i++)ans[i]=w;
	lst=r+1;
    }
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
    return 0;
}