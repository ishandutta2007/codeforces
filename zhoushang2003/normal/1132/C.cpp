#include<bits/stdc++.h>
using namespace std;
const int N=5001,I=1e9;
bool v[N][N],c;
int n,k,x,y,q[N],t,f[N][N],A,M=I;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		for(int j=x;j<=y;j++)
			v[j][i]=true;
	}
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int j=1;j<=k;j++)
			if(v[i][j])
				q[t++]=j;
		if(t==1)
			for(int i=1;i<=k;i++)
				f[q[0]][i]++,f[i][q[0]]++;
		if(t==2)
			f[q[0]][q[1]]++,f[q[1]][q[0]]++;
		if(t>0)
			A++;
	}
	for(int i=1;i<=k;i++)
		for(int j=i+1;j<=k;j++)
			M=min(M,f[i][j]);
	cout<<A-M;
	return 0;
}