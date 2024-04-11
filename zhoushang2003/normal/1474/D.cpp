#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,I=1e9+1;
int T,n,a[N],x[N],y[N],s[2],t;
int C(int x,int y,int z)
{
	if(x>y||y-x>z)
		return I;
	return z-y+x;
}
int main()
{
	cin>>T;
	while(T--&&cin>>n)
	{
		s[0]=s[1]=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],s[i&1]+=a[i];
		x[1]=a[1],y[1]=I;
		for(int i=2;i<=n;i++)
		{
			if(a[i]<x[i-1])
				x[i]=I;
			else
				x[i]=a[i]-x[i-1];
			if(a[i]<y[i-1])
				y[i]=I;
			else
				y[i]=a[i]-y[i-1];
			t=I;
			if(i&1)
			{
				if((a[i]-a[i-1])*2==s[1]-s[0])
					t=C(x[i-2],a[i],a[i-1]);
			}
			else if((a[i]-a[i-1])*2==s[0]-s[1])
				t=C(x[i-2],a[i],a[i-1]);
			if(t<I)
				y[i]=t;
		}
		if(x[n]==0||y[n]==0)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
	return 0;
}