#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
inline void init(){}
const int maxn=1e5+5,mod=1e9+7;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
struct XXJ
{
	static const int maxn=20,M=18;
	int a[maxn],size;
	inline void insert(int x)
	{
		for(int i=M;i>=0;--i)
		{
			if(!(x>>i&1))continue;
			if(a[i])x^=a[i];
			else
			{
				a[i]=x;
				size++;
				return ;
			}
		}
	}
}xxj;
int pw[maxn],n,a[maxn];
inline void input()
{
	n=gi();
	pw[0]=1;
	FOR(i,1,n)pw[i]=1ll*pw[i-1]*2%mod;
}
inline void solve()
{
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n)
	{
		int x=a[i];a[i]=0;
		FOR(j,0,18)
		{
			int cnt=0;
			while(x%prime[j]==0)cnt++,x/=prime[j];
			cnt&=1;a[i]|=cnt<<j;
		}
		xxj.insert(a[i]);
	}
	int ans=pw[n-xxj.size]+mod-1;
	ans%=mod;
	printf("%d\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}