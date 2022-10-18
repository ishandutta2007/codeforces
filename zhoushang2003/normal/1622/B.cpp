#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,a[N],A[N];
string s;
pair<pair<int,int>,int>p[N];
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		cin>>s;
		for(int i=1;i<=n;i++)
			p[i]={{s[i-1],a[i]},i};
		sort(p+1,p+n+1);
		for(int i=1;i<=n;i++)
			A[p[i].second]=i;
		for(int i=1;i<=n;i++)
			cout<<A[i]<<' ';
		puts(""); 
	}
}