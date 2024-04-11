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
const int maxn=4e3+5;
int mod;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
class mint
{
	public:
	int v;
	mint():v(0){}
	mint(int _v):v(_v){}
	mint& operator +=(const mint &rhs){v+=rhs.v;if(v>=mod)v-=mod;return *this;}
	mint& operator -=(const mint &rhs){v-=rhs.v;if(v<0)v+=mod;return *this;}
	mint& operator *=(const mint &rhs){v=(ll)v*rhs.v%mod;return *this;}
	mint& operator /=(const mint &rhs){v=(ll)v*rhs.inv()%mod;return *this;}
	mint operator -(){return v?mod-v:0;}
	friend mint operator +(const mint &lhs,const mint &rhs){return (mint)lhs+=rhs;}
	friend mint operator -(const mint &lhs,const mint &rhs){return (mint)lhs-=rhs;}
	friend mint operator *(const mint &lhs,const mint &rhs){return (mint)lhs*=rhs;}
	friend mint operator /(const mint &lhs,const mint &rhs){return (mint)lhs/=rhs;}
	int inv()const{return qpow(v,mod-2);}
};
int n,p;
class graph
{
	private:
	vector<int>e[maxn];
	public:
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	mint f[maxn][maxn],s[maxn][maxn],d[maxn][maxn];
	void dfs(int u,int fa=0)
	{
		static int ctz[maxn];
		for(int &i:e[u])if(i!=fa)dfs(i,u);
		for(int i=1;i<=n-1;i++)
		{
			d[u][i]=1;
			for(int &j:e[u])if(j!=fa)
			{
				if(s[j][i].v==0)ctz[i]++;
				else d[u][i]*=s[j][i];
			}
		}
		for(int i=1;i<=n-1;i++)f[u][i]=ctz[i]?0:d[u][i];
		if(u!=1)
			for(int &i:e[u])
				if(i!=fa)
				{
					mint sum=0;
					for(int j=1;j<=n-1;j++)
					{
						if(j>1&&ctz[j-1]<=1)
						{
							if(ctz[j-1]==1)sum+=s[i][j-1].v==0?d[u][j-1]:0;
							else sum+=d[u][j-1]/s[i][j-1];
						}
						f[u][j]+=sum*f[i][j];
					}
				}
		partial_sum(f[u]+1,f[u]+n,s[u]+1);
		for(int i=1;i<=n-1;i++)ctz[i]=0;
	}
}o;
mint fac[maxn],inv[maxn];
mint C(int n,int m){return fac[n]*inv[m]*inv[n-m];}
int main()
{
	n=read();mod=read();
	for(int i=1;i<n;i++)o.add(read(),read());
	o.dfs(1);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i;
	inv[n]=fac[n].inv();for(int i=n-1;i>=0;i--)inv[i]=inv[i+1]*(i+1);
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<i;j++)o.f[1][i]-=o.f[1][j]*C(i,j);
	for(int i=1;i<=n-1;i++)printf("%d ",o.f[1][i].v);putchar('\n');
	return 0;
}