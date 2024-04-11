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
const int N=110;
int n,a[N]={},s=0,ans=1<<30;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<n;++i)
		s=max(s,a[i+1]-a[i]);
	for(int i=1;i<=n-2;++i)
		ans=min(ans,max(s,a[i+2]-a[i]));
	cout<<ans<<endl;
	return 0;
}