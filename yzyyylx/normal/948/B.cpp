#include<iostream>
#include<cstdio>
#define INF 0x3f3f3f3f
#define N 1001000
using namespace std;

int mx[N],zs[N],zz,n,ans;
bool P[N];

inline void get()
{
	int i,j;
	P[1]=1;
	for(i=2;i<=1000000;i++)
	{
		if(!P[i])
		{
			zs[++zz]=i;
			mx[i]=i;
		}
		for(j=1;j<=zz&&i*zs[j]<=1000000;j++)
		{
			P[i*zs[j]]=1;
			mx[i*zs[j]]=max(zs[j],mx[i]);
		}
	}
}

inline int ask(int u)
{
	if(!P[u]) return INF;
	return u-mx[u]+1;
}

int main()
{
	get();
	int i,j;
	cin>>n;
	ans=INF;
	for(i=n-mx[n]+1;i<=n;i++)
	{
		ans=min(ans,ask(i));
	}
	cout<<ans;
}