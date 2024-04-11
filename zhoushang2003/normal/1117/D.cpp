#include<bits/stdc++.h>
using namespace std;
const int M=101;
const long long D=1e9+7;
struct S
{
	long long a[M][M];
};
long long n,m;
S c,A,r;
S P(S x,S y)
{
	memset(r.a,0,sizeof(r.a));
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				(r.a[i][j]+=x.a[i][k]*y.a[k][j])%=D;
	return r;
}
int main()
{
	cin>>n>>m;
	if(n<m)
	{
		cout<<1;
		return 0;
	}
	n-=m;
	for(int i=1;i<m;i++)
		c.a[i][i+1]=1;
	c.a[m][1]=c.a[m][m]=1;
	for(int i=1;i<m;i++)
		A.a[i][1]=1;
	A.a[m][1]=2;
	while(n)
	{
		if(n&1)
			A=P(c,A);
		c=P(c,c),n/=2;
	}
	cout<<A.a[m][1];
	return 0;
}