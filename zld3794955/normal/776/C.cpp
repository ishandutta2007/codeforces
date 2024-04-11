#include<bits/stdc++.h>
using namespace std;
const int N=100100,D=60;
map<long long,int> m;
long long maxv=0,ans=0,pk[D]={};
int n,k,a[N]={},t=0;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		maxv=maxv+abs(a[i]);
	}
	pk[0]=1,t=1;
	if(k==1)
		t=1;
	else if(k==-1)
		t=2,pk[1]=-1;
	else
		while(abs(pk[t]=pk[t-1]*k)<=maxv)
			++t;
	long long s=0;
	for(int i=1;i<=n;++i)
	{
		++m[s];
		s+=a[i];
		for(int d=0;d<t;++d)
			ans+=m[s-pk[d]];//m.count(s-pk[d]) ? m[s-pk[d]] : 0;
	}
	cout<<ans<<endl;
}