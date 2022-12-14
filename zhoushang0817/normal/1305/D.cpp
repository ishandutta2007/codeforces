#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
bool v[N];
int n,m,x,y,A,B,c[N],q[N],t,X;
vector<int>a[N],b[N];
int main()
{
	cin>>n;
	m=n-1;
	while(m--&&cin>>x>>y)
		b[x].push_back(y),b[y].push_back(x);
	while(true)
	{
		x=0;
		for(int i=1;i<=n;i++)
			if(!v[i])
				x++,A=i;
		for(int i=n;i>=1;i--)
			if(!v[i])
				B=i;
		if(x==1)
		{
			cout<<'!'<<' '<<A<<'\n';
			fflush(stdout);
			return 0;
		}
		if(x==2)
		{
			cout<<'?'<<' '<<A<<' '<<B<<'\n';
			fflush(stdout);
			cin>>x;
			cout<<'!'<<' '<<x<<'\n';
			fflush(stdout);
			return 0;
		}
		for(int i=1;i<=n;i++)
			a[i].clear(),c[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<b[i].size();j++)
				if(!v[i]&&!v[b[i][j]])
					a[i].push_back(b[i][j]),c[i]++;
		for(int i=1;i<=n;i++)
			if(c[i]>1)
			{
				cout<<'?'<<' '<<a[i][0]<<' '<<a[i][1]<<'\n';
				fflush(stdout);
				cin>>x;
				t=0;
				if(x!=i)
					q[++t]=i,v[i]=true;
				if(x!=a[i][0])
					q[++t]=a[i][0],v[a[i][0]]=true;
				if(x!=a[i][1])
					q[++t]=a[i][1],v[a[i][1]]=true;
				while(t)
				{
					X=q[t--];
					for(int j=0;j<a[X].size();j++)
						if(a[X][j]!=x&&!v[a[X][j]])
							q[++t]=a[X][j],v[a[X][j]]=true;
				}
				break;
			}
	}
	return 0;
}