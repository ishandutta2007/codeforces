#include<bits/stdc++.h>
using namespace std;
const int N=1000010,mod=1000000007;
int p,k;
long long ans=1;
bool ok[N]={};
int main()
{	
	cin>>p>>k;
	if(k==0)
		for(int i=1;i<p;++i)
			ans=ans*p%mod;
	else if(k==1)
		for(int i=1;i<=p;++i)
			ans=ans*p%mod;
	else
	{
		for(int i=1;i<p;++i)
		{
			if(ok[i])
				continue;
			ans=ans*p%mod;
			long long x=i;
			while(!ok[x])
				ok[x]=true,x=x*k%p;
		}
	}
	cout<<ans<<endl;
	return 0;
}