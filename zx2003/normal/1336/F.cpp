#include<bits/stdc++.h>
using namespace std;
const int N=150005;
typedef long long ll;
int n,m,k,i,j,x,y,rt[N],s[N],t[N];
vector<int>e[N];
int dep[N],be[N],en[N],dcnt,anc[20][N];
void dfs(int x,int fa){
	be[x]=++dcnt;
	dep[x]=dep[fa]+1;anc[0][x]=fa;
	for(int y:e[x])if(y!=fa)dfs(y,x);
	en[x]=dcnt;
}
inline int ka(int x,int k){for(int i=0;1<<i<=k;++i)if(k>>i&1)x=anc[i][x];return x;}
inline int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int dt=dep[y]-dep[x],i;
	for(i=0;1<<i<=dt;++i)if(dt>>i&1)y=anc[i][y];
	if(x==y)return x;
	for(i=19;i>=0;--i)if(anc[i][x]!=anc[i][y])x=anc[i][x],y=anc[i][y];
	return anc[0][x];
}
namespace ST{
struct node{int l,r,s;}t[N*100];int tcnt;
void ins(int&x,int l,int r,int k,int v){
	if(!x)x=++tcnt;t[x].s+=v;if(l==r)return;
	int m=l+r>>1;if(k<=m)ins(t[x].l,l,m,k,v);else ins(t[x].r,m+1,r,k,v);
}
int merge(int x,int y){
	if(!x || !y)return x|y;
	t[x].s+=t[y].s;t[x].l=merge(t[x].l,t[y].l);t[x].r=merge(t[x].r,t[y].r);
	return x;
}
int ask(int x,int rl,int rr,int l,int r){
	if(!x || (l<=rl && rr<=r))return t[x].s;
	int m=rl+rr>>1;return (l<=m?ask(t[x].l,rl,m,l,r):0)+(m<r?ask(t[x].r,m+1,rr,l,r):0);
}
}
int aa[N];
struct chain{
	int a,b,c,d;
	int gett(int z){
		z=dep[c]-dep[z];
		return ka(b,dep[b]-dep[a]-z);
	}
}ch[N];
bool bb[N];
set<int>see[N],*se[N];
vector<int>in[N],out[N],qu[N];
ll ans,ss,ww[N];
bool FL;
void dfss(int x,int fa){
	se[x]=see+x;
	auto upd=[&](int z,int v){
		int zz=ch[z].gett(x);
		ww[x]+=v*ST::ask(rt[x],1,n,be[zz],en[zz]);
	};
	auto ins=[&](int z,int v){
		ST::ins(rt[x],1,n,be[ch[z].b],v);
		ST::ins(rt[x],1,n,be[anc[0][ch[z].a]],v);
		if(v==1)se[x]->insert(z);else se[x]->erase(z);
	};
	for(auto u:in[x]){
		if(FL)upd(u,1);
		ins(u,1);
	}
	for(int y:e[x])if(y!=fa){
		dfss(y,x);aa[x]+=aa[y];
		if(se[x]->size()<se[y]->size())swap(se[x],se[y]),swap(rt[x],rt[y]);
		if(FL)for(int z:*se[y])upd(z,1),se[x]->insert(z);
		rt[x]=ST::merge(rt[x],rt[y]);
	}
	if(FL)ans+=ww[x];else for(int u:qu[x])ss+=ST::ask(rt[x],1,n,be[u],en[u])-1;
	for(auto u:out[x])ins(u,-1);
	if(x>1)ans+=(1ll*aa[x]*(aa[x]-1)>>1)*(FL?1:-1);
}
inline void calc(int k){
	FL=k==::k;
	memset(ST::t,0,sizeof ST::t);ST::tcnt=0;memset(rt,0,sizeof rt);
	memset(aa,0,sizeof aa);memset(ww,0,sizeof ww);
	for(i=1;i<=n;++i)see[i].clear(),in[i].clear(),out[i].clear(),qu[i].clear();
	for(i=1;i<=m;++i){
		int l=lca(s[i],t[i]),d1=dep[s[i]]-dep[l],d2=dep[t[i]]-dep[l],d=d1+d2;
		if(d<k)continue;
		if(d1>=k)++aa[s[i]],--aa[ka(s[i],d1-k+1)];
		if(d2>=k)++aa[t[i]],--aa[ka(t[i],d2-k+1)];
		if(l!=s[i] && l!=t[i] && k>1){
			if(be[s[i]]>be[t[i]])swap(s[i],t[i]);
			int s1,s2,t1,t2;
			auto gett=[&](int s,int t,int&a,int&b){
				int dd=dep[t]-dep[l];
				if(dd>=k)b=ka(t,dd-k+1),a=ka(s,dep[s]-dep[l]-1);
					else b=t,a=ka(s,d-k);
			};
			gett(s[i],t[i],s1,t1);gett(t[i],s[i],t2,s2);
			ch[i]=(chain){s1,s2,t1,t2};
			in[t1].push_back(i);out[t2].push_back(i);
			if(!FL){
				bool bb=0;
				if(anc[0][s1]==l)qu[t1].push_back(s1),bb=1;
				if(anc[0][t2]==l && (!bb || t1!=t2))qu[t2].push_back(s2);
			}
		}
	}
	dfss(1,0);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);for(i=1;i<20;++i)for(j=1;j<=n;++j)anc[i][j]=anc[i-1][anc[i-1][j]];
	for(i=1;i<=m;++i)scanf("%d%d",s+i,t+i);
	calc(k);calc(k+1);
	assert(ss%2==0);
	ans-=ss/2;
	printf("%lld\n",ans);
}