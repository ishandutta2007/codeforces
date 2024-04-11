#include<bits/stdc++.h>
using namespace std;
int t,n,A;
pair<int,int>p[9999];
int main()
{
	cin>>t;
	while(t--&&cin>>n>>A)
	{
		for(int i=1;i<=n;i++)
			cin>>p[i].first;
		for(int i=1;i<=n;i++)
			cin>>p[i].second;
		sort(p+1,p+n+1);
		for(int i=1;i<=n;i++)
			if(A>=p[i].first)
				A+=p[i].second;
		cout<<A<<'\n';
	}
}