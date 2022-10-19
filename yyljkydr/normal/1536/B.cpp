#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

string s;

set<string>ex;

string ans;

queue<string>q;

void bfs()
{
	string emp;
	while(!q.empty())
		q.pop();
	q.push(emp);
	while(!q.empty())
	{
		string x=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			string v=x+(char)(i+'a');
			if(!ex.count(v))
			{
				ans=v;
				return;
			}
			q.push(v);
		}
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ex.clear();
		scanf("%d",&n);
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			string tmp;
			for(int j=i;j<s.size();j++)
				tmp+=s[j],ex.insert(tmp);
		}
		ans="";
		bfs();
		cout<<ans<<endl;
	}
}