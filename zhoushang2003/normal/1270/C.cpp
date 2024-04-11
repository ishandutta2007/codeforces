#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long t,n,a[N],x,y;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		x=y=0;
		for(int i=1;i<=n;i++)
			x+=a[i],y^=a[i];
		cout<<2<<'\n'<<y<<' '<<x+y<<'\n';
	}
	return 0;
}