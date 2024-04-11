//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int block=400,maxn=2e5+5,mod=1e9+7;
int q;
int n,a[maxn];
map<int,int>mpp[maxn];
set<int>s[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();q=gi();
	FOR(i,1,n)a[i]=gi();
}
vector<int>prime;
bool vis[505];
int mp[505];
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	int minv[maxn<<2],id;
	inline void pushup(int u)
	{
		minv[u]=min(minv[ls],minv[rs]);
	}
	inline void build(int u,int l,int r)
	{
		if(l==r)
		{
			int cnt=0;
			while(a[l]%prime[id]==0)cnt++,a[l]/=prime[id];
			minv[u]=cnt;
			return ;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(u);
	}
	inline void update(int u,int l,int r,int x,int v)
	{
		if(l==r)return minv[u]+=v,void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,v);
		else update(rs,mid+1,r,x,v);
		pushup(u);
	}
}tree[60];
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*x*ret%mod;
		k>>=1;x=1ll*x*x%mod;
	}
	return ret;
}
inline void solve()
{
	FOR(i,2,500)
	{
		if(!vis[i])prime.pb(i);
		FOR(j,1,500)
		{
			if(i*j>500)break;
			vis[i*j]=1;
		}
	}
	FOR(i,0,sz(prime)-1)mp[prime[i]]=i;
	int sum=0;
	FOR(i,1,n)
	{
		int x=a[i],now=1;
		FOR(k,0,sz(prime)-1)
		{
			int j=prime[k],cnt=0;
			if(x%j==0)
			{
				while(x%j==0)x/=j,cnt++;
				if(j>=283)mpp[i][j]=cnt,now=1ll*now*qpow(j,cnt),s[j].insert(i);
			}
		}
		if(x!=1)mpp[i][x]=1,s[x].insert(i);
		sum=__gcd(sum,now*x);
	}
	int ans=1;
	if(sum!=1&&sum!=0)
	{
		ans=sum;
		if((int)sqrt(sum)*(int)sqrt(sum)==sum)sum/=sqrt(sum);
		s[sum].clear();
		int maxv=1e9;
		FOR(i,1,n)maxv=min(maxv,mpp[i][sum]);
		FOR(i,1,n)
		{
			mpp[i][sum]-=maxv;
			if(mpp[i][sum]!=0)s[sum].insert(i);
		}
	}
	FOR(i,0,sz(prime)-1)if(i<=59)tree[i].id=i,tree[i].build(1,1,n); 
	while(q--)
	{
		int x=gi(),v=gi();
		FOR(i,0,sz(prime)-1)
		{
			int counter=0;
			while(v%prime[i]==0)counter++,v/=prime[i];
			if(counter&&i<=59)tree[i].update(1,1,n,x,counter);
			else if(counter)
			{
				int v=prime[i];
				mpp[x][v]+=counter;
				s[v].insert(x);
				if(sz(s[v])==n)
				{
					s[v].clear();
					int maxv=1e9;
					FOR(i,1,n)maxv=min(maxv,mpp[i][v]);
					FOR(i,1,n)
					{
						mpp[i][v]-=maxv;
						if(mpp[i][v]!=0)s[v].insert(i);
					}
					ans=1ll*ans*qpow(v,maxv)%mod;
				}
			}
		}
		if(v!=1)
		{
			mpp[x][v]++;
			s[v].insert(x);
			if(sz(s[v])==n)
			{
				s[v].clear();
				int maxv=1e9;
				FOR(i,1,n)maxv=min(maxv,mpp[i][v]);
				FOR(i,1,n)
				{
					mpp[i][v]-=maxv;
					if(mpp[i][v]!=0)s[v].insert(i);
				}
				ans=1ll*ans*qpow(v,maxv)%mod;
			}
		}
		int sum=ans;
		FOR(i,0,59)sum=1ll*sum*qpow(prime[i],tree[i].minv[1])%mod;
		printf("%d\n",sum);
	}
}
int main()
{
	int T=1;
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}

/*
2 2
1 1
1 199999
1 199999
*/