#include<bits/stdc++.h>
using namespace std;
int x,t,a[99],c,n,s;
int main()
{
	for(int i=1;i<=9;i++)
	{
		x=i;
		for(int j=1;j<=9;j++)
			a[++c]=x,x=x*10+i;
	}
	cin>>t;
	while(t--&&cin>>n)
	{
		s=0;
		for(int i=1;i<=c;i++)
			if(a[i]<=n)
				s++;
		cout<<s<<'\n';
	}
	return 0;
}