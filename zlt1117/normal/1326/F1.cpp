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
const int maxn=20;
int n;
char s[20][20];
ll dp[maxn][(1<<18)+5];
ll g[maxn][(1<<18)+5],t[maxn][(1<<18)+5],cnt[(1<<18)+5];///chain,the set of chain
inline void FWT(ll *a,int n)
{
	for(int l=1;l<(1<<n);l<<=1)
	{
		for(int i=0;i<(1<<n);i+=l<<1)
		{
			for(int j=0;j<l;++j)a[i+j+l]=(a[i+j+l]+a[i+j]);
		}
	}
}
inline void IFWT(ll *a,int n)
{
	for(int l=1;l<(1<<n);l<<=1)
	{
		for(int i=0;i<(1<<n);i+=l<<1)
		{
			for(int j=0;j<l;++j)a[i+j]=(a[i+j]-a[i+j+l]);
		}
	}
}
inline void input()
{
	n=gi();
	FOR(i,0,n-1)scanf("%s",s[i]);
	FOR(i,1,(1<<n)-1)cnt[i]=cnt[i>>1]+(i&1);
	FOR(i,0,(1<<n)-1)t[0][i]=1;///prefix sum
	FOR(i,0,n-1)dp[i][(1<<i)]=1;
	FOR(i,0,(1<<n)-1)FOR(j,0,n-1)if(i>>j&1)FOR(k,0,n-1)if(s[j][k]=='1'&&!(i>>k&1))dp[k][i|(1<<k)]+=dp[j][i];
	FOR(i,0,n-1)FOR(j,0,(1<<n)-1)g[cnt[j]][j]+=dp[i][j];
	FOR(i,0,n-1)FWT(g[i],n);
}
map<vector<int>,ll>mp;
vector<int>cur;
inline void dfs(int step,int st,int res)///partition
{
	if(!res)
	{
		ll sum=0;
		FOR(i,0,(1<<n)-1)sum+=1ll*(cnt[i^((1<<n)-1)]&1?-1:1)*t[step][i];
		//puts(":");for(int x:cur)printf("%d ",x);printf("%lld\n",sum);
		return mp[cur]=sum,void();
	}
	FOR(i,st,res)
	{
		cur.pb(i);
		FOR(j,0,(1<<n)-1)t[step+1][j]=1ll*t[step][j]*g[i][j];
		dfs(step+1,i,res-i);
		cur.pop_back();
	}
}
ll ans[(1<<18)+6];
inline ll count(int x)
{
	vector<int>now;
	int cnt=1;
	FOR(i,1,n)
	{
		if(x>>(i-1)&1)cnt++;
		else
		{
			now.pb(cnt);
			cnt=1;
		}
	}
	now.pb(cnt);
	sort(now.begin(),now.end());
	return mp[now];
}
inline void solve()
{
	dfs(0,1,n);n--;///sum--
	FOR(i,0,(1<<n)-1)
	ans[i]=count(i);
	IFWT(ans,n);
	FOR(i,0,(1<<n)-1)printf("%lld%c",ans[i]," \n"[i==(1<<n)-1]);
}
int main()
{
	input();
	solve();
	return 0;
}