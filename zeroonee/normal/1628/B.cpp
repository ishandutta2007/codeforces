#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const int N=1e5+2;
string s[N],t[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,i;
		cin>>n;
		for (i=1;i<=n;i++) cin>>s[i];
		map<string,int> mp;
		for (i=1;i<=n;i++)
		{
			if (s[i].size()==1) goto yes;
			mp[s[i]]=1;
			t[i]=s[i];reverse(all(t[i]));
			if (mp[t[i]]) goto yes;
		}
		mp.clear();
		for (i=1;i<=n;i++) if (s[i].size()==3) mp[s[i].substr(0,2)]=1; else if (mp[t[i]]) goto yes;
		mp.clear();
		for (i=n;i;i--) if (s[i].size()==3) mp[t[i].substr(0,2)]=1; else if (mp[s[i]]) goto yes;
		cout<<"NO\n";continue;
		yes:cout<<"YES\n";
	}
}