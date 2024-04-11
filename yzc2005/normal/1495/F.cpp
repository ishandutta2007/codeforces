// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=200005;
int p[N],a[N],b[N],fa[N],st[N],top,anc[N][20],dep[N],cnt[N];
bool vis[N];
ll dis[N];
int lca(int x,int y)
{
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=19;i>=0;--i)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;--i)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
	return fa[x];
}
inline ll getdis(int x,int y){return dis[x]+dis[y]-2LL*dis[lca(x,y)];}
std::set<int> S;
ll ans;
void ins(int x)
{
	auto it=S.insert(x).first,qwq(it);
	int pre=it==S.begin()?*S.rbegin():*--it;
	int suf=++qwq==S.end()?*S.begin():*qwq;
	ans-=getdis(pre,suf),ans+=getdis(x,pre),ans+=getdis(x,suf);
}
void del(int x)
{
	auto it=S.find(x),qwq(it);
	int pre=it==S.begin()?*S.rbegin():*--it;
	int suf=++qwq==S.end()?*S.begin():*qwq;
	ans+=getdis(pre,suf),ans-=getdis(x,pre),ans-=getdis(x,suf),S.erase(x);
}
int main()
{
	int n,q;read(n,q);
	for(int i=1;i<=n;++i)read(p[i]);
	for(int i=1;i<=n;++i)
	{
		while(top&&p[i]>p[st[top]])--top;
		fa[i]=st[top],st[++top]=i,anc[i][0]=fa[i],dep[i]=dep[fa[i]]+1;
		for(int j=1;j<20;++j)anc[i][j]=anc[anc[i][j-1]][j-1];
	}
	for(int i=1;i<=n;++i)read(a[i]),dis[i]=a[i];
	for(int i=1;i<=n;++i)read(b[i]),dis[i]-=b[i],dis[fa[i]]+=b[i];
	for(int i=n;i>=1;--i)dis[fa[i]]+=min(0LL,dis[i]),chmax(dis[i],0LL);
	for(int i=1;i<=n;++i)dis[i]+=dis[fa[i]];
	int x;S={0},cnt[0]=inf;
	while(q--)
	{
		read(x);
		if(vis[x])!--cnt[fa[x]]?del(fa[x]):void();
		else !cnt[fa[x]]++?ins(fa[x]):void();
		vis[x]^=1;
		printf("%lld\n",ans/2+dis[0]);
	}
	return 0;
}