#include<bits/stdc++.h>
using namespace std;
const int N=2e3,X[]={-1,-1,-1,0,0,1,1,1},Y[]={-1,0,1,-1,1,-1,0,1};
int n,m,a[N][N],p[N*N],q[N*N],r[N*N],s,t,x,y,u,v,P,Q,R,S,c,f[N][N];
int C(int x,int y)
{
	P=a[x][y],Q=a[x+1][y],R=a[x][y+1],S=a[x+1][y+1],c=P|Q|R|S;
	return f[u][v]||P>0&&P!=c||Q>0&&Q!=c||R>0&&R!=c||S>0&&S!=c?0:max(1,c);
}
void T(int x,int y)
{
	p[++t]=x,q[t]=y,r[t]=C(x,y),f[x][y]=1;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(C(i,j))
				T(i,j);
	while(s<t)
	{
		x=p[++s],y=q[s],a[x][y]=a[x+1][y]=a[x][y+1]=a[x+1][y+1]=0;
		for(int i=0;i<8;i++)
			if(0<(u=x+X[i])&&u<n&&0<(v=y+Y[i])&&v<m&&C(u,v))
				T(u,v);
	}
	if(t<(n-1)*(m-1))
	{
		cout<<-1;
		return 0;
	}
	cout<<t<<'\n';
	for(int i=t;i;i--)
		cout<<p[i]<<' '<<q[i]<<' '<<r[i]<<'\n';
}