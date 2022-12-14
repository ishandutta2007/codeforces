#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+1;
int n,A[N],B[N],C[N],D[N],x,s,t,p,q;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((i+j)%2)
				A[++s]=i,B[s]=j;
			else
				C[++t]=i,D[t]=j;
	for(int i=1;i<=n*n;i++)
	{
		cin>>x;
		if(x==1)
		{
		    p++;
			cout<<2<<' '<<A[p]<<' '<<B[p]<<'\n';
			fflush(stdout);
			if(p==s)
			{
				while(q<t&&cin>>x)
				{
				    q++;
					if(x==1)
						cout<<3<<' '<<C[q]<<' '<<D[q]<<'\n';
					else
						cout<<1<<' '<<C[q]<<' '<<D[q]<<'\n';
					fflush(stdout);
				}
				i=n*n;
			}
		}
		else
		{
		    q++;
			cout<<1<<' '<<C[q]<<' '<<D[q]<<'\n';
			fflush(stdout);
			if(q==t)
			{
				while(p<s&&cin>>x)
				{
				    p++;
					if(x==2)
						cout<<3<<' '<<A[p]<<' '<<B[p]<<'\n';
					else
						cout<<2<<' '<<A[p]<<' '<<B[p]<<'\n';
					fflush(stdout);
				}
				i=n*n;
			}
		}
	}
	return 0;
}