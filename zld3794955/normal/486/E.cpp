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
const int N=100010;
int n,a[N]={},f[N]={},len=0,LISlen;
int l1[N]={},l2[N]={},tot[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
}
void LIS_front()
{
	fill(f,f+N,0);
	len=0;
	for(int i=1;i<=n;++i)
		if(a[i]>f[len])
			f[l1[i]=++len]=a[i];
		else
			f[l1[i]=lower_bound(f+1,f+len+1,a[i])-f]=a[i];
	LISlen=len;
}
void LIS_back()
{
	fill(f,f+N,0);
	len=0;
	f[0]=1<<30;
	for(int i=n;i>=1;--i)
		if(a[i]<f[len])
			f[l2[i]=++len]=a[i];
		else
			f[l2[i]=lower_bound(f+1,f+len+1,a[i],greater<int>())-f]=a[i];
	LISlen=len;
}
void work()
{
	for(int i=1;i<=n;++i)
		if(l1[i]+l2[i]-1==LISlen)
			++tot[l1[i]];
	for(int i=1;i<=n;++i)
		if(l1[i]+l2[i]-1<LISlen)
			putchar('1');
		else
			if(tot[l1[i]]==1)
				putchar('3');
			else
				putchar('2');
	putchar('\n');
}
int main()
{	
	init();
	LIS_front();
	LIS_back();
	work();
	return 0;
}