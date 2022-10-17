#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n;

string s[N];

int solve(string &a,string &b)
{
	int p=0,s=a.size()-1;
	while(a[p]==b[p]&&p<a.size())
		p++;
	while(a[s]==b[s]&&s>=0)
		s--;
	if(p>s)
		return 0;
	bool oka=1,okb=1;
	for(int i=p;i<=s-1;i++)
		oka&=a[i]<=a[i+1],okb&=b[i]<=b[i+1];
	if(oka||okb)
		return 1;
	return 2;
}

map<string,vector<string>>mp;

long long ans;

void calc(vector<string>&v)
{
	int n=v.size(),l=v[0].size();
	if(n<l*100)
	{
		ans-=1ll*n*(n-1)/2*1337;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				ans+=solve(v[i],v[j]);
	}
	else
	{
		ans-=1ll*n*(n-1)/2*1337;
		ans+=1ll*n*(n-1);
		unordered_set<string>vis;
		for(int i=0;i<n;i++)
			vis.insert(v[i]);
		for(int i=0;i<n;i++)
		{
			for(int x=0;x<l;x++)
				for(int y=x+1;y<l;y++)
				{
					string tmp=v[i];
					sort(tmp.begin()+x,tmp.begin()+y+1);
					if(tmp[x]==v[i][x]||tmp[y]==v[i][y])
						continue;
					if(vis.count(tmp))
						ans--;
				}
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		string tmp=s[i];
		sort(tmp.begin(),tmp.end());
		mp[tmp].push_back(s[i]);
	}
	ans=1ll*n*(n-1)/2*1337;
	for(auto [x,y]:mp)
		calc(y);
	printf("%lld\n",ans);
}