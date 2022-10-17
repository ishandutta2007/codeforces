#include<iostream>
#include<cstdio>
using namespace std;

int n,ans;

int main()
{
	int i,j,p;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p);
		for(j=1;j*(j+1)/2<=p;j++);
		ans^=j-1;
	}
	ans?puts("NO"):puts("YES");
}