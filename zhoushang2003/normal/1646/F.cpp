#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,x,y,c[N][N],A[N*N][N],s,t;
int C(int x)
{
	for(int i=1;i<=n;i++)
		if(c[x][i]>1)
			return 0;
	return 1;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>x,c[i][x]++;
	while(1)
	{
		s=0;
		for(int i=1;i<=n;i++)
			if(!C(i))
				s=i;
		if(!s)
			break;
		t++;
		for(int i=s;i<s+n;i++)
			for(int j=1;j<=n;j++)
				if(c[(i-1)%n+1][j]>1)
					A[t][(i-1)%n+1]=j,c[(i-1)%n+1][j]--,c[i%n+1][j]++,j=n;
	}
	for(int i=1;i<n;i++)
		for(int j=1;j<=i;j++)
		{
			t++;
			for(int k=1;k<=n;k++)
				A[t][k]=(k-i+n-1)%n+1;
		}
	cout<<t<<'\n';
	for(int i=1;i<=t;i++,cout<<'\n')
		for(int j=1;j<=n;j++)
			cout<<A[i][j]<<' ';
}