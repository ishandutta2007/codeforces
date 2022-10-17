#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,m,k;

string s[N],t[N];

map<string,int>id;

int pos[N];

vector<int>v[N],g[N];

queue<int>q;

int ind[N];

vector<int>p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		id[s[i]]=i;
	}
	for(int i=1;i<=m;i++)
		cin>>t[i]>>pos[i];
	for(int i=1;i<=m;i++)
	{
		bool fd=0;
		for(int S=0;S<1<<k;S++)
		{
			string pat=t[i];
			for(int j=0;j<k;j++)
				if(S&(1<<j))
					pat[j]='_';
			if(id.find(pat)==id.end())
				continue;
			if(id[pat]==pos[i])
				fd=1;
			v[i].push_back(id[pat]);
		}
		if(!fd)
		{
			puts("NO");
			return 0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto x:v[i])
		{
			if(x!=pos[i])
				g[pos[i]].push_back(x),ind[x]++;
		}
	}
	for(int i=1;i<=n;i++)
		if(!ind[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		p.push_back(x);
		for(auto v:g[x])
			if(!--ind[v])
				q.push(v);
	}
	if(p.size()!=n)
		puts("NO");
	else
	{
		puts("YES");
		for(auto x:p)
			printf("%d ",x);
		puts("");
	}
}