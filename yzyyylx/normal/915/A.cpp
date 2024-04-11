#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,k,num[110];

int main()
{
	int i,j;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num+1,num+n+1);
	for(i=n;i>=1;i--)
	{
		if(k%num[i]==0)
		{
			cout<<k/num[i];
			return 0;
		}
	}
}