#include<bits/stdc++.h>
using namespace std;
const int D=1e9+7,N=11,M=1024;
int n,m,k,a[N][N],v[N],f[N][N];
int S(int x,int y)
{
	if(y>m)
		x++,y=1;
	if(x>n)
		return 1;
	bool b=false;
	int A=0,s=0,t;
	f[x][y]=f[x-1][y]|f[x][y-1];
	for(int i=1;i<=k;i++)
		if(f[x][y]&(1<<(i-1)))
			s++;
	if(n+m-x-y+1>k-s)
		return 0;
	s=f[x][y];
	if(a[x][y])
	{
		if(!(s&(1<<(a[x][y]-1))))
			f[x][y]=s|(1<<(a[x][y]-1)),(A+=S(x,y+1))%=D;
		return A;
	}
	for(int i=1;i<=k;i++)
		if(!(s&(1<<(i-1))))
		{
			f[x][y]=s|(1<<(i-1)),v[i]++;
			if(v[i]==1)
			{
				if(!b)
					t=S(x,y+1),b=true;
				(A+=t)%=D;
			}
			else
				(A+=S(x,y+1))%=D;
			v[i]--;
		}
	return A;
}
int main()
{
	cin>>n>>m>>k;
	if(n+m-1>k)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			v[a[i][j]]++;
		}
	cout<<S(1,1);
	return 0;
}