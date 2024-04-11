#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,s,x;
map<int,int>p;
int C(int x)
{
	if(!x)
		return 0;
	if(p[x])
	{
		p[x]--;
		return 1;
	}
	return C(x/2)&&C(x-x/2);
}
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		p.clear(),s=0;
		for(int i=1;i<=n;i++)
			cin>>x,p[x]++,s+=x;
		puts(C(s)?"YES":"NO");
	}
}