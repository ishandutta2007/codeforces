#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=20,Inf=1<<30;
int n,l,r,x,c[N]={},ans=0;
int main()
{	
	cin>>n>>l>>r>>x;
	for(int i=0;i<n;++i)
		cin>>c[i];
	for(int s=(1<<n)-1;s>=1;--s)
	{
		int minv=Inf,maxv=-Inf,sum=0,tot=0;
		for(int i=0;i<n;++i)
			if(s&(1<<i))
			{
				minv=min(minv,c[i]);
				maxv=max(maxv,c[i]);
				sum+=c[i];
				++tot;
			}
		if(tot>=2 && maxv-minv>=x && l<=sum && sum<=r)
			++ans;
	}
	cout<<ans<<endl;
	return 0;
}