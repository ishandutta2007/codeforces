#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 110
using namespace std;

int n,m,num[N],ans=2;

int main()
{
	int i,j;
	cin>>n;
	for(i=j=1;i<=n;i++)
	{
		printf("%d",j);
		j^=1;
	}
}