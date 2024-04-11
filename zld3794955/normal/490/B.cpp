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
const int N=200020;
map<int,int> m;
set<int> s;
int n,a[N]={},tot=0;
int main()
{	
	cin>>n;
	for(int i=1,l=0,r=0;i<=n;++i)
	{
		cin>>l>>r;
		m[l]=r;
		s.insert(l);
		s.insert(r);
	}
	tot=0;
	while(int tmp=m[a[tot]])
		a[tot+=2]=tmp;
	for(map<int,int>::iterator it=m.begin();it!=m.end();++it)
		s.erase(it->second);
	a[tot=1]=*s.begin();
	while(int tmp=m[a[tot]])
		a[tot+=2]=tmp;
	for(int i=1;i<=n;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}