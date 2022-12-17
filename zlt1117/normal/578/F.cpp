//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline void chkmax(int &x,int y){if(x<y)x=y;}
inline void chkmin(int &x,int y){if(x>y)x=y;}
int mod;
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*ret*x%mod;
		k>>=1,x=1ll*x*x%mod;
	}
	return ret;
}
inline int det(vector<int>*a,int n)
{
	//FOR(j,1,n)FOR(k,1,n)printf("%d%c",a[j][k]," \n"[k==n]);
	int ans=1;
	FOR(i,1,n-1)
	{
		int now=i;
		FOR(j,i,n-1)if(a[j][i]){now=j;break;}
		if(now!=i)swap(a[now],a[i]),ans=(mod-ans)%mod;
		if(a[i][i]==0)return 0;
		ans=1ll*ans*a[i][i]%mod;
		int inv=qpow(a[i][i],mod-2);
		FOR(j,i,n-1)a[i][j]=1ll*a[i][j]*inv%mod;
		FOR(j,i+1,n-1)
		{
			int t=a[j][i];
			FOR(k,i,n)a[j][k]=(a[j][k]-1ll*t*a[i][k]%mod+mod)%mod;
		}
	}
	return ans;
}
const int maxn=505;
char s[maxn][maxn];
int id[maxn][maxn],cnt;
int fa[maxn*maxn],n,m,now[maxn];
inline void init()
{

}
inline int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
inline void input()
{
	n=gi(),m=gi(),mod=gi();
	FOR(i,1,n)scanf("%s",s[i]+1);
	FOR(i,1,n+1)FOR(j,1,m+1)id[i][j]=++cnt,fa[id[i][j]]=id[i][j];
}
int ans;
inline int count(vector<int>&nodes,int t)
{
	//for(int x:nodes)printf("%d ",x);
	//puts("");
	vector<int>a[maxn];
	map<int,int>mp;
	FOR(i,0,sz(nodes)-1)mp[nodes[i]]=i+1;
	FOR(i,0,sz(nodes))a[i].resize(sz(nodes)+1);
	FOR(i,1,n)FOR(j,1,m)
	{
		if(s[i][j]=='*')
		{
			int u=0,v=0;
			u=id[i][j],v=id[i+1][j+1];
			if(((i+j)&1)!=t)u=id[i][j+1],v=id[i+1][j];
			u=get(u),v=get(v);
			if(u==v)continue;
			else 
			{
				u=mp[u],v=mp[v];
				a[u][v]=(a[u][v]+mod-1)%mod;
				a[v][u]=(a[v][u]+mod-1)%mod;
				a[u][u]++,a[v][v]++;
			}
		}
	}
	return det(a,sz(nodes));
}
inline void solve()
{
	FOR(i,1,n)FOR(j,1,m)
	{
		if(s[i][j]=='/')
		{
			int u=id[i][j+1],v=id[i+1][j];
			if(get(u)==get(v))return puts("0"),void();
			fa[get(u)]=get(v);
		}
		else if(s[i][j]=='\\')
		{
			int u=id[i][j],v=id[i+1][j+1];
			if(get(u)==get(v))return puts("0"),void();
			fa[get(u)]=get(v);
		}
	}
	vector<int>v1,v2;
	FOR(i,1,n+1)FOR(j,1,m+1)
	{
		if(get(id[i][j])==id[i][j])
		{
			if((i+j)&1)v1.pb(id[i][j]);
			else v2.pb(id[i][j]);
		}
	}
	ans=(count(v1,1)+count(v2,0))%mod;
	printf("%d\n",ans);
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}