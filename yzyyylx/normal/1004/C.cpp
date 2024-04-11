#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define N 100100
using namespace std;

ll n,m,num[N],ans,le[N],ri[N],now;
bool P[N];

int main()
{
	ll i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	now=0;
	for(i=1;i<=n;i++)
	{
		if(!P[num[i]])
		{
			P[num[i]]=1;
			now++;
		}
		le[i]=now;
	}
	memset(P,0,sizeof(P));
//	for(i=1;i<=n;i++) cout<<le[i]<<" ";puts("");
	now=0;
	for(i=n;i>=1;i--)
	{
		if(!P[num[i]])
		{
			ans+=le[i-1];
			P[num[i]]=1;
		}
	}
	cout<<ans;
}