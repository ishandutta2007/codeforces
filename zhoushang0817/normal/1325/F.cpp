#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
bool v[N];
int n,m,x,y,k,q[N],t,d[N],A[N],c;
vector<int>a[N];
void D(int x)
{
	q[++t]=x,d[x]=t;
	for(int i=0;i<a[x].size();i++)
		if(!d[a[x][i]])
			D(a[x][i]);
		else if(d[x]-d[a[x][i]]+1>=k)
		{
			cout<<2<<'\n'<<d[x]-d[a[x][i]]+1<<'\n';
			for(int j=d[a[x][i]];j<=d[x];j++)
				cout<<q[j]<<' ';
			exit(0);
		}
	if(!v[x])
	{
		A[++c]=x;
		for(int i=0;i<a[x].size();i++)
			v[a[x][i]]=true;
	}
	t--;
}
int main()
{
	cin>>n>>m;
	while(m--&&cin>>x>>y)
		a[x].push_back(y),a[y].push_back(x);
	k=sqrt(n-1)+1,D(1);
	cout<<1<<'\n';
	for(int i=1;i<=k;i++)
		cout<<A[i]<<' ';
	return 0;
}