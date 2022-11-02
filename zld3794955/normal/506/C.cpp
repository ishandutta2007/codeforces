#include<bits/stdc++.h>
using namespace std;
const int N=100100,M=5050;
int n,m,k,p;
long long a[N]={},h[N]={},l[N]={};
bool check(long long mid)
{
	long long total=0;
	for(int i=1;i<=n;++i)
		total+=max(0ll,(l[i]-mid+p-1)/p);
	if((total-1)/m>=k)
		return false;
	int t[M]={},now=0;
	for(int i=1;i<=n;++i)
		if(l[i]>mid)
			for(long long cut=(l[i]-mid-1)%p+1;cut<=l[i]-mid;cut+=p)
				++t[max(0ll,(cut-h[i]+a[i]-1)/a[i])];
	for(int i=0;i<m;++i)
		now=max(0,now+t[i]-k);
	return now==0;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k>>p;
	for(int i=1;i<=n;++i)
	{
		cin>>h[i]>>a[i];
		l[i]=h[i]+a[i]*m;
	}
	long long l=*max_element(a+1,a+n+1),r=*max_element(::l+1,::l+n+1);
	for(long long mid=(l+r)>>1; l!=r; mid=(l+r)>>1)
		check(mid) ? r=mid : l=mid+1;
	cout<<l<<endl;
	return 0;
}