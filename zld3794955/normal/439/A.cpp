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
int n,d,t[110]={},s=0;
int main()
{	
	cin>>n>>d;
	for(int i=1;i<=n;++i)
		cin>>t[i];
	for(int i=1;i<=n;++i)
		s+=t[i];
	if(s+10*(n-1)<=d)
		cout<<(d-s)/5<<endl;
	else
		cout<<-1<<endl;
	return 0;
}