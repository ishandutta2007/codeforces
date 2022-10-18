#include<bits/stdc++.h>
using namespace std;
const int N=2e4;
int n,c,s,A,a[N],b[N];
main()
{
	for(cin>>n;cin>>n;)
	{
		bitset<N>f;
		c=s=0,A=1e9,f[0]=1;
		for(int i=1;i<=n;i++)
			cin>>a[i],c+=a[i]*a[i],s+=a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i],c+=b[i]*b[i],s+=b[i];
		for(int i=1;i<=n;i++)
			f=(f<<a[i])|(f<<b[i]);
		for(int i=0;i<N;i++)
			if(f[i])
				A=min(A,i*i+(s-i)*(s-i));
		cout<<A+c*(n-2)<<'\n';
	}
}