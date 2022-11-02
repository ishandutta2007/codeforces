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
const int N=200020;
int n,p[N]={},q[N]={},a[N]={};
int rp[N]={},rq[N]={},t[N]={};
int rans[N]={},ans[N]={};
inline void add(int pos)
{
	for(int i=pos;i<=n;i+=i&(-i))
		++t[i];
}
inline void dec(int pos)
{
	for(int i=pos;i<=n;i+=i&(-i))
		--t[i];
}
inline int sum(int pos)
{
	int s=0;
	for(;pos;pos-=pos&(-pos))
		s+=t[pos];
	return s;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&p[i]),++p[i];
	for(int i=1;i<=n;++i)
		scanf("%d",&q[i]),++q[i];
}
void sum()
{
	for(int i=n;i>=1;--i)
	{
		rp[i]=sum(p[i]);
		add(p[i]);
	}
	fill(t+1,t+n+1,0);
	for(int i=n;i>=1;--i)
	{
		rq[i]=sum(q[i]);
		add(q[i]);
	}
	fill(t+1,t+n+1,0);
	for(int i=n;i>=1;--i)
	{
		rans[i]+=rp[i]+rq[i];
		rans[i-1]+=rans[i]/(n-i+1);
		rans[i]%=(n-i+1);
	}
	for(int i=1;i<=n;++i)
		++rans[i];
	/*
	for(int i=1;i<=n;++i)
		cout<<rans[i]<<' ';
	cout<<endl;
	*/
}
void get_ans()
{
	for(int i=1;i<=n;++i)
		add(i);
	for(int i=1;i<=n;++i)
	{
		int l=1,r=n;
		//cout<<"i="<<i<<endl;
		while(l!=r)
		{
			int mid=(l+r)>>1;
			//cout<<"mid="<<mid<<" sum="<<sum(mid)<<endl;
			if(sum(mid)>=rans[i])
				r=mid;
			else
				l=mid+1;
		}
		printf("%d ",l-1);
		dec(l);
	}
	printf("\n");
}
int main()
{
	init();
	sum();
	get_ans();
	return 0;
}