#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
bool v[N];
int n,m,x,y;
vector<int>a[N];
priority_queue<int>q;
int main()
{
	cin>>n>>m,q.push(-1);
	while(m--&&cin>>x>>y)
		a[x].push_back(y),a[y].push_back(x);
	while(!q.empty())
	{
		x=-q.top(),q.pop();
		if(v[x])
			continue;
		cout<<x<<" ",v[x]=true;
		for(int i=0;i<a[x].size();i++)
			if(!v[a[x][i]])
				q.push(-a[x][i]);
	}
	return 0;
}