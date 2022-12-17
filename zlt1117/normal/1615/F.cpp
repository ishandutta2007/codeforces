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
const int maxn=4005,mod=1e9+7,M=2001;
int n,dp[2][maxn],now,last,a[maxn],ans[2][maxn];
char s[maxn],t[maxn];
inline void init()
{
	now=last=0;
	memset(dp,0,sizeof(dp));
	memset(ans,0,sizeof(ans));
}
inline void input()
{
	n=gi();
	scanf("%s%s",s+1,t+1);
	FOR(i,1,n)if((i&1)&&(s[i]!='?'))s[i]='0'+'1'-s[i];
	FOR(i,1,n)if((i&1)&&(t[i]!='?'))t[i]='0'+'1'-t[i];
}
inline void solve()
{
	dp[0][M]=1;
	FOR(i,1,n)
	{
		now=now^1,last=now^1;
		memset(dp[now],0,sizeof(dp[now]));
		memset(ans[now],0,sizeof(ans[now]));
		for(int j=M-i;j<=M+i;++j)
		{
			if(dp[last][j]==0)continue;
			for(int x:{0,1})
			{
				if(x==0&&s[i]=='1')continue;
				if(x==1&&s[i]=='0')continue;
				for(int y:{0,1})
				{
					if(y==0&&t[i]=='1')continue;
					if(y==1&&t[i]=='0')continue;
					dp[now][j+x-y]=(dp[now][j+x-y]+dp[last][j])%mod;
					ans[now][j+x-y]=(ans[now][j+x-y]+ans[last][j]+1ll*abs(j+x-y-M)*dp[last][j])%mod;
				}
			}
		}
	}
	printf("%d\n",ans[now][M]);
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}