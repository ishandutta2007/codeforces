#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,A[N],x,y;
vector<int>a[N];
int D(int x,int f,int y)
{
	A[x]=a[x].size()*y;
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f)
			D(a[x][i],x,-y);
}
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			a[i].clear();
		for(int i=1;i<n;i++)
			cin>>x>>y,a[x].push_back(y),a[y].push_back(x);
		D(1,0,1);
		for(int i=1;i<=n;i++)
			cout<<A[i]<<' ';
		cout<<'\n';
	}
}