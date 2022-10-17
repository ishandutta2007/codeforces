#include<bits/stdc++.h>
#define N 300010
using namespace std;

int n,num[N],k,ans,last=1,nn[N];

int main()
{
	int i,j,p,q;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		nn[i]=num[i];
		num[i]=1-num[i];
		num[i]+=num[i-1];
	}
	/*
	for(i=1;i<=n;i++)
	{
		cout<<num[i]<<" ";
	}
	return 0;
	//*/
	num[n+1]=1000000000;
	for(i=1;i<=n;i++)
	{
		for(j=last;j<=n+1;j++)
		{
			if(num[j]-num[i-1]>k)
			{
				last=j;
				break;
			}
			if(ans<j-i+1)
			{
				ans=j-i+1;
				p=i;
				q=j;
			}
		}
	}
//	ans=max(ans)
	cout<<ans<<endl;
	for(i=1;i<=n;i++)
	{
		if(i>=p&&i<=q) printf("1 ");
		else printf("%d ",nn[i]);
	}
}