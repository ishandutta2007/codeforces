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
const int N=5050;
int n,k,a[N]={};
map<int,int> m;
void init()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		for(int j=1;j<=k;++j)
			if(!m.count(a[i]*j))
				m[a[i]*j]=j;
			else
				m[a[i]*j]=min(m[a[i]*j],j);
	}
	m[0]=0;
}
void work()
{
	int q,x;
	cin>>q;
	while(q--)
	{
		cin>>x;
		int ans=k+1;
		for(auto it=m.begin();it!=m.end();++it)
			if(m.count(x-it->first))
				ans=min(ans,it->second+m[x-it->first]);
		if(ans>k)
			puts("-1");
		else
			cout<<ans<<endl;
	}
}
int main()
{
	init();
	work();
	return 0;
}