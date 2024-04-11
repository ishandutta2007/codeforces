#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
mt19937_64 rnd((ull)(new int));
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e6+5;
int n;
vector<int>ban;
vector<int>solve(int n)
{
	if(n<=1)return {};
	if(n%4==0)return {n/2};
	if(n%2==0)return {2,n/2};
	vector<int>ret=solve(n-1);ret.push_back(n);
	return ret;
}
bool vis[maxn];
ull val[maxn];
int main()
{
	n=read();
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			val[i]=rnd();
			for(int j=i*2;j<=n;j+=i)
			{
				vis[j]=1;
				int now=j;
				while(now%i==0)val[j]^=val[i],now/=i;
			}
		}
	}
	for(int i=1;i<=n;i++)val[i]^=val[i-1];
	ull sum=0;
	for(int i=1;i<=n;i++)sum^=val[i];
	if(sum==0)
	{
		printf("%d\n",n);
		for(int i=1;i<=n;i++)printf("%d ",i);putchar('\n');
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(val[i]==sum)
		{
			printf("%d\n",n-1);
			for(int j=1;j<=n;j++)if(j!=i)printf("%d ",j);putchar('\n');
			return 0;
		}
	unordered_map<ull,int>exi;
	for(int i=1;i<=n;i++)
	{
		if(exi.count(val[i]^sum))
		{
			printf("%d\n",n-2);
			for(int j=1;j<=n;j++)if(j!=i&&j!=exi[val[i]^sum])printf("%d ",j);putchar('\n');
			return 0;
		}
		exi[val[i]]=i;
	}
	memset(vis,0,sizeof(bool)*(n+1));
	ban=solve(n);
	for(int &i:ban)vis[i]=1;
	int cnt=0;
	for(int i=1;i<=n;i++)if(!vis[i])cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)if(!vis[i])printf("%d ",i);putchar('\n');
	return 0;
}