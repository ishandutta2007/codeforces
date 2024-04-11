#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y;
	long long ans=0;
	map<int,int> dx,dy;
	map<pair<int,int>,int> d;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		++dx[x],++dy[y];
		++d[make_pair(x,y)];
	}
	for(auto p:dx)
		ans+=p.second*1ll*(p.second-1)/2;
	for(auto p:dy)
		ans+=p.second*1ll*(p.second-1)/2;
	for(auto p:d)
		ans-=p.second*1ll*(p.second-1)/2;
	cout<<ans<<endl;
	return 0;
}