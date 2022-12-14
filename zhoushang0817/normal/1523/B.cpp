#include<bits/stdc++.h>
using namespace std;
int T,n,x;
int C(int t,int x)
{
	cout<<t<<' '<<x<<' '<<x+1<<'\n';
}
signed main()
{
	cin>>T;
	while(T--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>x;
		cout<<n*3<<'\n';
		for(int i=1;i<=n;i+=2)
			C(1,i),C(2,i),C(1,i),C(2,i),C(1,i),C(2,i);
	}
	return 0;
}