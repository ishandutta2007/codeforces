#pragma GCC optimize("Ofast")
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
const int maxn=105;
int dp[(1<<10)+5][100];
pair<int,int> pre[(1<<10)+5][100];
map<char,int>mp,mp2;
int n,pos[maxn][maxn][2];
inline void init()
{
	memset(dp,0,sizeof(dp));
	memset(pre,0,sizeof(pre));
	memset(pos,-1,sizeof(pos));
}
string s[maxn];
inline void input()
{
	n=gi();
	FOR(i,1,n)cin>>s[i];
	FOR(i,1,n)
	{
		FOR(j,0,sz(s[i])-1)
		{
			int x=mp[s[i][j]];
			if(pos[i][x][0]!=-1)pos[i][x][1]=j;
			else pos[i][x][0]=j;
		}
	}
}
int nxt[53][(1<<10)][53];
inline void solve()
{
	FOR(i,1,52)
	{
		bool ok=1;
		FOR(j,1,n)
		if(pos[j][i][0]==-1)ok=0;
		if(ok)dp[0][i]=1;
	}
	FOR(i,1,52)
	{
		FOR(j,0,(1<<n)-1)
		{
			FOR(k,1,52)
			{
				int S=0,ok=1;
				FOR(t,1,n)
				{
					int p=0;
					if(j>>(t-1)&1)p=pos[t][i][1]==-1?100:pos[t][i][1];
					else p=pos[t][i][0]==-1?100:pos[t][i][0];
					int p2=pos[t][k][0];
					if(p2>p)continue;
					if(pos[t][k][1]>p)S|=(1<<(t-1));
					else {ok=0;break;}
				}
				if(ok)nxt[i][j][k]=S;
				else nxt[i][j][k]=-1;
			}
		}
	}
	FOR(tt,0,104)
	{
		bool okk=0;
		FOR(i,1,52)
		{	
			FOR(j,0,(1<<n)-1)
			{
				FOR(k,1,52)
				{
					int S=nxt[i][j][k];
					if(S!=-1&&dp[j][i]+1>dp[S][k])okk=1,dp[S][k]=max(dp[S][k],dp[j][i]+1),pre[S][k]={j,i};
				}
			}
		}
		if(!okk)break;
	}
	int ans=0;pair<int,int>p;
	vector<char>vec(1);
	FOR(i,0,(1<<n)-1)FOR(j,1,52)
	{
		if(dp[i][j]>ans)
		{
			ans=dp[i][j];
			p=pre[i][j];
			vec[0]=mp2[j];
		}
	}
	while(p.second)vec.pb(mp2[p.second]),p=pre[p.first][p.second];
	printf("%d\n",ans);
	if(ans==0)return puts(""),void(); 
	reverse(vec.begin(),vec.end());
	for(char x:vec)printf("%c",x);
	puts("");
}
int main()
{
	FOR(i,1,26)mp[i+'a'-1]=i,mp2[i]=i+'a'-1;
	FOR(i,1,26)mp[i+'A'-1]=i+26,mp2[i+26]=i+'A'-1;
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}