#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,m,v[N],A[N],x[N],y[N],z[N],f[N],c,b,p,q,r;
int F(int x)
{
	return f[x]==x?x:f[x]=F(f[x]);
}
void C(int x,int p,int y,int q)
{
	f[F(y+q*n)]=F(x+p*n);
}
int main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			v[i]=v[i+n]=A[i]=0,f[i]=i,f[i+n]=i+n;
		for(int i=1;i<n;i++)
		{
			cin>>x[i]>>y[i]>>z[i],c=0;
			if(z[i]==-1)
				continue;
			for(int j=0;j<30;j++)
				if(z[i]>>j&1)
					c^=1;
			C(x[i],0,y[i],c),C(x[i],1,y[i],c^1);
		}
		while(m--&&cin>>p>>q>>r)
			C(p,0,q,r),C(p,1,q,r^1);
		b=0;
		for(int i=1;i<=n;i++)
			if(F(i)==F(i+n))
				b=1;
		if(b)
		{
			cout<<"NO\n"; 
			continue;
		}
		for(int i=1;i<=n;i++)
			if(v[F(i+n)])
				A[i]=1;
			else if(!v[F(i)]&&!v[F(i+n)])
				v[F(i)]=1;
		cout<<"YES\n";
		for(int i=1;i<n;i++)
			cout<<x[i]<<' '<<y[i]<<' '<<(z[i]==-1?A[x[i]]!=A[y[i]]:z[i])<<'\n';
	}
}