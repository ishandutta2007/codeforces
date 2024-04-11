#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
struct S
{
	int x,y,i;
};
int n,x,y,X,Y,A,d[N],v[N],l,r;
pair<int,int>p[N];
S w[N];
priority_queue<pair<int,int> >q;
bool C(S x,S y)
{
	if(x.y!=y.y)
		return x.y<y.y;
	if(x.x!=y.x)
		return x.x<y.x;
	return x.i<y.i;
}
int main()
{
	cin>>n>>n>>x>>y>>X>>Y,A=abs(x-X)+abs(y-Y);
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
		w[i].x=p[i].first,w[i].y=p[i].second,w[i].i=i;
	sort(w+1,w+n+1,C);
	for(int i=1;i<=n;i++)
		d[i]=min(abs(x-p[i].first),abs(y-p[i].second)),q.push(make_pair(-d[i],i));
	while(!q.empty())
	{
		x=q.top().second,q.pop();
		if(v[x])
			continue;
		v[x]=1,l=1,r=n;
		if(d[x]+min(abs(p[x].first-p[x+1].first),abs(p[x].second-p[x+1].second))<d[x+1])
			d[x+1]=d[x]+min(abs(p[x].first-p[x+1].first),abs(p[x].second-p[x+1].second)),q.push(make_pair(-d[x+1],x+1));
		if(d[x]+min(abs(p[x].first-p[x-1].first),abs(p[x].second-p[x-1].second))<d[x-1])
			d[x-1]=d[x]+min(abs(p[x].first-p[x-1].first),abs(p[x].second-p[x-1].second)),q.push(make_pair(-d[x-1],x-1));
		while(l<r)
			if(make_pair(p[x].second,p[x].first)<make_pair(w[(l+r+1)/2].y,w[(l+r+1)/2].x))
				r=(l+r-1)/2;
			else
				l=(l+r+1)/2;
		if(d[w[l].i]+min(abs(w[l].x-w[l+1].x),abs(w[l].y-w[l+1].y))<d[w[l+1].i])
			d[w[l+1].i]=d[w[l].i]+min(abs(w[l].x-w[l+1].x),abs(w[l].y-w[l+1].y)),q.push(make_pair(-d[w[l+1].i],w[l+1].i));
		if(d[w[l].i]+min(abs(w[l].x-w[l-1].x),abs(w[l].y-w[l-1].y))<d[w[l-1].i])
			d[w[l-1].i]=d[w[l].i]+min(abs(w[l].x-w[l-1].x),abs(w[l].y-w[l-1].y)),q.push(make_pair(-d[w[l-1].i],w[l-1].i));
	}
	for(int i=1;i<=n;i++)
		A=min(A,d[i]+abs(X-p[i].first)+abs(Y-p[i].second));
	cout<<A;
	return 0;
}