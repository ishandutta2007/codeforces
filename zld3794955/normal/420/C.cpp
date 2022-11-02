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
const int N=300300;
int n,p,s[N]={},v[N]={};
map<int,int>m[N];
void init()
{
	scanf("%d%d",&n,&p);
	int x1,x2;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&x1,&x2);
		++s[x1];
		++s[x2];
		++m[x1][x2];
		++m[x2][x1];
	}
	copy(s+1,s+n+1,v+1);
	sort(v+1,v+n+1);
}
void work()
{
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		ans+=n+1-(lower_bound(v+1,v+n+1,p-s[i])-v);
		if(s[i]+s[i]>=p)
			--ans;
		for(map<int,int>::iterator it=m[i].begin();it!=m[i].end();++it)
			if(s[i]+s[it->first]>=p && s[i]+s[it->first]-it->second<p)
				--ans;
	}
	cout<<ans/2<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}