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
int n,m,a,b;
int main()
{	
	int ans=1<<30;
	cin>>n>>m>>a>>b;
	for(int i=0;i<=1000;++i)
		for(int j=0;j<=1000;++j)
			if(i+j*m>=n)
				ans=min(ans,i*a+j*b);
	cout<<ans<<endl;
	return 0;
}