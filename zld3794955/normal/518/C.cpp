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
const int N=100100,M=100100;
int n,m,k,a[N]={},b[N]={};
void init()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		b[a[i]]=i;
	}
}
void work()
{
	long long ans=0;
	for(int i=1,x=0;i<=m;++i)
	{
		scanf("%d",&x);
		int pos=b[x];
		ans+=(pos+k-1)/k;
		if(pos>1)
		{
			swap(a[pos-1],a[pos]);
			b[a[pos]]=pos;
			b[a[pos-1]]=pos-1;
		}
	}
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}