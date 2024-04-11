#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=2e7+5;
int c,d,x;
ll ans;
int p[maxn],cnt,num[maxn];bool vis[maxn];
void prework()
{
	int n=2e7;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])p[++cnt]=i,num[i]=1;
		for(int j=1;j<=cnt&&p[j]*i<=n;j++)
		{
			vis[i*p[j]]=1;
			num[i*p[j]]=num[i];
			if(i%p[j]==0)break;
			num[i*p[j]]++;
		}
	}
}
int main()
{
	T=read();prework();
	while(T--)
	{
		c=read(),d=read(),x=read();ans=0;
		for(int i=1;i<=x/i;i++)
		{
			if(x%i)continue;
			if((x/i+d)%c==0)ans+=1<<num[(x/i+d)/c];
			if(i*i!=x&&(i+d)%c==0)ans+=1<<num[(i+d)/c];
		}
		printf("%lld\n",ans);
	}
	return 0;
}