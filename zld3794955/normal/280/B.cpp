#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int n,a[N]={},ans=0;
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
}
void calcl(int s,int d)
{
	int v=0,p=s-1;
	while(p && a[p]<a[s] && (a[p]&(1<<d))==0)
		v=max(v,a[p]),ans=max(ans,v^a[s]),--p;
}
void calcr(int s,int d)
{
	int v=0,p=s+1;
	while(p<=n && a[p]<a[s] && (a[p]&(1<<d))==0)
		v=max(v,a[p]),ans=max(ans,v^a[s]),++p;
}
void work()
{
	for(int d=30;d>=0;--d)
	{
		int t[2]={};
		for(int i=1;i<=n;++i)
			++t[bool(a[i]&(1<<d))];
		if(t[0] && t[1])
		{
			for(int i=1;i<=n;++i)
				if(a[i]&(1<<d))
					calcl(i,d),calcr(i,d);
			break;
		}
	}
	printf("%d\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}