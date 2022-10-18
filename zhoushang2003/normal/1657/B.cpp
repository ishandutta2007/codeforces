#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,B,x,y,p,A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>B>>x>>y)
	{
		p=A=0;
		for(int i=1;i<=n;i++)
			if(p+x<=B)
				p+=x,A+=p;
			else
				p-=y,A+=p;
		cout<<A<<'\n';
	}
}