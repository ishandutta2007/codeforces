#include<bits/stdc++.h>
using namespace std;
const int N=251,D=998244353;
long long n,p[N],q[N],a,b,c,d,u[N],r[N],v[N],V[N],S[N][N],C[N][N],W[N][N],P[N],f[N],g[N],h[N],A[N];
void F(int x)
{
	if(!x)
		return;
	v[x]=V[x]=1;
	if(u[x]!=x)
	{
		if(V[u[x]])
			d++;
		else
			F(u[x]),u[x]=u[u[x]];
	}
	V[x]=0;
}
int main()
{
	cin>>n,S[0][0]=S[1][1]=P[0]=1;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>q[i];
	for(int i=1;i<=n;i++)
		u[i]=i;
	for(int i=1;i<=n;i++)
	{
		if(p[i])
		{
			if(p[i]==q[i])
				v[p[i]]=1,d++;
			else
				u[p[i]]=q[i];
		}
		if(q[i])
			++r[q[i]];
	}
	for(int i=1;i<=n;i++)
		if(!v[i])
			F(i);
	for(int i=1;i<=n;i++)
		if(!p[i])
		{
			if(u[q[i]])
				b++;
			else
				a++;
		}
		else if(!r[p[i]]&&!u[q[i]])
			c++;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i;j++)
			S[i][j]=((i-1)*S[i-1][j]+S[i-1][j-1])%D;
	for(int i=0;i<=n;i++)
		C[i][0]=W[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%D;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			W[i][j]=(i-j+1)*W[i][j-1]%D;
	for(int i=1;i<=n;i++)
		P[i]=P[i-1]*i%D;
	for(int i=0;i<=b;i++)
		for(int j=i;j<=b;j++)
			if(a+b-j-1>=0)
				(f[i]+=S[j][i]*C[b][j]%D*W[a+b-j-1][b-j])%=D;
			else
				(f[i]+=S[j][i]*C[b][j])%=D;
	for(int i=0;i<=c;i++)
		for(int j=i;j<=c;j++)
			if(a+c-j-1>=0)
				(g[i]+=S[j][i]*C[c][j]%D*W[a+c-j-1][c-j])%=D;
			else
				(g[i]+=S[j][i]*C[c][j])%=D;
	for(int i=0;i<=a;i++)
		h[i]=S[a][i]*P[a]%D;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<=i-j;k++)
				(A[i]+=h[j]*f[k]%D*g[i-j-k])%=D;
	for(int i=0;i<n;i++)
		if(n-i-d>=0)
			cout<<A[n-i-d]<<" ";
		else
			cout<<0<<" ";
	return 0;
}