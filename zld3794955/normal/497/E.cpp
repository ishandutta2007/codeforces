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
const int K=33,mod=1000000007;
struct matrix
{
	long long a[K][K];
}t[K]={},ans={{}},pre[K]={},suf[K]={};
long long n;
int k;
inline void multi(const matrix &m1,const matrix &m2,matrix &to)
{
	static matrix tmp={{}};
	for(int i=0;i<=k;++i)
		for(int j=0;j<=k;++j)
		{
			tmp.a[i][j]=0;
			for(int p=0;p<=k;++p)
				(tmp.a[i][j]+=m1.a[i][p]*m2.a[p][j])%=mod;
		}
	to=tmp;
}
void init()
{
	cin>>n>>k;
	for(int i=0;i<=k;++i)
		for(int j=0;j<=k;++j)
			ans.a[i][j]=i==j;
	for(int p=0;p<k;++p)
		for(int i=0;i<=k;++i)
			for(int j=0;j<=k;++j)
				t[p].a[i][j]=i==j || i==p;
}
void work()
{
	vector<int> bit;
	for(;n;n/=k)
		bit.push_back(n%k);
	bit.push_back(0);
	partial_sum(bit.rbegin(),bit.rend(),bit.rbegin());
	for(auto p=0u;p<bit.size()-1;++p)
	{
		for(int i=bit[p]-1;i>=bit[p+1];--i)
			multi(t[i%k],ans,ans);
		pre[0]=t[0];
		for(int i=1;i<k;++i)
			multi(pre[i-1],t[i],pre[i]);
		suf[k-1]=t[k-1];
		for(int i=k-2;i>=0;--i)
			multi(t[i],suf[i+1],suf[i]);
		t[0]=suf[0];
		for(int i=1;i<k;++i)
			multi(suf[i],pre[i-1],t[i]);
	}
	long long sum=0;
	for(int i=0;i<=k;++i)
		sum+=ans.a[i][k];
	cout<<sum%mod<<endl;
}
int main()
{
	init();
	work();
	return 0;
}