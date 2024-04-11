#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll fp(ll a,ll b)
{
	ll s=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)
			s=s*a%mod;
	return s;
}
ll len[11];
ll to[11];
char s[100010];
vector<int> a[100010];
int c[100010];
char s2[100010];
int main()
{
//	freopen("cf464c.in","r",stdin);
//	freopen("cf464c.out","w",stdout);
	scanf("%s",s+1);
	int i,n,j,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		s2[1]='\0';
		scanf("%d->%[^\n]",&c[i],s2+1);
		m=strlen(s2+1);
		for(j=1;j<=m;j++)
			a[i].push_back(s2[j]-'0'); 
	}
	for(i=0;i<=9;i++)
	{
		len[i]=1;
		to[i]=i;
	}
	for(i=n;i>=1;i--)
	{
		ll v1=0,v2=0;
		m=a[i].size();
		for(j=m-1;j>=0;j--)
		{
			int v=a[i][j];
			v2+=fp(10,v1)*to[a[i][j]];
			v1+=len[a[i][j]];
			v2%=mod;
			v1%=(mod-1);
		}
		len[c[i]]=v1;
		to[c[i]]=v2;
	}
	ll ans1=0,ans2=0;
	m=strlen(s+1);
	for(i=m;i>=1;i--)
	{
		ans2+=fp(10,ans1)*to[s[i]-'0'];
		ans1+=len[s[i]-'0'];
		ans2%=mod;
		ans1%=(mod-1);
	}
	printf("%I64d\n",ans2);
	return 0;
}