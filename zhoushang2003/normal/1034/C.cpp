#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1,D=1e9+7;
long long n,A,f[N],a[N],p[N],c[N];
int main()
{
	ios::sync_with_stdio(false); 
	cin>>n,f[1]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
		cin>>p[i];
	for(int i=n;i>1;i--)
		a[p[i]]+=a[i];
	for(int i=1;i<=n;i++)
		if(a[1]/__gcd(a[1],a[i])<=n)
			c[a[1]/__gcd(a[1],a[i])]++;
	for(int i=n;i>=1;i--)
		for(int j=i+i;j<=n;j+=i)
			c[j]+=c[i];
	for(int i=1;i<=n;i++)
		if(c[i]==i)
		{
			(A+=f[i])%=D;
			for(int j=i+i;j<=n;j+=i)
				(f[j]+=f[i])%=D;
		}
	cout<<A;
	return 0;
}