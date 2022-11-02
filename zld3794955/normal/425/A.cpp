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
const int N=220;
int n,k,a[N]={},n1[N]={},n2[N]={},ans=-0x7fffffff;
void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
}
void work(int l,int r)
{
	int t1=0,t2=0,s=0;
	for(int i=1;i<l;++i)
		n1[++t1]=a[i];
	for(int i=r+1;i<=n;++i)
		n1[++t1]=a[i];
	for(int i=l;i<=r;++i)
		n2[++t2]=a[i],s+=a[i];
	sort(n1+1,n1+t1+1);
	sort(n2+1,n2+t2+1);
	for(int i=1;i<=k && i<=t1 && i<=t2 && n1[t1+1-i]>n2[i];++i)
	{
		s+=n1[t1+1-i];
		s-=n2[i];
	}
	ans=max(ans,s);
}
void work()
{
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			work(i,j);
	printf("%d\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}