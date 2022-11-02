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
int n,a,b,ans=0;
int main()
{
	cin>>a>>b;
	a-=b;
	if(a==0)
	{
		puts("infinity");
		return 0;
	}
	for(int i=1;i*i<=a;++i)
		if(a%i==0)
		{
			ans+=i>b;
			if(i*i<a)
				ans+=a/i>b;
		}
	cout<<ans<<endl;
	return 0;
}