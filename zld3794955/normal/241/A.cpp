#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int M=1010,K=1010,Inf=10000;
int m,k,d[M]={},s[M]={};
int main()
{
	cin>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>d[i];
	for(int i=1;i<=m;++i)
		cin>>s[i];
	int now=s[1],v=s[1],ans=0;
	for(int i=1;i<=m;++i)
	{
		while(now<d[i])
			now+=v,ans+=k;
		now-=d[i];
		now+=s[i+1];
		ans+=d[i];
		v=max(v,s[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}