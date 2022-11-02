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
int n,x,l[N]={},r[N]={},ans=0;
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;++i)
		cin>>l[i]>>r[i];
	for(int i=1;i<=n;++i)
		ans+=r[i]-l[i]+1+(l[i]-r[i-1]-1)%x;
	cout<<ans<<endl;
	return 0;
}