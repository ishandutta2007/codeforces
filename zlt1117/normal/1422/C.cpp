#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define rd (rand()<<16^rand())
using namespace std;
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e5+5,mod=1e9+7;
char s[maxn];
ll len;
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	ll temp=0,sum=0,ten=1;
	FOR(i,1,len)temp+=s[i]-'0';
	for(ll i=len;i>=1;--i)
	{
		temp-=s[i]-'0';
		sum+=(temp*(len-i+1))%mod*ten%mod;
		sum+=((s[i]-'0')*i*(i-1)/2)%mod*ten%mod;
		sum%=mod;
		ten=(ten<<3)+(ten<<1);
		ten%=mod;
	}
	printf("%lld\n",sum%mod);
	return 0;
}