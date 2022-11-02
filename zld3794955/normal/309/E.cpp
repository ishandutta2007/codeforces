#include<bits/stdc++.h>
using namespace std;
const int N=2020,Inf=1<<30;
int n,a[N]={},last[N]={},l[N]={},r[N]={Inf},t[N]={};
bool check(int d)
{
	fill(last+1,last+n+1,n);
	fill(a+1,a+n+1,0);
	bool in[N]={};
	for(int i=1;i<=n;++i)
	{
		int p=0,b=0;
		fill(t,t+n+1,0);
		for(int j=1;j<=n;++j)
			t[last[j]]+=!in[j];
		for(int j=1;j<=n;++j)
			t[j]+=t[j-1];
		for(int j=1;j<=n;++j)
			if(t[j]>max(0,j-i+1))
				return false;
		for(int j=n;j>=i;--j)
			if(t[j]==j-i+1)
				b=j;
		for(int j=1;j<=n;++j)
			if(!in[j] && last[j]<=b && r[j]<r[p])
				p=j;
		a[i]=p;
		in[p]=true;
		for(int j=1;j<=n;++j)
			if(l[j]<=r[p] && r[j]>=l[p])
				last[j]=min(last[j],i+d);
	}
	return true;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>l[i]>>r[i];
	int l=1,r=n-1;
	for(int mid=(l+r)>>1; l!=r; mid=(l+r)>>1)
		check(mid) ? r=mid : l=mid+1;
	check(l);
	for(int i=1;i<=n;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	cerr<<"l="<<l<<endl;
	return 0;
}