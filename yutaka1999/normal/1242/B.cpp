#include <bits/stdc++.h>
#define SIZE 100005

using namespace std;

vector <int> vec[SIZE];
bool use[SIZE];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--,b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	set <int> zan;
	set <int>::iterator it;
	for(int i=0;i<n;i++) zan.insert(i);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(zan.count(i)==0) continue;
		cnt++;
		queue <int> que;
		que.push(i);
		zan.erase(i);
		while(!que.empty())
		{
			int v=que.front();que.pop();
			vector <int> nxt;
			for(int j=0;j<vec[v].size();j++)
			{
				int to=vec[v][j];
				if(zan.count(to))
				{
					nxt.push_back(to);
					zan.erase(to);
				}
			}
			for(it=zan.begin();it!=zan.end();it++) que.push(*it);
			zan.clear();
			for(int j=0;j<nxt.size();j++) zan.insert(nxt[j]);
		}
	}
	printf("%d\n",cnt-1);
	return 0;
}