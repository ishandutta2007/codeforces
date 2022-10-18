#include <bits/stdc++.h>

using namespace std;

const int N=1e4+5;

int n,q;
string arr[N];
map<string,vector<int> > mp;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		set<string> ss;
		for(int x=0;x<arr[i].size();x++)
		{
			for(int y=x;y<arr[i].size();y++)
			{
				string s=arr[i].substr(x,y-x+1);
				ss.insert(s);
			}
		}
		for(auto j:ss)
			mp[j].push_back(i);
	}
	scanf("%d",&q);
	while(q--)
	{
		string s;
		cin >> s;
		string ans=(mp[s].size()?arr[mp[s][0]]:"-");
		printf("%d %s\n",(int)mp[s].size(),ans.c_str());
	}
}