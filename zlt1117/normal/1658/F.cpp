//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()
#define mk make_pair
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
const int maxn=2e5+5;
int n,k;
char s[maxn];
int cnt[maxn];
inline void init()
{
	
}
inline void input()
{
	n=gi(),k=gi();
	scanf("%s",s+1);
	FOR(i,1,n)cnt[i]=cnt[i-1]+(s[i]=='1');
}
inline void solve()
{
	int tn=n/__gcd(n,k);
	if(cnt[n]%tn!=0)return puts("-1"),void();
	int m=1ll*cnt[n]*k/n;
	FOR(i,k,n)
	{
		if(cnt[i]-cnt[i-k]==m)
		{
			puts("1");
			printf("%d %d\n",i-k+1,i);
			return ;
		}
	}
	FOR(i,n-k,n-1)
	{
		if(cnt[n]-cnt[i]+cnt[k-(n-i)]==m)
		{
			puts("2");
			printf("%d %d\n %d %d\n",1,k-(n-i),i+1,n);
			return ;
		}
	}
	assert(0);
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