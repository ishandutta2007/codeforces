#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 1010
using namespace std;

int n,m;
char str[N];

int main()
{
	int i,j;
	cin>>n;
	scanf("%s",str+1);
	for(i=1;i<=n;i++)
	{
		if(str[i]=='0') m++;
	}
	if(n==m)
	{
		puts("0");
		return 0;
	}
	cout<<1;
	for(i=1;i<=m;i++) printf("0");
}