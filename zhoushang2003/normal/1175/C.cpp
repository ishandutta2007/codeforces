#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,I=1e9;
int t,n,k,a[N],M,A;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>k)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		M=I;
		for(int i=1;i+k<=n;i++)
			if((a[i+k]-a[i]+1)/2<M)
				M=(a[i+k]-a[i]+1)/2,A=(a[i+k]+a[i])/2;
		cout<<A<<'\n';
	}
	return 0;
}