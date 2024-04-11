#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=300,mod=998244353;
int n,p[maxn],q[maxn],pos[maxn];
int bas;
int cnt0,cnt1,cnt2;
struct dsu
{
	int fa[maxn],nsiz[maxn],esiz[maxn];
	bool vis[maxn];
	void prework(){iota(fa+1,fa+n+1,1);fill_n(nsiz+1,n,1);}
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	void merge(int x,int y)
	{
		x=get(x);y=get(y);
		esiz[y]++;if(x==y)return;
		esiz[y]+=esiz[x];nsiz[y]+=nsiz[x];fa[x]=y;
	}
}S;
struct poly
{
	vector<int>v;
	int& operator[](const int &i){return v[i];}
	void set(int l){v.resize(l);}
	int len(){return v.size();}
	poly operator *(poly x)
	{
		poly ret;ret.set(len()+x.len()-1);
		for(int i=0;i<len();i++)
			for(int j=0;j<x.len();j++)
				(ret[i+j]+=(ll)v[i]*x[j]%mod)%=mod;
		return ret;	
	}
};
int s[maxn][maxn],down[maxn][maxn],c[maxn][maxn];
void prework()
{
	s[0][0]=1;for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)s[i][j]=((ll)s[i-1][j]*(i-1)%mod+s[i-1][j-1])%mod;
	for(int i=0;i<=n;i++){c[i][0]=1;for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;}
	for(int i=0;i<=n;i++){down[i][0]=1;for(int j=1;j<=i;j++)down[i][j]=(ll)down[i][j-1]*(i-j+1)%mod;}
}
bool vis[maxn];
int main()
{
	n=read();generate_n(p+1,n,read);generate_n(q+1,n,read);
	for(int i=1;i<=n;i++)if(p[i])pos[p[i]]=i;
	S.prework();
	for(int i=1;i<=n;i++)if(p[i]&&q[i])S.merge(p[i],q[i]);
	for(int i=1;i<=n;i++){int now=S.get(i);if(!S.vis[now]&&S.esiz[now]==S.nsiz[now])S.vis[now]=true,bas++;}
	for(int i=1;i<=n;i++)
	{
		if(!p[i]&&q[i])
		{
			int now=q[i];
			while(pos[now]&&q[pos[now]])now=q[pos[now]];
			if(!pos[now])cnt1++;
			else if(!q[pos[now]])cnt2++,vis[pos[now]]=true;
		}
		if(!p[i]&&!q[i])cnt2++;
	}
	for(int i=1;i<=n;i++)if(p[i]&&!q[i]&&!vis[i])cnt0++;
	prework();
	poly f,g,h;
	f.set(n+1);g.set(n+1);h.set(n+1);
	for(int i=0;i<=n;i++)for(int j=i;j<=cnt0;j++)(f[i]+=(ll)c[cnt0][j]*s[j][i]%mod*(cnt0-j?down[cnt0+cnt2-j-1][cnt0-j]:1)%mod)%=mod;
	for(int i=0;i<=n;i++)for(int j=i;j<=cnt1;j++)(g[i]+=(ll)c[cnt1][j]*s[j][i]%mod*(cnt1-j?down[cnt1+cnt2-j-1][cnt1-j]:1)%mod)%=mod;
	int v=1;
	for(int i=1;i<=cnt2;i++)v=(ll)v*i%mod;
	for(int i=0;i<=n;i++)h[i]=(ll)s[cnt2][i]*v%mod;
	f=f*g*h;
	for(int i=0;i<=n-1;i++)printf("%d ",n-i-bas>=0?f[n-i-bas]:0);putchar('\n');
	return 0;
}