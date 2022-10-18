#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,A,d;
string s;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>s)
	{
		vector<int>v;
		for(int i=0;i<n;i++)
			if(s[i]=='*')
				v.push_back(i);
		A=0,d=v.size()/2;
		for(int i=0;i<v.size();i++)
			A+=abs(v[d]-v[i]-d+i);
		cout<<A<<'\n';
	}
	return 0;
}