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
const int N=100100,mod=1000000007;
int n;
int color[N]={};
long long f[N][2]={};
vector<int> v[N];
void init()
{
	scanf("%d",&n);
	for(int i=2,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		v[x+1].push_back(i);
	}
	for(int i=1;i<=n;++i)
		scanf("%d",&color[i]);
}
void dfs(int s)
{
	f[s][color[s]]=1;
	long long x1=0,x2=0;
	for(vector<int>::iterator it=v[s].begin();it!=v[s].end();++it)
	{
		dfs(*it);
		x1=f[s][0]*f[*it][0];
		x2=f[s][1]*f[*it][0]+f[s][0]*f[*it][1];
		f[s][0]=x1%mod;
		f[s][1]=x2%mod;
	}
	f[s][0]=(f[s][0]+f[s][1])%mod;
	//cout<<"s="<<s<<" f[s][0]="<<f[s][0]<<" f[s][1]="<<f[s][1]<<endl;
}
void work()
{
	dfs(1);
	cout<<f[1][1]<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}