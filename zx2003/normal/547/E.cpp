#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int ch[N][26],fail[N],xb,s[N],q[N],bi[N],dcnt,be[N],en[N],t,w=1,u,x;
vector<int>e[N],path[N];
inline void add(int x){for(;x<=dcnt;x+=x&-x)++bi[x];}
inline int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
void dfs(int u){be[u]=++dcnt;for(int v:e[u])dfs(v);en[u]=dcnt;}
char c[N];
int n,Q,ans[500005],i,j,l,r;
vector<pair<int,int>>qu[N];
int main(){
	scanf("%d%d",&n,&Q);
	for(j=1;j<=n;++j){
		scanf("%s",c+1);path[j].resize(strlen(c+1));
		for(u=0,i=1;c[i];++i){
			x=c[i]-'a';
			if(!ch[u][x])ch[u][x]=++xb;
			path[j][i-1]=u=ch[u][x];
		}
	}
	for(;t<w;)for(i=0,u=q[++t],s[u]+=s[fail[u]];i<26;++i)if(!ch[u][i])ch[u][i]=ch[fail[u]][i];
		else q[++w]=ch[u][i],fail[q[w]]=u?ch[fail[u]][i]:0;
	for(i=1;i<=xb;++i)e[fail[i]].push_back(i);dfs(0);
	for(i=1;i<=Q;++i)scanf("%d%d%d",&l,&r,&x),qu[l-1].push_back(make_pair(x,-i)),qu[r].push_back(make_pair(x,i));
	for(i=1;i<=n;++i){
		for(int x:path[i])add(be[x]);
		for(auto u:qu[i])x=u.second,j=path[u.first].back(),ans[abs(x)]+=(x>0?1:-1)*(ask(en[j])-ask(be[j]-1));
	}
	for(i=1;i<=Q;++i)printf("%d\n",ans[i]);
	return 0;
}