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
const int mod=1e9+7,maxn=2e6+5;
int a[maxn],n;
int ans1,ans2,fac[maxn],sum,M=1e6;
int cnt[maxn];
inline void input()
{
	ans2=1;
	n=gi();fac[0]=fac[1]=1;
	FOR(i,2,n)fac[i]=1ll*fac[i-1]*i%mod;
	FOR(i,1,n)a[i]=gi(),cnt[a[i]-1+M]++,cnt[-1-a[i]+M]--,sum+=a[i],sum%=mod;
}
inline void solve()
{
	for(int i=M;i>=-M;--i)
	{
		cnt[i+M]+=cnt[i+M+2];
		ans2=1ll*ans2*fac[cnt[i+M]]%mod;
		ans1=(ans1+1ll*(sum+sum-cnt[i+M]+1)*cnt[i+M]/2%mod*i%mod)%mod;	
		ans1=(ans1+mod)%mod;
		sum-=cnt[i+M];sum=(sum+mod)%mod;
	} 
	printf("%d %d\n",ans1,ans2);
}
int main()
{
	input();
	solve();
	return 0;
}