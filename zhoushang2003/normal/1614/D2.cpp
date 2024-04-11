#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e7,M=2e7;
int v[N],p[N],c,n,x,s[N],f[N],A;
signed main()
{
	for(int i=2;i<=M;i++)
	{
		if(!v[i])
			p[++c]=i;
		for(int j=1;j<=c&&i*p[j]<=M;j++)
		{
			v[i*p[j]]=1;
			if(i%p[j]==0)
				break;
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x,s[x]++;
	for(int i=1;i<=c;i++)
		for(int j=M/p[i];j;j--)
			s[j]+=s[j*p[i]];
	for(int i=M;i;i--)
	{
		f[i]=s[i]*i;
		for(int j=1;j<=c&&i*p[j]<=M;j++)
			f[i]=max(f[i],f[i*p[j]]+(s[i]-s[i*p[j]])*i);
		A=max(A,f[i]+n-s[i]);
	}
	cout<<A;
	return 0;
}