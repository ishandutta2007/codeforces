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
const int maxn=17;
int dp[maxn][maxn][(1<<15)+1];
pair<int,int>pre[maxn][maxn][(1<<15)+1];
int n,a[maxn],sum[(1<<15)+1];
bool del[maxn];
int id[(1<<15)+1];
inline void init()
{
	FOR(i,0,(1<<n)-1)sum[i]=id[i]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,0,(1<<n)-1)FOR(j,0,n-1)if(i>>j&1)sum[i]+=a[j+1];
	FOR(i,0,(1<<n)-1)id[i]=i;
	sort(id,id+(1<<n),[&](int x,int y){return sum[x]<sum[y];});
	FOR(i,0,n)FOR(j,0,n+1)FOR(k,0,(1<<n)-1)dp[i][j][k]=1e9,pre[i][j][k]={0,0};
}
inline void solve()
{
	dp[0][0][0]=0;
	int l=1,m=(1<<n)-1;
	while(l<=(1<<n)-1)
	{
		int r=l;
		while(r<m&&sum[id[r+1]]==sum[id[l]])r++;
		for(int i=n-1;i>=0;--i)
		{
			FOR(j,i,n)///++
			{
				FOR(kk,l,r)
				{
					int now=id[kk];
					if(j!=0&&(now>>(j-1)&1))continue;
					int S=((1<<n)-1)^now,t=S;int x=0;
					FOR(k,j,n-1)if(now>>k&1){x=k+1;break;}
					if(x==0)continue;
					while(1)
					{
						if(dp[i][j][S]>n)
						{
							if(S==0)break;
							S=(S-1)&t;
							continue;
						}
						int val=dp[i][j][S]+__builtin_popcount(now)-1;
						if(val<dp[i+1][x][S|now])
						{
							dp[i+1][x][S|now]=val;
							pre[i+1][x][S|now]={j,S};
						}
						if(S==0)break;
						S=(S-1)&t;
					}
				}
			}
		}
		l=r+1;
		//cerr<<l<<' '<<r<<endl;
	}
	int nowans=1e9,p1=0,p2=0,S=m;
	FOR(i,0,n)FOR(j,1,n)
	if(dp[i][j][m]<nowans)nowans=dp[i][j][m],p1=i,p2=j;
	printf("%d\n",nowans);
	vector<pair<int,int>>vec;
	while(S)
	{
		int np1=p1-1,np2=pre[p1][p2][S].first,nS=pre[p1][p2][S].second;
		int now=S^nS;
		FOR(i,0,n-1)if((now>>i&1)&&i+1!=p2)vec.pb({i+1,p2});
		p2=np2,p1=np1,S=nS;
	}
	FOR(i,1,n)del[i]=0;
	for(auto x:vec)
	{
		int a=x.first,b=x.second,ans1=0,ans2=0;
		FOR(i,1,a)if(!del[i])ans1++;
		FOR(i,1,b)if(!del[i])ans2++;
		printf("%d %d\n",ans1,ans2);
		del[a]=1;
	}
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