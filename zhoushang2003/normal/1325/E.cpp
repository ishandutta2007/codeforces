#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1,I=1e9;
int n,w[N],t,q[N],c,d[N],p[N],s,x,A=I;
vector<int>a[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		t=0,q[2]=1;
		for(int j=2;j*j<=w[i];j++)
		{
			c=0;
			while(w[i]%j==0)
				w[i]/=j,c++;
			if(c&1)
				q[++t]=j;
		}
		if(w[i]>1)
			q[++t]=w[i];
		if(t==0)
			A=1;
		a[q[1]].push_back(q[2]),a[q[2]].push_back(q[1]);
	}
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<N;j++)
			d[j]=I;
		d[i]=0,s=t=0,q[++t]=i;
		while(s<t)
		{
			x=q[++s];
			for(int j=0;j<a[x].size();j++)
				if(a[x][j]!=p[x])
				{
					if(d[a[x][j]]==I)
						d[a[x][j]]=d[x]+1,p[a[x][j]]=x,q[++t]=a[x][j];
					else
						A=min(A,d[x]+d[a[x][j]]+1);
				}
		}
	}
	if(A==I)
		cout<<-1;
	else
		cout<<A;
	return 0;
}