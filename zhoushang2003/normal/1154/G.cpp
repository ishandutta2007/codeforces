#include<bits/stdc++.h>
using namespace std;
const int N=1e7+1;
int n,x,c[N],q[N][3],t[N],p[N],C,A,B;
long long M=1e18;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		c[x]++;
		if(t[x]<2)
			q[x][++t[x]]=i;
	}
	for(int i=1;i<N;i++)
	{
		for(int j=1;i*j<N;j++)
		{
			while(c[i*j]&&C<2)
				c[i*j]--,p[++C]=j;
			if(C==2)
				break;
		}
		if(C==2&&(long long)p[1]*p[2]*i<M)
			M=(long long)p[1]*p[2]*i,A=p[1]*i,B=p[2]*i;
		while(C)
			c[i*p[C--]]++;
	}
	if(A==B)
		A=q[A][1],B=q[B][2];
	else
		A=q[A][1],B=q[B][1];
	if(A>B)
		swap(A,B);
	cout<<A<<" "<<B;
	return 0;
}