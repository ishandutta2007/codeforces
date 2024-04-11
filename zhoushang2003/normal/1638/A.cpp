#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,a[N],x,y;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		x=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=i)
				x=i,i=n;
		if(!x)
		{
			for(int i=1;i<=n;i++)
				cout<<i<<' ';
			puts("");
			continue;
		}
		for(int i=1;i<=n;i++)
			if(a[i]==x)
				y=i;
		for(int i=1;i<x;i++)
			cout<<a[i]<<' ';
		for(int i=y;i>=x;i--)
			cout<<a[i]<<' ';
		for(int i=y+1;i<=n;i++)
			cout<<a[i]<<' ';
		puts(""); 
	}
}