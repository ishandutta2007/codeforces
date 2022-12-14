#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,I=1e9;
bool v[N];
int n,m,x,y,k,p[N],d[N],X,A,B;
vector<int>a[N],b[N];
priority_queue<pair<int,int> >q;
int main()
{
	cin>>n>>m;
	while(m--&&cin>>x>>y)
		a[y].push_back(x),b[x].push_back(y);
	cin>>k;
	for(int i=1;i<=k;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		d[i]=I;
	d[p[k]]=0,q.push(make_pair(0,p[k]));
	while(!q.empty())
	{
		X=q.top().second,q.pop();
		if(v[X])
			continue;
		v[X]=true;
		for(int i=0;i<a[X].size();i++)
			if(d[X]+1<d[a[X][i]])
				d[a[X][i]]=d[X]+1,q.push(make_pair(-d[a[X][i]],a[X][i]));
	}
	for(int i=1;i<k;i++)
		if(d[p[i]]-1==d[p[i+1]])
		{
			for(int j=0;j<b[p[i]].size();j++)
				if(b[p[i]][j]!=p[i+1]&&d[p[i]]-1==d[b[p[i]][j]])
					B++,j=b[p[i]].size();
		}
		else
			A++,B++;
	cout<<A<<' '<<B;
	return 0;
}