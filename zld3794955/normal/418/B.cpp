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
const int N=110,M=30;
struct thing
{
	long long x,k,m,state;
}t[N]={};
bool thing_cmp(const thing &t1,const thing &t2)
{
	return t1.k<t2.k;
}
long long n,m,b;
long long ans1=0,f[(1<<21)+100]={},ans=0x7fffffffffffffffll;
//queue<long long>q;
//bool in[(1<<21)+100]={};
void init()
{
	cin>>n>>m>>b;
	for(int i=1;i<=n;++i)
	{
		cin>>t[i].x>>t[i].k>>t[i].m;
		int a;
		for(int j=1;j<=t[i].m;++j)
		{
			cin>>a;
			t[i].state|=1<<a-1;
		}
	}
	sort(t+1,t+n+1,thing_cmp);
	for(int i=1;i<=(1<<m)-1;++i)
		f[i]=0x3fffffffffffffffll;
}
void dp(long long s,long long c)
{
	//cout<<s<<' '<<c<<endl;
	for(long long i=(1<<m)-1;i>=0;--i)
		if(f[i]+c<f[i|s])
			f[i|s]=f[i]+c;
	/*
	int t=q.size();
	while(t--)
	{
		long long state=q.front();
		q.pop();
		in[state]=false;
		if(f[state]+c<f[state|s])
		{
			f[state|s]=f[state]+c;
			if(!in[state|s])
			{
				in[state|s]=true;
				q.push(state|s);
			}
		}
	}*/
}
void work()
{
	//q.push(0);
	for(int i=1;i<=n;++i)
	{
		ans1=t[i].k*b;
		dp(t[i].state,t[i].x);
		ans=min(ans,ans1+f[(1<<m)-1]);
	}
	if(ans>=0x3fffffffffffffffll)
		printf("-1\n");
	else
		printf("%I64d\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}