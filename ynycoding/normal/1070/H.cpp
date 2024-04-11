#include <bits/stdc++.h>
#define MAXN 10001
using namespace std;

int n, m;
string s[MAXN], tmp;
map<string, pair<int, int> > mp;
int main()
{
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>s[i];
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<s[i].length(); ++j) for(int k=j; k<s[i].length(); ++k)
		if(!mp.count(s[i].substr(j, k+1-j))||mp[s[i].substr(j, k+1-j)].first!=i) mp[s[i].substr(j, k+1-j)].first=i, ++mp[s[i].substr(j, k+1-j)].second;
	}
	cin>>m;
	for(int i=1; i<=m; ++i)
	{
		cin>>tmp;
		if(mp.count(tmp)) cout<<mp[tmp].second<<" "<<s[mp[tmp].first]<<endl;
		else puts("0 -");
	}
	return 0;
}