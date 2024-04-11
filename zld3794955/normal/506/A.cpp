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
const int N=30030,L=1000,MD=30000;
int n,d,a[N]={},f[N][L]={};
map<int,int> g[N];
bool b[N][L]={};
int dp(int pos,int l)
{
	if(l<L && b[pos][l])
		return f[pos][l];
	if(g[pos].count(l))
		return g[pos][l];
	if(l<L)
		b[pos][l]=true;
	if(pos+l<=MD)
	{
		int tmp=(l-1) ? dp(pos+l,l-1) : 0;
		tmp=max(tmp,dp(pos+l,l));
		tmp=max(tmp,dp(pos+l,l+1));
		(l<L ? f[pos][l] : g[pos][l])=tmp;
	}
	return (l<L ? f[pos][l] : g[pos][l])+=a[pos];
}
int main()
{	
	cin>>n>>d;
	for(int i=1,x=0;i<=n;++i)
	{
		cin>>x;
		++a[x];
	}
	cout<<dp(0,d)<<endl;
	return 0;
}