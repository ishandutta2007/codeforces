#include<iostream>
#include<cstdio>
using namespace std;
const int N=1001000;
int n,a[N]={},pos[N]={},tot=0;
long long f[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
}
void get_v()
{
	pos[++tot]=1;
	if(n==1)
		return;
	pos[++tot]=2;
	for(int i=2;i<n;++i)
		if((a[i]>a[i-1] && a[i]>=a[i+1]) || (a[i]<a[i-1] && a[i]<=a[i+1]))
		{
			if(pos[tot]<i-1)
				pos[++tot]=i-1;
			if(pos[tot]<i)
				pos[++tot]=i;
			if(pos[tot]<i+1)
				pos[++tot]=i+1;
		}
	if(pos[tot]<n-1)
		pos[++tot]=n-1;
	if(pos[tot]<n)
		pos[++tot]=n;
}
void work()
{
	for(int i=1;i<=tot;++i)
	{
		int minv=1<<30,maxv=-1<<30;
		for(int j=i;j>=1 && j>=i-10;--j)
		{
			minv=min(minv,a[pos[j]]);
			maxv=max(maxv,a[pos[j]]);
			f[i]=max(f[i],f[j-1]+maxv-minv);
		}
	}
	cout<<f[tot]<<endl;
}
int main()
{	
	init();
	get_v();
	work();
	return 0;
}