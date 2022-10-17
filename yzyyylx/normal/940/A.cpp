#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 110
using namespace std;

int n,num[N],ans=N,d;

int main()
{
	int i,j;
	cin>>n>>d;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num+1,num+n+1);
	for(i=1;i<=n;i++)
	{
		int an=i-1;
		for(j=i+1;j<=n;j++)
		{
			if(num[j]-num[i]>d) an++;
		}
		ans=min(an,ans);
	}
	cout<<ans;
}