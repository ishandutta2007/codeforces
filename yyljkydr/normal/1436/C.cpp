#include<bits/stdc++.h>
using namespace std;

const int N=1e3+7,P=1e9+7;

int n,x,p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>x>>p;
	long long ans=1;
	int gr=n-x,ls=x-1;
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(mid<p)
		{
			//a[mid]<=x
			if(!ls)
			{
				puts("0");
				return 0;
			}
			ans=ans*ls%P;
			ls--;
			l=mid+1;
		}
		else if(mid>p)
		{
			if(!gr)
			{
				puts("0");
				return 0;
			}
			ans=ans*gr%P;
			gr--;
			r=mid;
		}
		else
			l=mid+1;
	}
	for(int i=1;i<=ls+gr;i++)
		ans=ans*i%P;
	cout<<ans<<endl;
}