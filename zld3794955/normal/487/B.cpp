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
const int N=100010,Inf=1<<30;
int n,s,l,a[N]={},f[N]={};
void init()
{
	scanf("%d%d%d",&n,&s,&l);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
}
void work()
{
	fill(f+1,f+n+1,Inf);
	multiset<int> num;
	multiset<int> fmin;
	for(int i=1;i<l;++i)
		num.insert(a[i]);
	int pos=0;
	for(int i=l;i<=n;++i)
	{
		//cout<<"i="<<i<<" pos="<<pos<<endl;
		num.insert(a[i]);
		fmin.insert(f[i-l]);
		//cout<<"delta="<<*num.rbegin()-*num.begin()<<endl;
		while(pos<=i-l && *num.rbegin()-*num.begin()>s)
		{
			fmin.erase(fmin.find(f[pos]));
			++pos;
			num.erase(num.find(a[pos]));
		}
		//cout<<"bao"<<endl;
		if(pos<=i-l)
			f[i]=*fmin.begin()+1;
	}
	printf("%d\n",f[n]>=Inf ? -1 : f[n]);
}
int main()
{	
	init();
	work();
	return 0;
}