#include<iostream>
#include<cstdio>
#define N 110
using namespace std;

int n,k;
char str[N];

int main()
{
	int i,j;
	cin>>n>>k;
	if(!k) return 0;
	scanf("%s",str+1);
	for(i=2;i<=n;i++)
	{
		for(j=1;j+i-1<=n;j++)
		{
			if(str[j]!=str[i+j-1]) break;
		}
		if(i+j-1>n) break;
	}
	printf("%s",str+1);
	for(k--;k;k--)
	{
		for(j=n-i+2;j<=n;j++)
		{
			printf("%c",str[j]);
		}
	}
}