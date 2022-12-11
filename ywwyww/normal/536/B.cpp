#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
char s[1000010];
int nxt[1000010];
int a[1000010];
ll mod=1000000007;
ll pow(ll a,ll b)
{
	ll s=1;
	while(b)
	{
		if(b&1)
			s=s*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return s;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int len;
	scanf("%s",s+1);
	len=strlen(s+1);
	int k,p,i,j;
	nxt[1]=len;
	for(i=2,j=-1;i<=n;i++,j--)
		if(j<0||i+nxt[i-k+1]-1>=p)
		{
			if(j<0)
			{
				j=0;
				p=i-1;
			}
			while(p<n&&s[p+1]==s[j+1])
			{
				p++;
				j++;
			}
			nxt[i]=j;
			k=i;
		}
		else
			nxt[i]=nxt[i-k+1];
	ll ans=0;
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(i=2;i<=m;i++)
		if(a[i]-a[i-1]+1<=len&&nxt[a[i]-a[i-1]+1]<=len-a[i]+a[i-1]-1)
		{
			printf("0\n");
			return 0;
		}
	if(!m)
		ans=n;
	else
	{
		ans=a[1]-1;
		for(i=2;i<=m;i++)
			if(a[i]-a[i-1]+1>len)
				ans+=a[i]-a[i-1]+1-len-1;
		ans+=n-a[m]-len+1;
	}
	printf("%I64d\n",pow(26,ans));
	return 0;
}