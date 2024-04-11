#include<iostream>
#include<cstdio>
#define N 1000100
using namespace std;

int n,len[N],ans,last;

int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&len[i]);
	}
	for(i=n;i>=1;i--)
	{
		ans+=!last;
		last=max(last-1,len[i]);
	}
	printf("%d",ans);
}