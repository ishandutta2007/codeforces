#include<bits/stdc++.h>
using namespace std;
const int N=1010,mod=1000000007;
int n,t[3]={};
long long ans=1,a,b,c;
int main()
{
	scanf("%d",&n);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		++t[x];
	}
	for(int i=t[1]+1;i<=t[1]+t[2];++i)
		ans=ans*i%mod;
	a=1,b=1;
	for(int i=2;i<=t[1];++i)
	{
		c=(b+(i-1)*a)%mod;
		a=b,b=c;
	}
	cout<<ans*b%mod<<endl;
	return 0;
}