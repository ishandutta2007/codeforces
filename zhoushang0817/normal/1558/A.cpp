#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1;
int t,a,b,v[N],x,y,A;
signed main()
{
	cin>>t;
	while(t--&&cin>>a>>b)
	{
		for(int i=0;i<=a+b;i++)
			v[i]=0;
		A=0,x=(a+b)/2,y=(a+b+1)/2;
		for(int i=0;i<=a;i++)
			if(i<=x&&a-i<=y)
				v[x-i+a-i]=1;
		x=(a+b+1)/2,y=(a+b)/2;
		for(int i=0;i<=a;i++)
			if(i<=x&&a-i<=y)
				v[x-i+a-i]=1;
		for(int i=0;i<=a+b;i++)
			A+=v[i];
		cout<<A<<'\n';
		for(int i=0;i<=a+b;i++)
			if(v[i])
				cout<<i<<' ';
		cout<<'\n';
	}
	return 0;
}