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
const int N=55;
int n,k,a[N]={};
int main()
{	
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	if(k>n)
	{
		cout<<-1<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int sum=0;
	for(int i=1;i<=n;++i)
		sum+=a[k]<=a[i];
	if(sum==k)
		cout<<a[k]<<' '<<a[k]<<endl;
	else
		cout<<-1<<endl;
	return 0;
}