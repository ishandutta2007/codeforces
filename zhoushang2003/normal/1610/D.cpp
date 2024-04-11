#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6,D=1e9+7;
int p[N],n,x,s,c[N],A;
signed main()
{
	p[0]=1;
	for(int i=1;i<N;i++)
		p[i]=p[i-1]*2%D;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x,c[__builtin_ctz(x)]++;
	for(int i=30;i;i--)
	{
		s+=c[i];
		if(c[i]>1)
			(A+=(p[c[i]-1]-1)*p[s-c[i]])%=D;
	}
	cout<<(A+(p[c[0]]-1)*p[n-c[0]])%D;
}