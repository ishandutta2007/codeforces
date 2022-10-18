#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,x;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		set<int>s;
		for(int i=1;i<=n;i++)
			cin>>x,s.insert(x);
		for(int i=1;i<=n;i++)
			cout<<max((int)s.size(),i)<<' ';
		puts("");
	}
}