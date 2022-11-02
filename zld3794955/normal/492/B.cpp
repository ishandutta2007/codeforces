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
const int N=1010;
int n,l,ans=0,a[N]={};
int main()
{	
	cin>>n>>l;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	ans=max(a[1]*2,(l-a[n])*2);
	for(int i=1;i<n;++i)
		ans=max(ans,a[i+1]-a[i]);
	if(ans%2)
		cout<<ans/2<<".5000000000"<<endl;
	else
		cout<<ans/2<<".0000000000"<<endl;
	return 0;
}