#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
typedef pair<int,int>pii;
int lo[N*2],n;
struct S{
	static const int N=::N*2;
	char c[N];
	int sa[N],rk[N],h[N],ff[20][N],n;
	inline void getsa(int n){
		static int f[N],g[N],ork[N],ork2[N];
		int d,i,j,p;this->n=n;
		memset(f,0,160);
		for(i=1;i<=n;++i)++f[c[i]-'a'];for(i=1;i<26;++i)f[i]+=f[i-1];
		for(i=1;i<=n;++i)g[f[c[i]-'a']--]=i;
		p=0;
		for(i=1;i<=n;++i)rk[g[i]]=p+=c[g[i]]>c[g[i-1]];
		for(i=1;i<=n;++i)sa[rk[i]]=i;sa[n+1]=0;
		for(d=2;p<n;d<<=1){
			memcpy(ork+1,rk+1,n<<2);
			memcpy(ork2+1,rk+(d>>1)+1,(n-(d>>1))<<2);
			memset(ork2+n+1-(d>>1),0,(d>>1)<<2);
			memset(f,0,(p+1)<<2);
			for(i=1;i<=n;++i)++f[ork2[i]];
			for(i=1;i<=p;++i)f[i]+=f[i-1];
			for(i=1;i<=n;++i)g[f[ork2[i]]--]=i;
			memset(f,0,(p+1)<<2);
			for(i=1;i<=n;++i)++f[ork[i]];
			for(i=1;i<=p;++i)f[i]+=f[i-1];
			for(i=n;i;--i)sa[f[ork[g[i]]]--]=g[i];p=0;
			for(i=1;i<=n;++i)rk[sa[i]]=p+=ork[sa[i]]>ork[sa[i-1]] || ork2[sa[i]]>ork2[sa[i-1]];
		}
		for(i=1,j=0;i<=n;h[rk[i++]]=j)
			for(j?--j:0;c[i+j]==c[sa[rk[i]+1]+j];++j);
		for(i=1;i<n;++i)ff[0][i]=h[i];
		for(i=1;1<<i<n;++i)for(j=1;j+(1<<i)-1<n;++j)ff[i][j]=min(ff[i-1][j],ff[i-1][j+(1<<i-1)]);
	}
	inline int lcp(int x,int y){
		x=rk[x];y=rk[y];if(x>y)swap(x,y);if(x==y)return n-sa[x]+1;
		int l=lo[y-x];return min(ff[l][x],ff[l][y-(1<<l)]);
	}
}sa;
namespace HLD{
int sz[N],dep[N],dad[N],ma[N],top[N],dfn[N],id[N],en[N],xb;
vector<int>e[N];
inline void addedge(int x,int y){e[x].push_back(y);e[y].push_back(x);}
void dfs1(int x,int fa){
	sz[x]=1;dep[x]=dep[fa]+1;dad[x]=fa;
	for(int y:e[x])if(y!=fa){
		dfs1(y,x);sz[x]+=sz[y];
		if(sz[y]>sz[ma[x]])ma[x]=y;
	}
}
void dfs2(int x,int fa){
	dfn[id[x]=++xb]=x;
	if(ma[x])top[ma[x]]=top[x],dfs2(ma[x],x);
	for(int y:e[x])if(y!=fa && y!=ma[x])top[y]=y,dfs2(y,x);
	en[x]=xb;
}
inline void ini(){dfs1(1,0);top[1]=1;dfs2(1,0);}
inline vector<pii>getP(int x,int y){
	vector<pii>A,B;
	for(;top[x]!=top[y];)
		if(dep[top[x]]>dep[top[y]])A.push_back(pii(id[x],id[top[x]])),x=dad[top[x]];
			else B.push_back(pii(id[top[y]],id[y])),y=dad[top[y]];
	A.push_back(pii(id[x],id[y]));
	reverse(B.begin(),B.end());
	A.insert(A.end(),B.begin(),B.end());
	return A;
}
inline bool inc(pii&u,int l){
	if(u.first<u.second)return (u.first+=l)>u.second;
		else return (u.first-=l)<u.second;
}
inline void solve(){
	int a,b,c,d,i=0,j=0,ans=0;scanf("%d%d%d%d",&a,&b,&c,&d);
	auto L=getP(a,b),R=getP(c,d);
	for(;i<L.size() && j<R.size();){
		int b1,b2,mn,l;
		b1=L[i].first<L[i].second?L[i].first:n*2-L[i].first+1;
		b2=R[j].first<R[j].second?R[j].first:n*2-R[j].first+1;
		mn=min(abs(L[i].second-L[i].first)+1,abs(R[j].second-R[j].first)+1);
		ans+=l=min(sa.lcp(b1,b2),mn);if(l<mn)break;
		if(inc(L[i],l))++i;if(inc(R[j],l))++j;
	}
	printf("%d\n",ans);
}
}
int q,a,b,i;
char cc[N];
int main(){
	for(int i=2;i<2*N;++i)lo[i]=lo[i>>1]+1;
	scanf("%d%s",&n,cc+1);
	for(i=1;i<n;++i)scanf("%d%d",&a,&b),HLD::addedge(a,b);
	HLD::ini();
	for(i=1;i<=n;++i)sa.c[i]=sa.c[n*2-i+1]=cc[HLD::dfn[i]];sa.getsa(n*2);
	scanf("%d",&q);
	for(;q--;)HLD::solve();
	return 0;
}