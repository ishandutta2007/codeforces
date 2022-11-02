#include<bits/stdc++.h>
using namespace std;
const int N=1000100;
int n,a[N]={},t[N]={};
long long l,B,d,s=0;
void init()
{
	scanf("%d%I64d%I64d",&n,&l,&B);
	B=B*2+l, d=B%l;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	s=(long long)n*(n-1)*(B/l);
}
void work()
{
	int p=1;
	for(int i=1;i<=n;++i)
	{
		while(a[i]-a[p]>d)
			++p;
		s-=p-1;
	}
	p=1;
	for(int i=1;i<=n;++i)
	{
		while(l+a[p]-a[i]<=d)
			++p;
		s-=i-p;
	}
	printf("%I64d%s\n",s/4,s%4==1?".25":s%4==2?".5":s%4==3?".75":"");
}
int main()
{	
	init();
	work();
	return 0;
}