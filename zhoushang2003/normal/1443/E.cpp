#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=15;
int P[N],n,m,q,t,x,s,l,r,p,v[N],c,a[N],A;
signed main()
{
	P[0]=1;
	for(int i=1;i<15;i++)
		P[i]=i*P[i-1];
	cin>>n>>q,m=min(n,14ll);
	while(q--&&cin>>t)
		if(t==2&&cin>>x)
			s+=x;
		else
		{
			cin>>l>>r,p=s,memset(v,0,sizeof(v));
			for(int i=m;i>=1;i--)
			{
				c=p/P[i-1],p%=P[i-1];
				for(int j=1;j<=14;j++)
					if(!v[j])
					{
						if(!c)
							a[i]=j+n-m,v[j]=1;
						c--;
					}
			}
			A=(l+r)*(r-l+1)/2;
			for(int i=1;i<=m;i++)
				if(l<=n-i+1&&n-i+1<=r)
					A+=a[i]-n+i-1;
			cout<<A<<'\n';
		}
	return 0;
}