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
long long m,n;
int main()
{	
	cin>>n>>m;
	cout<<(n%m)*(n/m+1)*(n/m)/2 + (m-n%m)*(n/m)*(n/m-1)/2;
	cout<<' '<<(n-m+1)*(n-m)/2<<endl;
	return 0;
}