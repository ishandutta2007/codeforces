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
const int N=55;
int p,q,l,r,ans=0,a[N]={},b[N]={},c[N]={},d[N]={};
int main()
{
	cin>>p>>q>>l>>r;
	for(int i=1;i<=p;++i)
		cin>>a[i]>>b[i];
	for(int i=1;i<=q;++i)
		cin>>c[i]>>d[i];
	for(int t=l;t<=r;++t)
	{
		bool flag=false;
		for(int i=1;i<=p && !flag;++i)
			for(int j=1;j<=q && !flag;++j)
				flag|=b[i]>=(c[j]+t) && a[i]<=(d[j]+t);
		ans+=flag;
	}
	cout<<ans<<endl;
	return 0;
}