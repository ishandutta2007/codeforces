#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;

int n,m,num[110];

int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	
	for(i=1;i<=n;i++)
	{
		m-=(86400-num[i]);
		if(m<=0)break;
	}
	cout<<i;
}