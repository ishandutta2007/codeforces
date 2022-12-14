#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1; 
int n,k,L,a[N],l,r,f[N],g[N],A;
string s;
bool C(int x)
{
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+a[i],g[i]=g[i-1];
		if(f[max(i-L,0)]+x<f[i])
			f[i]=f[max(i-L,0)]+x,g[i]=g[max(i-L,0)]+1;
	}
	return g[n]<=k;
}
int S()
{
	l=0,r=L;
	while(l<r)
		if(C((l+r)/2))
			r=(l+r)/2;
		else
			l=(l+r)/2+1;
	C(l);
	return f[n]-l*k;
}
int main()
{
	cin>>n>>k>>L>>s;
	for(int i=1;i<=n;i++)
		a[i]=(s[i-1]>='a');
	A=S();
	for(int i=1;i<=n;i++)
		a[i]=1-a[i];
	cout<<min(A,S());
	return 0;
}