#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
bool v[N];
int T,n,m,x,y,d[N],l[N],C,b[N],c[N];
stack<int>s; 
vector<int>a[N],A,B;
void D(int k)
{
	d[k]=l[k]=++x,s.push(k),v[k]=true;
	for(int i=0;i<a[k].size();i++)
		if(!d[a[k][i]])
			D(a[k][i]),l[k]=min(l[k],l[a[k][i]]);
		else if(v[a[k][i]])
			l[k]=min(l[k],d[a[k][i]]);
	if(d[k]==l[k])
	{
		C++;
		while(s.top()!=k)
			b[s.top()]=C,v[s.top()]=false,s.pop();
		b[k]=C,v[k]=false,s.pop();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			a[i].clear(),d[i]=0;
		while(m--&&cin>>x>>y)
			a[x].push_back(y);
		x=C=0;
		for(int i=1;i<=n;i++)
			if(!d[i])
				D(i);
		if(C==1)
		{
			cout<<"No"<<'\n';
			continue; 
		}
		for(int i=1;i<=n;i++)
			for(int j=0;j<a[i].size();j++)
				if(b[i]!=b[a[i][j]])
					c[b[i]]++;
		for(int i=1;i<=C;i++)
			if(!c[i])
			{
				A.clear(),B.clear();
				for(int j=1;j<=n;j++)
					if(b[j]==i)
						A.push_back(j);
					else
						B.push_back(j);
				cout<<"Yes"<<'\n'<<A.size()<<" "<<B.size()<<'\n';
				for(int j=0;j<A.size();j++)
					cout<<A[j]<<" ";
				cout<<'\n';
				for(int j=0;j<B.size();j++)
					cout<<B[j]<<" ";
				cout<<'\n';
				break;
			}
	}
	return 0;
}