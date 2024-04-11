#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1000000007;
char s[100010];
char t[100010];
int fail[100010];
ll f[100010];
ll g[100010];
int b[100010];
int main()
{
	memset(b,0,sizeof(b));
	int n,m;
	scanf("%s%s",s+1,t+1);
	int i;
	n=strlen(s+1);
	m=strlen(t+1);
	fail[1]=0;
	for(i=2;i<=m;i++)
	{
		fail[i]=fail[i-1];
		while(fail[i]&&t[fail[i]+1]!=t[i])
			fail[i]=fail[fail[i]];
		if(t[fail[i]+1]==t[i])
			fail[i]++;
	}
	int j=0;
	for(i=1;i<=n;i++)
	{
		while(j&&s[i]!=t[j+1])
			j=fail[j];
		if(s[i]==t[j+1])
			j++;
		if(j==m)
		{
			b[i]=1;
			j=fail[j];
		}
	}
	f[0]=0;
	g[0]=0;
	int last=-1;
	for(i=1;i<=n;i++)
	{
		if(b[i])
			last=i-m;
		f[i]=f[i-1];
		if(~last)
			f[i]=(f[i]+g[last]+last+1)%mod;
		g[i]=(g[i-1]+f[i])%mod;
	}
	printf("%I64d\n",f[n]);
	return 0;
}