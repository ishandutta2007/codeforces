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
const int N=20;
int n,a[N]={},tot=0;
int main()
{	
	cin>>n;
	while(n)
	{
		++tot;
		int s=1;
		for(int i=1;i<=7;++i,s*=10)
			if(n/s%10)
			{
				n-=s;
				a[tot]+=s;
			}
	}
	cout<<tot<<endl;
	for(int i=1;i<=tot;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}