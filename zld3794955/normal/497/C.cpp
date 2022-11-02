#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int N=100010,M=100010,Inf=0x7fffffff;
struct sing
{
	int l,r,num;
}a[N]={},b[M]={};
bool sing_cmp(const sing &s1,const sing &s2)
{
	return s1.r<s2.r;
}
int n,m,k[M]={},way[N]={},v[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
		v[i]=a[i].r;
		a[i].num=i;
	}
	sort(a+1,a+n+1,sing_cmp);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&b[i].l,&b[i].r,&k[i]);
		b[i].num=i;
	}
	sort(b+1,b+m+1,sing_cmp);
}
void arrange()
{
	int pos=1;
	multimap<int,int> song;
	for(int i=1;i<=m;++i)
	{
		while(pos<=n && a[pos].r<=b[i].r)
			song.insert(make_pair(a[pos].l,a[pos].num)),++pos;
		multimap<int,int>::iterator it=song.lower_bound(b[i].l);
		while(it!=song.end() && k[b[i].num])
		{
			way[it->second]=b[i].num;
			--k[b[i].num];
			song.erase(it);
			it=song.lower_bound(b[i].l);
		}
	}
	if(pos<=n || !song.empty())
	{
		puts("NO");
		return;
	}
	puts("YES");
	for(int i=1;i<=n;++i)
		printf("%d ",way[i]);
	printf("\n");
}
int main()
{	
	init();
	arrange();
	return 0;
}