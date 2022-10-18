#include<bits/stdc++.h>
using namespace std;
const int N=100;
int t,n,a[N],x,y;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i],a[i]=abs(a[i]);
		x=y=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]<=a[i+1])
				x++;
			if(a[i]>=a[i+1])
				y++;
		}
		while(x<(n-1)/2)
			for(int i=2;i<n;i++)
				if(a[i]<a[i-1]&&a[i+1]<a[i])
					a[i]=-a[i],i=n,x++,y--;
		while(y<(n-1)/2)
			for(int i=2;i<n;i++)
				if(a[i]>a[i-1]&&a[i+1]>a[i])
					a[i]=-a[i],i=n,y++,x--;
		for(int i=1;i<=n;i++)
			cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}