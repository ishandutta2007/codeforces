#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
long long n,a[N],x,p[N],f[58][N],c[2],k,w[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],x=max(x,a[i]);
	for(int i=1;i<=n;i++)
		a[i]=x-a[i],p[i]=i;
	memset(f,0x3f,sizeof(f)),f[0][0]=0;
	for(int i=0;i<57;i++)
	{
		c[0]=c[1];
		for(int j=1;j<=n;j++)
			c[a[j]>>i&1]++;
		x=c[1],k=0;
		for(int j=0;j<=n;j++)
		{
			f[i+1][k]=min(f[i+1][k],f[i][j]+x),f[i+1][k+x]=min(f[i+1][k+x],f[i][j]+n-x);
			if(a[p[j+1]]>>i&1)
				k++,x--;
			else
				x++;
		}
		c[0]+=c[1];
		for(int j=n;j>=1;j--)
			w[c[a[p[j]]>>i&1]--]=p[j];
		memcpy(p,w,sizeof(p));
	}
	cout<<f[57][0];
	return 0;
}