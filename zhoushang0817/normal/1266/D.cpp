#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
long long n,m,x,y,z,f[N],l=1,r=1,w,A[N],B[N],C[N],t;
int main()
{
	cin>>n>>m;
	while(m--&&cin>>x>>y>>z)
		f[x]-=z,f[y]+=z;
	while(true)
	{
		while(l<=n&&f[l]>=0)
			l++;
		while(r<=n&&f[r]<=0)
			r++;
		if(l>n||r>n)
			break;
		w=min(-f[l],f[r]),A[++t]=l,B[t]=r,C[t]=w,f[l]+=w,f[r]-=w;
	}
	cout<<t<<'\n';
	for(int i=1;i<=t;i++)
		cout<<A[i]<<' '<<B[i]<<' '<<C[i]<<'\n';
	return 0;
}