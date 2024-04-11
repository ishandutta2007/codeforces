#include<bits/stdc++.h>
using namespace std;
const int N=2001;
int n,x,p[N],c[N],A[N];
vector<int>a[N],v;
void D(int x,int f)
{
	c[x]=1;
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f)
			D(a[x][i],x),c[x]+=c[a[x][i]];
}
void S(vector<int>v,int x,int f)
{
	if(p[x]>=v.size())
	{
		cout<<"NO";
		exit(0);
	}
	A[x]=v[p[x]],v.erase(v.begin()+p[x]);
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f)
		{
			vector<int>q;
			for(int j=v.size()-c[a[x][i]];j<v.size();j++)
				q.push_back(v[j]);
			for(int j=1;j<=c[a[x][i]];j++)
				v.pop_back();
			S(q,a[x][i],x);
		}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>p[i];
		a[i].push_back(x),a[x].push_back(i);
	}
	D(0,0);
	for(int i=0;i<=n;i++)
		v.push_back(i);
	S(v,0,0);
	cout<<"YES"<<'\n'; 
	for(int i=1;i<=n;i++)
		cout<<A[i]<<' ';
	return 0;
}