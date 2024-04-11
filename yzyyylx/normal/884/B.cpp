#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;

int n,m,num[110];

int main()
{
	int i,j,sum=-1,p;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p);
		sum+=p+1;
	}
	if(sum==m)cout<<"YES";
	else cout<<"NO";
}