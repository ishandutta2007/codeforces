#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100100
using namespace std;

int n,num[N],ans;

int main()
{
	int i,j,p,q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num+1,num+n+1);
	for(i=j=1;j<=n;i++,j++)
	{
		for(;j<=n&&num[j]<=num[i];) j++;
		if(j<=n) ans++;
	}
	cout<<ans;
}