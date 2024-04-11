#import<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,x,y,A[N];
pair<pair<int,int>,int>p[N];
main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>x>>y,p[i]={{x,y},i},A[i]=1;
		sort(p+1,p+n+1),x=y=0;
		for(int i=1;i<=n;i++)
		{
			if(x&&p[i].first.first>x)
				y=i;
			x=max(x,p[i].first.second);
		}
		if(!y)
		{
			puts("-1");
			continue;
		}
		for(int i=1;i<y;i++)
			A[p[i].second]=2;
		for(int i=1;i<=n;i++)
			cout<<A[i]<<' ';
		puts("");
	}
}