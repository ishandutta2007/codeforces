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
int a,b,c,d,e;
int main()
{	
	cin>>a>>b>>c>>d>>e;
	int s=a+b+c+d+e;
	if(s && s%5==0)
		cout<<s/5<<endl;
	else
		cout<<-1<<endl;
	return 0;
}