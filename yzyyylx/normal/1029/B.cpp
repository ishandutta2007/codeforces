#include<iostream>
#include<cstdio>
#define N 110
using namespace std;

int n,k,now=1,ans;

int main()
{
	int i,j,p,q=-1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p);
		if(p<=q*2) now++;
		else now=1;
		ans=max(ans,now);
		q=p;
	}
	cout<<ans;
}