#include<bits/stdc++.h>
using namespace std;
const int N=300030,D=30;
int n,a[N]={},x=0,tmp[N]={};
long long p[D+1]={},q[D+1]={},ans=0;
void work(int l,int r,int d)
{
	if(l>r || d<0)
		return;
	/*
	cout<<"l="<<l<<" r="<<r<<" d="<<d<<endl;
	for(int i=l;i<=r;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	*/
	int t0=0,t1=0;
	for(int i=l;i<=r;++i)
	{
		if((a[i]&(1<<d)))
		{
			++t1;
			p[d]+=t0;
		}
		else
		{
			++t0;
			q[d]+=t1;
		}
	}
	int pos=l,mid;
	for(int i=l;i<=r;++i)
		if((a[i]&(1<<d)))
			tmp[pos++]=a[i];
	mid=pos;
	for(int i=l;i<=r;++i)
		if(!(a[i]&(1<<d)))
			tmp[pos++]=a[i];
	copy(tmp+l,tmp+pos,a+l);
	work(l,mid-1,d-1);
	work(mid,r,d-1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	work(1,n,D);
	for(int d=D;d>=0;--d)
		if(p[d]<q[d])
		{
			x|=1<<d;
			ans+=p[d];
		}
		else
			ans+=q[d];
	cout<<ans<<' '<<x<<endl;
}