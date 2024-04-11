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
const int N=550,M=1100;
int n,m,w[N]={},b[M]={},p[N]={},tot=0,ans=0;
bool a[N]={};
int main()
{	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>w[i];
	for(int j=1;j<=m;++j)
	{
		cin>>b[j];
		if(!a[b[j]])
		{
			a[b[j]]=true;
			p[++tot]=b[j];
		}
	}
	for(int i=1;i<=n;++i)
		if(!a[i])
			p[++tot]=i,a[i]=true;
	for(int i=1;i<=m;++i)
	{
		int pos=0;
		for(pos=1;pos<=n;++pos)
			if(p[pos]==b[i])
				break;
		for(int j=pos-1;j>=1;--j)
		{
			ans+=w[p[j]];
			swap(p[j],p[j+1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}