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
#include<numeric>
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
const int N=100010;
int n,a[N]={},s1[N]={},s2[N]={},t1=0,t2=0,ans=0;
pair<int,int> way[N];
int getr(int p,int t)
{
	int l=p,r=n;
	while(l!=r)
	{
		int mid=(l+r)>>1;
		if(s1[mid]-s1[p-1]>=t || s2[mid]-s2[p-1]>=t)
			r=mid;
		else
			l=mid+1;
	}
	if(s1[l]-s1[p-1]>=t)
		++t1;
	else
		++t2;
	return l;
}
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s1[i]=s1[i-1]+(a[i]==1);
		s2[i]=s2[i-1]+(a[i]==2);
	}
	for(int t=n;t>=1;--t)
	{
		t1=t2=0;
		int last=0,now=1;
		while(now<=n)
		{
			last=now;
			now=getr(last,t)+1;
		}
		if(s1[now-1]-s1[last-1]>=t && t1>t2)
			way[++ans]=make_pair(t1,t);
		if(s2[now-1]-s2[last-1]>=t && t1<t2)
			way[++ans]=make_pair(t2,t);
	}
	sort(way+1,way+ans+1);
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)
		printf("%d %d\n",way[i].first,way[i].second);
	return 0;
}