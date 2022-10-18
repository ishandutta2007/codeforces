#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1;
int t,n,m,x,y,A;
vector<int>a[N];
int D(int x,int f)
{
	int c=0;
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f)
			c+=D(a[x][i],x);
	if(!c)
		return 1;
	A+=c-1;
	return 0;
}
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		m=n-1,A=0;
		for(int i=1;i<=n;i++)
			a[i].clear();
		while(m--&&cin>>x>>y)
			a[x].push_back(y),a[y].push_back(x);
		D(1,0);
		cout<<A+1<<'\n';
	}
	return 0;
}