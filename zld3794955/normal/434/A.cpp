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
const int N=100100;
int n,m,a[N]={};
long long sum=0,ans=1ll<<60;
vector<int>v[N];
void init()
{
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		printf("0\n");
		return;
	}
	for(int i=1;i<=m;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<m;++i)
		sum+=max(a[i],a[i+1])-min(a[i],a[i+1]);
	if(a[2]!=a[1])
		v[a[1]].push_back(a[2]);
	if(a[m]!=a[m-1])
		v[a[m]].push_back(a[m-1]);
	for(int i=2;i<m;++i)
	{
		if(a[i-1]!=a[i])
			v[a[i]].push_back(a[i-1]);
		if(a[i+1]!=a[i])
			v[a[i]].push_back(a[i+1]);
	}
	ans=sum;
	for(int i=1;i<=n;++i)
		sort(v[i].begin(),v[i].end());
}
long long calc(const vector<int>& v,int value)
{
	long long sum=0;
	for(vector<int>::size_type i=0;i<v.size();++i)
		sum+=max(v[i],value)-min(v[i],value);
	return sum;
}
void work()
{
	for(int i=1;i<=n;++i)
		if(v[i].size())
		{
			long long ans1=calc(v[i],i);
			long long ans2=calc(v[i],v[i][v[i].size()/2]);
			ans=min(ans,sum-ans1+ans2);
		}
	cout<<ans<<endl;
}
int main()
{	
	init();
	if(m>1)
		work();
	return 0;
}