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
const int N=110;
char ch[N]={};
int n;
int main()
{	
	cin>>n>>(ch+1);
	for(int i=1;i<=n;++i)
		for(int d=1;i+d*4<=n;++d)
			if(ch[i]=='*' && ch[i+d]=='*' && ch[i+d+d]=='*' && ch[i+d*3]=='*' && ch[i+d*4]=='*')
			{
				puts("yes");
				return 0;
			}
	puts("no");
	return 0;
}