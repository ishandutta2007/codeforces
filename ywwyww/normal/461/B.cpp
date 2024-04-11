#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll f1[100010];// 
ll f2[100010];// 
list<int> l[100010];
int a[100010];
void dfs(int x)
{
	if(a[x])
	{
		f1[x]=1;
		f2[x]=0;
	}
	else
	{
		f1[x]=0;
		f2[x]=1;
	}
	for(auto v:l[x])
	{
		dfs(v);
		f1[x]=(f1[x]*(f2[v]+f1[v])+f2[x]*f1[v])%mod;
		f2[x]=f2[x]*(f2[v]+f1[v])%mod;
	}
}
int main()
{
	int n;
	int x,i;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);
		x++;
		l[x].push_back(i);
	}
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1);
	printf("%I64d\n",f1[1]);
	return 0;
}