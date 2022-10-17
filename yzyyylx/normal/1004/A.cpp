#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 110
using namespace std;

int n,m,num[N],ans=2;

int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num+1,num+n+1);
	for(i=1;i<n;i++)
	{
		if(num[i+1]-num[i]>2*m)
		{
			ans+=2;
		}
		else if(num[i+1]-num[i]==2*m) ans++;
	}
	cout<<ans;
}