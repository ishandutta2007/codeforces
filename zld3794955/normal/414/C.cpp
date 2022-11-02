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
const int D=20,N=(1<<D)+10;
int n,a[N]={},b[N]={};
long long tot=0,num[D+5]={},e[D+5]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=(1<<n);++i)
		scanf("%d",&a[i]);
}
void get_reverse_pair(int l,int r,int d)
{
	if(l==r)
		return;
	int mid=l+r>>1;
	get_reverse_pair(l,mid,d-1);
	get_reverse_pair(mid+1,r,d-1);
	copy(a+l,a+mid+1,b+l);
	copy(a+mid+1,a+r+1,b+mid+1);
	int p1=l,p2=mid+1,p=l,last=-1,t=0;
	long long sum=0;
	while(p1<=mid && p2<=r)
	{
		if(b[p1]>b[p2])
		{
			if(b[p1]==last)
				e[d]+=t;
			a[p++]=b[p1++];
		}
		else
		{
			sum+=(p1-l);
			if(b[p2]==last)
				++t;
			else
			{
				t=1;
				last=b[p2];
			}
			a[p++]=b[p2++];
		}
	}
	while(p1<=mid)
	{
		if(b[p1]==last)
			e[d]+=t;
		a[p++]=b[p1++];
	}
	while(p2<=r)
	{
		a[p++]=b[p2++];
		sum+=p1-l;
	}
	tot+=sum;
	num[d]+=sum;
}
void query()
{
	int q(0);
	scanf("%d",&q);
	for(int i=1,d=0;i<=q;++i)
	{
		scanf("%d",&d);
		for(int j=d;j>=1;--j)
		{
			tot=tot-num[j];
			num[j]=(1ll<<(n+j-2))-e[j]-num[j];
			tot=tot+num[j];
		}
		printf("%I64d\n",tot);
	}
}
int main()
{	
	init();
	get_reverse_pair(1,1<<n,n);
	query();
	return 0;
}