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
int a,m;
int gcd(int a,int b)
{
	return b ? gcd(b,a%b) : a;
}
int main()
{	
	cin>>a>>m;
	m=m/gcd(m,a);
	while(m%2==0)
		m/=2;
	puts(m==1 ? "Yes" : "No");
	return 0;
}