#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=3e5+7;
int n,Q,tot,tp,stk[N],dep[N],id[N],L[N],R[N],cnt[N];
char str[N];
vector<int>d[N],G[N];
ll f[N];
int s_dfn,s_bfn,dfn[N],low[N],fa[N],bfn[N];
struct b1t{
    ll c[N];
    inline void add(int p,ll x){if(p)for(;p<=n;p+=p&-p)c[p]+=x;}
    inline ll ask(int p){ll res=0;for(;p;p^=p&-p)res+=c[p];return res;}
    inline ll query(int l,int r){return ask(r)-ask(l-1);}
}T,B;
void dfs(int x){
    dfn[x]=++s_dfn,cnt[x]=G[x].size();
    for(int y:G[x])dfs(y),fa[y]=x;
    f[x]=1ll*G[x].size()*(G[x].size()+1)>>1;
    T.add(dfn[x],f[x]),low[x]=s_dfn;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=read(),Q=read(),scanf("%s",str+1);
    for(int i=1;i<=n;i++){
	if(str[i]=='('){
	    stk[++tp]=++tot,L[tot]=i,id[i]=tot,dep[i]=tp;
	    d[tp].push_back(i),G[stk[tp-1]].push_back(tot);
	}else{
	    if(!tp)continue;
 	    int x=stk[tp--];
	    R[x]=i,id[i]=x;
	}
    }
    dfs(0);
    queue<int>q;q.push(0);
    while(!q.empty()){
	int x=q.front();q.pop(),bfn[x]=++s_bfn,B.add(s_bfn,1);
	for(int y:G[x])q.push(y);
    }
    while(Q--){
	int t=read(),l=read(),r=read();
	if(t==1){
	    l=id[l];
	    T.add(dfn[fa[l]],-(cnt[fa[l]]--)),B.add(bfn[l],-1);
	}else{
	    l=id[l],r=id[r];
	    ll ans=T.query(dfn[l],low[r]);
	    ll num=B.query(bfn[l],bfn[r]);
	    ans+=1ll*num*(num+1)>>1;
	    printf("%lld\n",ans);
	}
    }
    return 0;
}