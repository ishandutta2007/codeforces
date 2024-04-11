#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
typedef pair<int,int>pii;
int n,m,i,l,r,x,a[N],b[N];
char o[N];
struct T{
vector<int>e[N];
int be[N],en[N],fa[N],xb;
inline void add(int x,int y){e[x].push_back(y);fa[y]=x;}
void dfs(int x){be[x]=en[x]=++xb;for(int y:e[x])dfs(y);}
inline void ini(){for(int i=1;i<=n;++i)if(!fa[i])dfs(i);}
}U,M;
ll bi[N],ans[N];
inline void add(int x,int v){for(;x<=n;x+=x&-x)bi[x]+=v;}
inline ll ask(int x){ll ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
map<int,int>S;
vector<pii>qu[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i){
		for(;!isalpha(o[i]=getchar()););scanf("%d",a+i);
		if(o[i]=='U' || o[i]=='M'){
			scanf("%d",b+i);
			if(o[i]=='U')U.add(a[i],b[i]);else M.add(a[i],b[i]);
		}
	}
	U.ini();M.ini();
	S[n]=0;
	for(i=1;i<=m;++i){
		if(o[i]=='M')M.en[a[i]]=M.en[b[i]];
		if(o[i]=='Z'){
			auto it=S.lower_bound(M.be[a[i]]),it2=it;
			if(it!=S.begin()?(--it2)->first<M.be[a[i]]-1:1)S[M.be[a[i]]-1]=it->second;
			for(;it!=S.end() && it->first<=M.en[a[i]];S.erase(it++));
			S[M.en[a[i]]]=i;
		}
		if(o[i]=='Q')qu[i].push_back(pii(U.be[a[i]],i)),
			qu[S.lower_bound(M.be[a[i]])->second].push_back(pii(U.be[a[i]],-i));
	}
	for(i=1;i<=m;++i){
		if(o[i]=='U')U.en[a[i]]=U.en[b[i]];
		if(o[i]=='A')r=U.en[a[i]],l=U.be[a[i]],x=r-l+1,add(l,x),add(r+1,-x);
		for(pii u:qu[i])ans[abs(u.second)]+=(u.second>0?1:-1)*ask(u.first);
	}
	for(i=1;i<=m;++i)if(o[i]=='Q')printf("%lld\n",ans[i]);
	return 0;
}