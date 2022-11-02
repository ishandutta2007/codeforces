#include<bits/stdc++.h>
using namespace std;
const int N=200020;
struct seg
{
	int l,r,num;
}t[N]={};
int m,n;
bool use[N]={};
void init()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&t[i].l,&t[i].r);
		t[i].r+=t[i].l-1, t[i].num=i;
	}
	sort(t+1,t+n+1,[](const seg &s1,const seg &s2){return s1.l<s2.l;});
}
void work()
{
	int lastl=0,pos=1,maxp=0;
	while(pos<=n)
	{
		if(t[pos].l>lastl+1)
			lastl=t[pos].l-1;
		while(pos<=n && t[pos].l<=lastl+1)
		{
			if(t[pos].r>t[maxp].r)
				maxp=pos;
			++pos;
		}
		lastl=t[maxp].r;
		use[t[maxp].num]=true;
	}
	int tot=0;
	for(int i=1;i<=n;++i)
		tot+=!use[i];
	printf("%d\n",tot);
	for(int i=1;i<=n;++i)
		if(!use[i])
			printf("%d ",i);
	printf("\n");
}
int main()
{
	init();
	work();
	return 0;
}