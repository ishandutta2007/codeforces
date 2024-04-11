#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll tim[100005],beg,end,n,t,i,j,mn,last,ans;
	cin>>beg>>end>>t>>n;
	end-=t-1;
	if(n==0)
	{
		cout<<beg;
		return 0;
	}
//	cout<<end;
	for(i=1;i<=n;i++)
	{
		cin>>tim[i];
	}
	
	if(tim[1]>beg)
	{
		cout<<beg;
		return 0;
	}
	
	mn=beg-(tim[1]-1);
	ans=tim[1]-1;
//	cout<<ans;
	last=beg+t;
	if(mn<=0)
	{
		cout<<ans;
		return 0;
	}
	for(i=2;i<=n;i++)
	{
		if(mn>last-(tim[i]-1))
		{
			mn=last-(tim[i]-1);
//			cout<<mn<<" ";
			ans=tim[i]-1;
//			cout<<ans<<" ";
			if(mn<=0)
			{
				cout<<ans;
				return 0;
			}
		}
		last+=t;
		if(last>end)
		break;
	}
	if(last<=end)
	{
		cout<<last;
		return 0;
	}
	cout<<ans;
}