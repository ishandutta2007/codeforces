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
int a,s[10]={119,18,93,91,58,107,111,82,127,123};
int main()
{
	cin>>a;
	int s1=0,s2=0;
	for(int i=0;i<=9;++i)
		if((s[i]&s[a/10])==s[a/10])
			++s1;
	for(int i=0;i<=9;++i)
		if((s[i]&s[a%10])==s[a%10])
			++s2;
	cout<<s1*s2<<endl;
	return 0;
}