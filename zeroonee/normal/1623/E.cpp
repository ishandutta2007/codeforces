#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
template<typename typC,int N> struct bit
{
	typC a[N];
	int n;
	bit()
	{
		memset(a,0,sizeof a);
	}
	void init(int nn)
	{
		n=nn;
		memset(a+1,0,n*sizeof a[0]);
	}
	void mdf(int x,typC y)
	{
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y; 
	}
	typC sum(int x)
	{
		typC r=a[x];
		while (x^=x&-x) r+=a[x];
		return r;
	}
	typC sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
const int N=2e5+2;
bit<ll,N> t;
int c[N][2],a[N],fa[N],b[N],fb[N],dfn[N],siz[N],FA[N];
char s[N];
void dfs1(int u)
{
	static int id=0;
	a[++id]=u;fa[u]=id;siz[u]=1;dfn[u]=id;
	if (c[u][0]) dfs1(c[u][0]),siz[u]+=siz[c[u][0]];
	if (c[u][1]) dfs1(c[u][1]),siz[u]+=siz[c[u][1]];
}
void dfs2(int u)
{
	static int id=0;
	if (c[u][0]) dfs2(c[u][0]);
	b[++id]=u;fb[u]=id;
	if (c[u][1]) dfs2(c[u][1]);
}
bool av[N],fg[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j,k;string S;
	cin>>n>>m>>S;t.init(n);
	for (i=1;i<=n;i++) s[i]=S[i-1];
	for (i=1;i<=n;i++) cin>>c[i][0]>>c[i][1];
	for (i=1;i<=n;i++) for (j=0;j<2;j++) if (c[i][j]) FA[c[i][j]]=i;
	dfs1(1);dfs2(1);
	for (i=j=1;i<=n;i=j)
	{
		while (j<=n&&s[b[i]]==s[b[j]]) ++j;//[i,j)
		for (k=i;k<j;k++) av[b[k]]=j<=n&&s[b[i]]<s[b[j]];
	}
///	for (i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
	for (i=1;i<=n;i++) t.mdf(dfn[i],1),t.mdf(dfn[i]+siz[i],-1);fg[0]=1;
	for (i=1;i<=n&&m;i++) if (!fg[b[i]]&&t.sum(dfn[b[i]])<=m)
	{
		int x=b[i];//assert(dfn[x]==i);
		if (av[x])
		{
			fg[x]=1;int cc=t.sum(dfn[x]);
			m-=cc;int cnt=1;
			t.mdf(dfn[x],-1);t.mdf(dfn[x]+siz[x],1);
			while (!fg[x=FA[x]]) fg[x]=1,t.mdf(dfn[x],-1),t.mdf(dfn[x]+siz[x],1),++cnt;
			assert(cc==cnt);
		}
		else if (c[x][1]) t.mdf(dfn[c[x][1]],1e6),t.mdf(dfn[c[x][1]]+siz[c[x][1]],-1e6);
	}
	string ans;
	for (i=1;i<=n;i++) {ans+=s[b[i]];if (fg[b[i]]) ans+=s[b[i]];}
	cout<<ans<<endl;
}