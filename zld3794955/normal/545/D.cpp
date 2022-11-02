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
const int N=100010;
int n,t[N]={},ans=0;
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>t[i];
	sort(t+1,t+n+1);
	long long s=0;
	for(int i=1;i<=n;++i)
		if(s<=t[i])
			s+=t[i],++ans;
	cout<<ans<<endl;
	return 0;
}