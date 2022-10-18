#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,m,x,d[N],p[N],C,c[N],y,L,R,l,r;
string s;
vector<int>a[N],S[N];
vector<pair<int,int> >q[N];
void D(int k,int f)
{
	p[k]=++C,q[d[k]].push_back(make_pair(k,p[k])),c[k]=1;
	for(int i=0;i<a[k].size();i++)
		if(a[k][i]!=f)
			d[a[k][i]]=d[k]+1,D(a[k][i],k),c[k]+=c[a[k][i]];
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		a[i].push_back(x),a[x].push_back(i);
	}
	cin>>s;
	d[1]=1,D(1,0);
	for(int i=1;i<N;i++)
	{
		S[i].push_back(0);
		for(int j=0;j<q[i].size();j++)
			S[i].push_back(S[i][S[i].size()-1]^(1<<(s[q[i][j].first-1]-'a')));
	}
	while(m--&&cin>>x>>y)
	{
		if(q[y].size()==0)
		{
			cout<<"Yes"<<'\n';
			continue;
		}
		L=p[x],R=p[x]+c[x]-1,l=0,r=q[y].size()-1;
		while(l<r)
			if(q[y][(l+r)/2].second<L)
				l=(l+r)/2+1;
			else
				r=(l+r)/2;
		if(q[y][l].second<L)
		{
			cout<<"Yes"<<'\n';
			continue;
		}
		L=l,l=0,r=q[y].size()-1;
		while(l<r)
			if(q[y][(l+r+1)/2].second>R)
				r=(l+r-1)/2;
			else
				l=(l+r+1)/2;
		if(q[y][l].second>R)
		{
			cout<<"Yes"<<'\n';
			continue;
		}
		R=l;
		if(__builtin_popcount(S[y][L]^S[y][R+1])<2)
			cout<<"Yes"<<'\n';
		else
			cout<<"No"<<'\n';
	}
	return 0;
}