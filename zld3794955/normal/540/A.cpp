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
char s[N]={},t[N]={};
int n;
inline int abs(int x)
{
	return x>=0 ? x : -x;
}
int main()
{	
	cin>>n>>s>>t;
	int ans=0;
	for(int i=0;i<n;++i)
	{
		int x=s[i]-'0',y=t[i]-'0';
		ans+=min(abs(x-y),10-abs(x-y));
	}
	cout<<ans<<endl;
	return 0;
}