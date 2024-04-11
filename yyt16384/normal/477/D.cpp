#include <algorithm>
#include <cstdio>
#include <cstring>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=5005;
const int MOD=1000000007;
int n;
char s[MAXN];
int sa[MAXN];
int rank[2*MAXN];
int lcp[MAXN];
int ll[MAXN][MAXN];
int cmparg;
bool cmp(const int &x,const int &y)
{
	return rank[x]<rank[y]||(rank[x]==rank[y]&&rank[x+cmparg]<rank[y+cmparg]);
}
void init()
{
	int tmp[MAXN];
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;++i) rank[i]=s[i]-'0';
	for (int i=n;i<2*n;++i) rank[i]=-1;
	for (int i=1;i<=n;i<<=1)
	{
		for (int j=0;j<n;++j) sa[j]=j;
		cmparg=i;
		std::sort(sa,sa+n,cmp);
		for (int j=0,k=0;j<n;++j)
		{
			if (j>0&&cmp(sa[j-1],sa[j])) ++k;
			tmp[sa[j]]=k;
		}
		for (int j=0;j<n;++j) rank[j]=tmp[j];
	}
	for (int i=0;i<n;++i) sa[rank[i]]=i;
	for (int i=0;i<n-1;++i)
	{
		int x=sa[i],y=sa[i+1];
		int j=0;
		while (s[x+j]==s[y+j]) ++j;
		lcp[i]=j;
	}
	for (int i=0;i<n;++i)
		for (int j=i+1,l=0x3f3f3f3f;j<n;++j)
			l=std::min(l,lcp[j-1]),ll[sa[j]][sa[i]]=ll[sa[i]][sa[j]]=l;
}
int check(int u,int v,int l)
{
	if (ll[u][v]>=l) return 1;
	else return rank[u]<rank[v];
}
int powermod(int x,int y)
{
	int s=1;
	while (y)
	{
		if (y&1) s=(long long)s*x%MOD;
		x=(long long)x*x%MOD;
		y>>=1;
	}
	return s;
}
void solve()
{
	static int g[MAXN][MAXN];
	static int hh[MAXN][MAXN];
	memset(hh,0x3f,sizeof(hh));
	g[0][1]=1;hh[0][1]=1;
	for (int i=0;i<=n;++i)
	{
		for (int j=1;j<=n;++j)
			(g[i][j]+=g[i][j-1])%=MOD,hh[i][j]=std::min(hh[i][j],hh[i][j-1]);
		if (i==n) break;
		for (int j=i;j<n;++j)
			if (hh[i][j]<0x3f3f3f3f&&s[j]!='0')
			{
				int l=j-i;
				if (j+l>n) break;
				int u=j+l+1;
				if (check(i,j,l)) --u;
				if (u<=n) (g[j][u]+=g[i][j])%=MOD,hh[j][u]=std::min(hh[j][u],hh[i][j]+1);
			}
	}
	int su=0;
	for (int i=0;i<=n;++i)
		(su+=g[i][n])%=MOD;
	int ansf=-1;
	for (int i=n;i>=0;--i)
		if (hh[i][n]<0x3f3f3f3f&&(ansf==-1||n-i<20))
		{
			int sum=0;
			for (int j=i;j<n;++j)
				if (s[j]=='1') (sum+=powermod(2,n-j-1))%=MOD;
			if (ansf!=-1)
			{
				if (sum+hh[i][n]<ansf) ansf=sum+hh[i][n];
			}
			else
			{
				ansf=sum+hh[i][n];
				ansf%=MOD;
				if (n-i>=20) break;
			}
		}
	printf("%d\n%d\n",su,ansf);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}