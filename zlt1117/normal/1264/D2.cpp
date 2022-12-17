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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e6+5,mod=998244353;
int n,prel[maxn],sufr[maxn],fac[maxn],inv[maxn],suml[maxn],sumr[maxn];
char s[maxn]; 
inline int C(int n,int m)
{
	if(n<m||n<0||m<0)return 0;
	return 1ll*fac[n]*inv[n-m]%mod*inv[m]%mod;
}
inline void input()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	fac[1]=fac[0]=inv[0]=inv[1]=1;
	FOR(i,2,n)fac[i]=1ll*i*fac[i-1]%mod,inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,2,n)inv[i]=1ll*inv[i-1]*inv[i]%mod;
}
inline void solve()
{
	FOR(i,1,n)prel[i]=prel[i-1]+(s[i]=='(');
	for(int i=n;i>=1;--i)sufr[i]=(sufr[i+1]+(s[i]==')'));
	FOR(i,1,n)suml[i]=(suml[i-1]+(s[i]=='?'));
	for(int i=n;i>=1;--i)sumr[i]=(sumr[i+1]+(s[i]=='?'));
	int ans=0;
	FOR(i,1,n)
	{
		int sum=1ll*prel[i]*C(suml[i]+sumr[i+1],sumr[i+1]+sufr[i+1]-prel[i])%mod;
		sum=(sum+1ll*suml[i]*C(suml[i]+sumr[i+1]-1,sumr[i+1]+sufr[i+1]-prel[i]-1))%mod;
		//cerr<<sum<<endl;
		ans=(ans+sum)%mod;	
	} 
	printf("%d\n",ans);
}
int main()
{
	input();
	solve();
	return 0;
}