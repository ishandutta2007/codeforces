#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=210000;
const int P=1000000007;
int n,k;
int cl[N*15],cr[N*15],sum[N*15][2],tag[N*15][2];
int segtot;
int root[N],top[N],rank[N],but[N];
int bel[N];
int lktot;
int head[N],np[N],p[N],tot,dep[N],is[N];int fa[N];
int tofa[N];
int size[N];
int val[N][2];
//------
int rest;
inline void updata(int me){
	rep(kk,0,1){
		sum[me][kk]+=sum[cl[me]][kk];
		if(sum[me][kk]>=P)sum[me][kk]-=P;
		sum[me][kk]+=sum[cr[me]][kk];
		if(sum[me][kk]>=P)sum[me][kk]-=P;
	}
}
void bd(int &me,int l,int r){
	if(l>r)return;
	me=++segtot;tag[me][0]=tag[me][1]=1;
	if(l==r){
		if(tofa[rest]==-1){
			sum[me][0]=1;
			sum[me][1]=0;
		}
		else
		if(tofa[rest]==1){
			sum[me][0]=0;
			sum[me][1]=1;
		}
		rest=fa[rest];
		return;
	}
	int mid=(l+r)>>1;
	bd(cl[me],l,mid);
	bd(cr[me],mid+1,r);
	updata(me);
}
void build_(int lk){
	rest=but[lk];
	bd(root[lk],1,rank[top[lk]]-1);
}
//------
int lca(int x,int y){
	if(bel[x]==bel[y]){
		if(dep[x]<dep[y])return x;
		return y;
	}
	if(dep[top[bel[x]]]<dep[top[bel[y]]]){
		return lca(x,fa[top[bel[y]]]);
	}
	else
		return lca(fa[top[bel[x]]],y);
}
inline void down(int x){
	rep(kk,0,1){
		int v=tag[x][kk];
		tag[cl[x]][kk]=tag[cl[x]][kk]*1ll*v%P;
		tag[cr[x]][kk]=tag[cr[x]][kk]*1ll*v%P;
		sum[cl[x]][kk]=sum[cl[x]][kk]*1ll*v%P;
		sum[cr[x]][kk]=sum[cr[x]][kk]*1ll*v%P;
		tag[x][kk]=1;
	}
}
void modify(int me,int l,int r,int x,int y,int MD){
	if(l^r)down(me);
	if(x<=l&&r<=y){
		tag[me][MD]*=2;
		sum[me][MD]=sum[me][MD]*2%P;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)modify(cl[me],l,mid,x,y,MD);
	if(y>mid)modify(cr[me],mid+1,r,x,y,MD);
	updata(me);
}
int ask(int me,int l,int r,int x,int y,int MD){
	if(l^r)down(me);
	if(x<=l&&r<=y)return sum[me][MD];
	int mid=(l+r)>>1;
	int ans=0;
	if(x<=mid)ans=ask(cl[me],l,mid,x,y,MD);
	if(y>mid)ans+=ask(cr[me],mid+1,r,x,y,MD);
	if(ans>=P)ans-=P;
	return ans;
}
int cnt[N][2];
int dv[N][2];
void work(int x,int y){
	int lc=lca(x,y);
	int ans=0;
	cnt[x][1]++;cnt[lc][1]--;
	cnt[y][0]++;cnt[lc][0]--;
}



void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	size[x]=1;
	int fat1,fat2;fat2=0;
	for(int u=head[x];u;u=np[u])if(p[u]!=fa[x]){
		tofa[p[u]]=is[u];
		fa[p[u]]=x;dfs(p[u]);size[x]+=size[p[u]];
		if(size[p[u]]>fat2)fat1=p[u],fat2=size[p[u]];
	}
	if(size[x]==1){
		++lktot;
		but[lktot]=x;
		rank[x]=1;
		bel[x]=lktot;
		return;
	}
	for(int u=head[x];u;u=np[u])if(p[u]!=fa[x]){
		if(fat1==p[u]){
			rank[x]=rank[p[u]]+1;
			bel[x]=bel[p[u]];
		}
		else{
			int y=p[u];
			top[bel[y]]=y;
			//build_(bel[y]);
		}
	}
}
void DD(int x){
	for(int u=head[x];u;u=np[u])if(p[u]!=fa[x]){
		DD(p[u]);
		cnt[x][0]+=cnt[p[u]][0];
		cnt[x][1]+=cnt[p[u]][1];
	}
}
int p2[1100000];
int Main(){
	int ans=0;
	DD(1);
	p2[0]=1;
	rep(i,1,1050000)p2[i]=p2[i-1]*2%P;
	
	rep(i,1,n)rep(j,0,1){
		if(!cnt[i][j])continue;
		ans=(ans+(p2[cnt[i][j]]-1)*val[i][j])%P;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		int x,y,c;scanf("%d%d%d",&x,&y,&c);
		++tot;p[tot]=y;np[tot]=head[x];head[x]=tot;is[tot]=c;
		++tot;p[tot]=x;np[tot]=head[y];head[y]=tot;is[tot]=-c;
	}
	dfs(1);
	top[bel[1]]=1;
	//build_(bel[1]);
	rep(i,1,n){
		if(tofa[i]==-1)val[i][0]=1;
		else if(tofa[i]==1)val[i][1]=1;
	}
	int now=1;
	int ans=0;
	scanf("%d",&k);
	while(k--){
		int x;scanf("%d",&x);
		work(now,x);
		now=x;
	}
	ans=Main();
	printf("%d\n",ans);
	return 0;
}