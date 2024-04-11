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
int a1,a2,a3,b1,b2,b3,n;
int main()
{	
	cin>>a1>>a2>>a3>>b1>>b2>>b3>>n;
	if((a1+a2+a3+4)/5 + (b1+b2+b3+9)/10 <=n)
		puts("YES");
	else
		puts("NO");
	return 0;
}