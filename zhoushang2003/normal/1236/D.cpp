#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long n,m,k,x,y,A,M,a,b,c,d;
vector<long long>p[N],q[N];
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		p[x].push_back(y),q[y].push_back(x);
	}
	A=1,x=y=1;
	M=m-b;
	for(int i=0;i<p[x].size();i++)
		if(p[x][i]>y)
			M=min(M,p[x][i]-1);
	A+=M-y,a=x,y=M;
	while(true)
	{
		M=n-c;
		for(int i=0;i<q[y].size();i++)
			if(q[y][i]>x)
				M=min(M,q[y][i]-1);
		if(M==x)
			break;
		A+=M-x,b=m-y+1,x=M;
		M=d+1;
		for(int i=0;i<p[x].size();i++)
			if(p[x][i]<y)
				M=max(M,p[x][i]+1);
		if(M==y)
			break;
		A+=y-M,c=n-x+1,y=M;
		M=a+1;
		for(int i=0;i<q[y].size();i++)
			if(q[y][i]<x)
				M=max(M,q[y][i]+1);
		if(M==x)
			break;
		A+=x-M,d=y,x=M;
		M=m-b;
		for(int i=0;i<p[x].size();i++)
			if(p[x][i]>y)
				M=min(M,p[x][i]-1);
		if(M==y)
			break;
		A+=M-y,a=x,y=M;
	}
	if(A==n*m-k)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}