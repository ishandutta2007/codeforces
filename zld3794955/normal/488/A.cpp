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
int a,b=0;
bool check(int v)
{
	for(;v;v/=10)
		if(v%10==8 || v%10==-8)
			return true;
	return false;
}
int main()
{	
	cin>>a;
	while(!check(a+(++b)))
		;
	cout<<b<<endl;
	return 0;
}