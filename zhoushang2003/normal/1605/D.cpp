#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,x,y,c[N],l,r,A[N],b[N];
vector<int>a[N],u,v;
void D(int x,int f)
{
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f)
			c[a[x][i]]=c[x]^1,D(a[x][i],x);
}
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			a[i].clear();
		for(int i=1;i<n;i++)
			cin>>x>>y,a[x].push_back(y),a[y].push_back(x);
		D(1,0),x=y=0,u.clear(),v.clear();
		for(int i=1;i<=n;i++)
			x+=(c[i]==0);
		if(2*x>n)
			x=n-x,y=1;
		for(int i=0;i<20;i++)
			for(int j=1;j<=n;j++)
				if(j>>i&1)
					b[j]=(x>>i&1);
		for(int i=1;i<=n;i++)
			if(b[i])
				u.push_back(i);
			else
				v.push_back(i);
		l=r=0;
		for(int i=1;i<=n;i++)
			if(c[i]==y)
				A[i]=u[l++];
			else
				A[i]=v[r++];
		for(int i=1;i<=n;i++)
			cout<<A[i]<<' ';
		cout<<'\n';
	}
	return 0;
}