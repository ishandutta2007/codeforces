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
const int N=3030;
int n,a[N]={};
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		ans+=max(0,a[i-1]+1-a[i]);
		a[i]=max(a[i],a[i-1]+1);
	}
	cout<<ans<<endl;
	return 0;
}