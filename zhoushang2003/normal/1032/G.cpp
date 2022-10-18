#import<bits/stdc++.h>
using namespace std;
const int N=4e5,M=22;
int n,a[N],u[N][M],v[N][M],l[N][M],r[N][M],x,y,d,p,q,A;
int U(int x,int y)
{
	return x-a[x]<y-a[y]?x:y;
}
int V(int x,int y)
{
	return x+a[x]>y+a[y]?x:y;
}
int L(int x,int y)
{
	d=log2(y-x+1);
	return U(u[x][d],u[y-(1<<d)+1][d]);
}
int R(int x,int y)
{
	d=log2(y-x+1);
	return V(v[x][d],v[y-(1<<d)+1][d]);
}
main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i+n]=a[i+n+n]=a[i];
	n*=3;
	for(int i=1;i<=n;i++)
		u[i][0]=v[i][0]=i,l[i][0]=max(1,i-a[i]),r[i][0]=min(n,i+a[i]);
	for(int i=1;i<M;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			u[j][i]=U(u[j][i-1],u[j+(1<<(i-1))][i-1]),v[j][i]=V(v[j][i-1],v[j+(1<<(i-1))][i-1]);
	for(int i=1;i<M;i++)
		for(int j=1;j<=n;j++)
			x=L(l[j][i-1],r[j][i-1]),y=R(l[j][i-1],r[j][i-1]),l[j][i]=min(l[x][i-1],l[y][i-1]),r[j][i]=max(r[x][i-1],r[y][i-1]);
	n/=3;
	for(int i=n+1;i<=2*n;i++)
	{
		A=0,p=q=i;
		for(int j=M-1;~j;j--)
			if((y=max(r[p][j],r[q][j]))-(x=min(l[p][j],l[q][j]))+1<n)
				p=L(x,y),q=R(x,y),A+=(1<<j);
		cout<<A+(n>1)<<' ';
	}
}