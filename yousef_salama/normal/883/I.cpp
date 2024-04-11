#include <bits/stdc++.h>

using namespace std;

const int N=3e5+5;

int arr[N];
int mem[N],sum[N];
int n,k;

int can(int x)
{
	mem[n]=1; sum[n]=1;
	for(int i=n-1;i>=0;i--)
	{

		int r=upper_bound(arr,arr+n,arr[i]+x)-arr;
		int l=i+k;
		if(l>r) mem[i]=0;
		else mem[i]=min(1,sum[l]-sum[r+1]);
		//cout << mem[i] << " " << l << " "<< r << endl;
		sum[i]=sum[i+1]+mem[i];
	}
	return mem[0];
}

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int st=0,en=1e9+1,ans=1e9+1;
	while(st<=en)
	{
		int mid=(st+en)/2;
		if(can(mid)){ans=mid; en=mid-1;}
		else st=mid+1;
	}
	printf("%d\n",ans);
}