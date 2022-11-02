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
int main()
{	
	for(int i=1,x=0;i<=5;++i)
		for(int j=1;j<=5;++j)
		{
			cin>>x;
			if(x)
			{
				cout<<abs(i-3)+abs(j-3)<<endl;
				return 0;
			}
		}
	return 0;
}