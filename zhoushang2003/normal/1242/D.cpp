#include<bits/stdc++.h>
using namespace std;
long long T,n,k,K,m,x;
long long C(long long x)
{
	if(x==0)
		return k*(k+1)/2;
	return k*(k+1)/2-x%k+max(0ll,min(k,(x%k+1)*k-C(x/k)+1));
}
int main()
{
	cin>>T;
	while(T--&&cin>>n>>k)
	{
		K=k*k+1,m=(n-1)/K,x=m*K+C(m);
		if(x==n)
			cout<<(m+1)*(k+1)<<'\n';
		else
			cout<<n+(n-(m+(n>=x))*(k+1)-1)/k<<'\n';
	}
	return 0;
}