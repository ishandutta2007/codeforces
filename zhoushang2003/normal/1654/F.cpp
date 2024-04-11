#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,a[N];
pair<pair<int,int>,int>p[N];
string s;
int main()
{
	cin>>n>>s,m=(1<<n);
	for(int i=0;i<m;i++)
		a[i]=s[i]-'a'+1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			p[j]={{a[j],a[j^(1<<i)]},j};
		sort(p,p+m),a[p[0].second]=1;
		for(int j=1;j<m;j++)
			a[p[j].second]=a[p[j-1].second]+(p[j].first!=p[j-1].first);
	}
	for(int i=0;i<m;i++)
		if(a[i]==1)
		{
			for(int j=0;j<m;j++)
				cout<<s[i^j];
			exit(0);
		}
			
}