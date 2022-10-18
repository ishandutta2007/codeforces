#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6,M=20;
int n,m,A=1,a[M],v[N],c;
bitset<N*M>b;
signed main()
{
	cin>>n>>m;
	for(int i=1;i<M;i++)
	{
		for(int j=1;j<=m;j++)
			b[i*j]=1;
		a[i]=b.count();
	}
	for(int i=2;i<=n;i++)
		if(!v[i])
		{
			c=0;
			for(int j=i;j<=n;j*=i)
				v[j]=1,c++;
			A+=a[c];
		}
	cout<<A;
}