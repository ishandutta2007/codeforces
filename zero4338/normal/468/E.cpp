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
const int mod=1e9+7,maxn=105,maxm=1e6+5;
class mint
{
	public:
	int v;
	mint()=default;
	mint(int _v):v(_v){}
	mint& operator +=(const mint &rhs){v+=rhs.v;if(v>=mod)v-=mod;return *this;}
	mint& operator -=(const mint &rhs){v-=rhs.v;if(v<0)v+=mod;return *this;}
	mint& operator *=(const mint &rhs){v=(ll)v*rhs.v%mod;return *this;}
	mint& operator /=(const mint &rhs){v=(ll)v*rhs.inv().v%mod;return *this;}
	friend mint qpow(mint a,int b){mint ret=1;for(;b;b>>=1,a*=a)if(b&1)ret*=a;return ret;}
	mint inv()const{return qpow(*this,mod-2);}
	friend mint operator +(const mint &lhs,const mint &rhs){return (mint)lhs+=rhs;}
	friend mint operator -(const mint &lhs,const mint &rhs){return (mint)lhs-=rhs;}
	friend mint operator *(const mint &lhs,const mint &rhs){return (mint)lhs*=rhs;}
	friend mint operator /(const mint &lhs,const mint &rhs){return (mint)lhs/=rhs;}
};
int n,k;
struct point{int x,y,w;}p[maxn];
int cx,cy;
vector<pair<int,int>>add[maxn];
int cnt[maxn],id[maxn],siz;
void discrete()
{
	static int num[maxn];
	for(int i=1;i<=k;i++)num[i]=p[i].x;
	sort(num+1,num+k+1);cx=unique(num+1,num+k+1)-(num+1);
	for(int i=1;i<=k;i++)p[i].x=lower_bound(num+1,num+cx+1,p[i].x)-num-1;
	for(int i=1;i<=k;i++)num[i]=p[i].y;
	sort(num+1,num+k+1);cy=unique(num+1,num+k+1)-(num+1);
	for(int i=1;i<=k;i++)p[i].y=lower_bound(num+1,num+cy+1,p[i].y)-num-1;
}
mint fac[maxm];
int pre[maxn],suf[maxn];
int main()
{
	n=read();k=read();
	for(int i=1;i<=k;i++)p[i].x=read(),p[i].y=read(),p[i].w=(read()-1+mod)%mod;
	discrete();
	for(int i=1;i<=k;i++)cnt[p[i].x]++;
	memset(id,-1,sizeof id);
	for(int i=0;i<cx;i++)if(cnt[i]>=2)id[i]=siz++;
	for(int i=1;i<=k;i++)add[p[i].y].emplace_back(id[p[i].x],p[i].w);
	vector<vector<mint>>f;f.resize(1);f[0].resize(1);
	f[0][0]=1;
	for(int i=0;i<cy;i++)
	{
		int now=0,pre=0,suf=0;
		for(auto&[p,w]:add[i])if(p!=-1)now|=1<<p;
		for(int j=0;j<i;j++)for(auto&[p,w]:add[j])if(p!=-1)pre|=1<<p;
		for(int j=i+1;j<cy;j++)for(auto&[p,w]:add[j])if(p!=-1)suf|=1<<p;
		now|=pre&suf;
		static int lto[maxn],nid[maxn];
		int top=0;
		for(int j=0;j<siz;j++)if(now>>j&1)nid[j]=top++;else nid[j]=-1;
		vector<vector<mint>>g;
		g.resize(1<<top);
		for(auto&j:g)j.resize(cx-top+1);
		for(int i=0;i<f.size();i++)
		{
			int to=0,del=0;
			for(int j=0;j<siz;j++)if(i>>j&1){if(nid[lto[j]]==-1)del++;else to|=1<<nid[lto[j]];}
			for(int j=0;j<f[i].size();j++)if(f[i][j].v)g[to][j+del]+=f[i][j];
		}
		for(int i=0;i<siz;i++)if(nid[i]!=-1)lto[nid[i]]=i;
		swap(f,g);
		for(int j=(1<<top)-1;j>=0;j--)
			for(int k=(int)f[j].size()-1;k>=0;k--)
				if(f[j][k].v)
					for(auto&[p,w]:add[i])
					{
						if(p==-1||nid[p]==-1)
						{
							if(f[j].size()<=k+1)f[j].resize(k+2);
							f[j][k+1]+=f[j][k]*w;
						}
						else if(!(j>>nid[p]&1))
						{
							if(f[j|(1<<nid[p])].size()<=k)f[j|(1<<nid[p])].resize(k+1);
							f[j|(1<<nid[p])][k]+=f[j][k]*w;
						}
					}
	}
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i;
	mint ans=0;
	for(int i=0;i<f.size();i++)for(int j=0;j<f[i].size();j++)if(f[i][j].v)ans+=f[i][j]*fac[n-__builtin_popcount(i)-j];
	printf("%d\n",ans.v);
	return 0;
}