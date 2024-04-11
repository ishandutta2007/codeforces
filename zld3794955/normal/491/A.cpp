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
int main()
{	
	int a,b;
	cin>>a>>b;
	for(int i=b+1;i>=1;--i)
		cout<<i<<' ';
	for(int i=b+2;i<=a+b+1;++i)
		cout<<i<<' ';
	cout<<endl;
	return 0;
}