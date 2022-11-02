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
const int N=1010;
int n,w[N]={},h[N]={};
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>w[i]>>h[i];
	int ans=1<<30;
	for(int H=1;H<=1000;++H)
	{
		int t=0,s=0,d[N]={},tot=0;
		bool flag=true;
		for(int i=1;i<=n;++i)
			if(h[i]>H)
			{
				if(w[i]>H)
					flag=false;
				else
					++t,s+=h[i];
			}
		if(!flag || t>n/2)
			continue;
		for(int i=1;i<=n;++i)
			if(h[i]<=H)
			{
				s+=w[i];
				if(w[i]<=H)
					d[++tot]=h[i]-w[i];
			}
		sort(d+1,d+tot+1);
		for(int i=1;i<=tot && d[i]<0 && t<n/2;++i)
			s+=d[i],++t;
		ans=min(ans,s*H);
	}
	cout<<ans<<endl;
	return 0;
}