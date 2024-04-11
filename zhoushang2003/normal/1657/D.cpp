#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,c,x,y,z,f[9999999],m;
signed main()
{
	cin>>n>>c;
	while(n--&&cin>>x>>y>>z)
		f[x]=max(f[x],y*z);
	for(int i=1;i<=c;i++)
	{
		for(int j=i;j<=c;j+=i)
			f[j]=max(f[j],f[i]*j/i);
		f[i]=max(f[i],f[i-1]);
	}
	cin>>m;
	while(m--&&cin>>x>>y)
		cout<<((z=upper_bound(f+1,f+c+1,x*y)-f)>c?-1:z)<<' ';
}