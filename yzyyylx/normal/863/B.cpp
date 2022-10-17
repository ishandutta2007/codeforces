#include<bits/stdc++.h>
using namespace std;

int num[55],n,ans=100000000,i,j;

int now()
{
	int an=0,k,last=0;
	for(k=1;k<=2*n;k++)
	{
		if(k==i||k==j) continue;
		if(last==0)
		{
			last=k;
			continue;
		}
		an+=num[k]-num[last];
		last=0;
	}
	return an;
}

int main()
{
	cin>>n;
	for(i=1;i<=n*2;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num+1,num+n*2+1);
	
	for(i=1;i<=n*2;i++)
	{
		for(j=1;j<=n*2;j++)
		{
			if(j!=i)
			{
				ans=min(ans,now());
			}
		}
	}
	cout<<ans;
}