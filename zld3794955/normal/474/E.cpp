#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100100;
int n,tpre[N]={},tsuf[N]={},len[N]={},f[N]={},p[N]={};
long long d,h[N]={},v[N]={};
bool cmp(int x,int y)
{
	return len[x]<len[y];
}
inline void add_pre(int pos,int v)
{
	for(int i=pos;i<=n;i+=i&(-i))
		tpre[i]=max(tpre[i],v,cmp);
}
inline void add_suf(int pos,int v)
{
	for(int i=pos;i;i-=i&(-i))
		tsuf[i]=max(tsuf[i],v,cmp);
}
inline int max_pre(int pos)
{
	int s=0;
	for(int i=pos;i;i-=i&(-i))
		s=max(s,tpre[i],cmp);
	return s;
}
inline int max_suf(int pos)
{
	int s=0;
	for(int i=pos;i<=n;i+=i&(-i))
		s=max(s,tsuf[i],cmp);
	return s;
}
void init()
{
	scanf("%d%I64d",&n,&d);
	for(int i=1;i<=n;++i)
	{
		scanf("%I64d",&h[i]);
		v[i]=h[i];
	}
	sort(v+1,v+n+1);
	for(int i=1;i<=n;++i)
		p[i]=lower_bound(v+1,v+n+1,h[i])-v;
}
void work()
{
	for(int i=1;i<=n;++i)
	{
		long long l=h[i]-d,r=h[i]+d;
		l=upper_bound(v+1,v+n+1,l)-v-1;
		r=lower_bound(v+1,v+n+1,r)-v;
		int s=max(max_pre(l),max_suf(r),cmp);
		f[i]=s;
		len[i]=len[s]+1;
		add_pre(p[i],i);
		add_suf(p[i],i);
	}
	int now=max_element(len+1,len+n+1)-len,w[N]={},tot=0;
	printf("%d\n",len[now]);
	while(now)
	{
		w[++tot]=now;
		now=f[now];
	}
	for(int i=tot;i>=1;--i)
		printf("%d ",w[i]);
	printf("\n");
}
int main()
{	
	init();
	work();
	return 0;
}