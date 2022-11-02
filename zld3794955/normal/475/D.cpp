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
const int N=100010,D=20;
map<int,long long> tot;
int n,a[N]={},g[N][D]={},dt[N]={};
inline int gcd(int a,int b)
{
	while(int r=a%b)
	{
		a=b;
		b=r;
	}
	return b;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&g[i][0]);
		a[i]=g[i][0];
	}
	for(int d=1,s=2;s<=n;++d,s<<=1)
		for(int i=1;i<=n-s+1;++i)
			g[i][d]=gcd(g[i][d-1],g[i+(1<<(d-1))][d-1]);
	for(int i=1;i<=n;++i)
	{
		if((1<<(dt[i-1]+1))<=i)
			dt[i]=dt[i-1]+1;
		else
			dt[i]=dt[i-1];
	}
	//for(int i=1;i<=n;++i)
	//	cout<<dt[i]<<' ';
	//cout<<endl;
}
inline int seg_gcd(int l,int r)
{
	//cout<<"l="<<l<<" r="<<r<<endl;
	int d=dt[r-l];
	return gcd(g[l][d],g[r-(1<<d)+1][d]);
}
inline int get_next(int s,int lg)
{
	int l=s,r=n;
	while(l!=r)
	{
		//cout<<"er l="<<l<<" r="<<r<<endl;
		int mid=(l+r+1)>>1;
		//cout<<"s="<<s<<" mid="<<mid<<endl;
		if(seg_gcd(s,mid)>=lg)
			l=mid;
		else
			r=mid-1;
		//cout<<"er l="<<l<<" r="<<r<<endl;
	}
	return l;
}
void work()
{
	for(int i=1;i<=n;++i)
	{
		//cout<<"aogiadsngo i="<<i<<endl;
		int nowgcd=a[i],last=i-1,pos=i-1;
		while(pos<n)
		{
			nowgcd=gcd(nowgcd,a[pos+1]);
			last=pos;
			pos=get_next(i,nowgcd);
			//cout<<"nowgcd="<<nowgcd<<" pos="<<pos<<" last="<<last<<endl;
			tot[nowgcd]+=pos-last;
			//cout<<"last="<<last<<" pos="<<pos<<endl;
			nowgcd=seg_gcd(i,pos);
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=1,x=0;i<=q;++i)
	{
		scanf("%d",&x);
		printf("%I64d\n",tot[x]);
	}
}
int main()
{	
	init();
	work();
	return 0;
}