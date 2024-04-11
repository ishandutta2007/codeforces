#include<bits/stdc++.h>
using namespace std;
const int N=5050;
int n,ans=0,f[N]={},t[N]={};
long long a[N]={};
int main()
{
	cin>>n;
	ans=n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		while(a[i]%2==0)
			a[i]/=2,++t[i];
	}
	for(int i=1;i<=n;++i)
	{
		f[i]=1;
		for(int j=1;j<i;++j)
			if(a[j]%a[i]==0 && (t[i]+j-i==t[j] || t[i]<=i-j-1))
				f[i]=max(f[i],f[j]+1);
		ans=min(ans,n-f[i]);
	}
	cout<<ans<<endl;
	return 0;
}