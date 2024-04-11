#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6,D=998244353;
int t,n,m,k,q,x[N],y[N],u[N],v[N],A,r,c;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>m>>k>>q)
	{
		A=1,r=n,c=m;
		for(int i=1;i<=q;i++)
			cin>>x[i]>>y[i];
		for(int i=q;i;i--)
			if(u[x[i]]+v[y[i]]<2&&r*c)
				(A*=k)%=D,r-=!u[x[i]],c-=!v[y[i]],u[x[i]]=v[y[i]]=1;
		for(int i=1;i<=q;i++)
			u[x[i]]=v[y[i]]=0;
		cout<<A<<'\n';
	}
}