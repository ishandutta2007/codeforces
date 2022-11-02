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
const int N=1010;
int n,m;
string s1,s2;
map<string,string> translate;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>s1>>s2;
		translate[s1]=translate[s2]=s1.size()<=s2.size() ? s1 : s2;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>s1;
		cout<<translate[s1]<<' ';
	}
	cout<<endl;
	return 0;
}