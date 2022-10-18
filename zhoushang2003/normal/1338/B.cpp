#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,m,x,y,p,q,A=1,B,d[N],l[N];
vector<int>a[N];
void D(int x,int f)
{
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f)
			l[a[x][i]]=l[x]+1,D(a[x][i],x),d[x]=max(d[x],d[a[x][i]]+1);
	p=q=0;
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f)
		{
			if(d[a[x][i]]==0)
				p++;
			else if(d[a[x][i]]==1)
				q++;
			else
				B++;
		}
	if(p>0&&q==0)
		B++;
	else if(p==0&&q>0)
		B+=q;
	else if(p>0&&q>0)
		B+=q+1;
}
int main()
{
	cin>>n;
	m=n-1;
	while(m--&&cin>>x>>y)
		a[x].push_back(y),a[y].push_back(x);
	for(int i=1;i<=n;i++)
		if(a[i].size()>1)
			D(i,0),i=n;
	for(int i=1;i<=n;i++)
		if(a[i].size()==1)
			x=i;
	for(int i=1;i<=n;i++)
		if(a[i].size()==1&&((l[x]+l[i])&1))
			A=3;
	cout<<A<<' '<<B;
	return 0;
}