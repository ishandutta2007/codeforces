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
long long n,m,a[110]={},b[110]={},s1=0;
bool d[110]={};
int main()
{	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int j=1;j<=m;++j)
	{
		cin>>b[j];
		d[j]=true;
		b[j]=a[b[j]];
		s1-=b[j];
	}
	for(int i=1;i<=n;++i)
		s1+=a[i];
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=m;++j)
			b[j]=max(b[j],s1);
		long long x=0;
		for(int j=1;j<=m;++j)
			if(d[j] && b[j]>b[x])
				x=j;
		d[x]=false;
		s1+=b[x];
	}
	cout<<s1<<endl;
	return 0;
}