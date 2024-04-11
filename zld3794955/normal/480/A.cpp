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
const int N=5050;
struct exam
{
	int a,b;
}t[N]={};
bool cmp(const exam &e1,const exam &e2)
{
	return e1.a<e2.a || (e1.a==e2.a && e1.b<e2.b);
}
int n;
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>t[i].a>>t[i].b;
	sort(t+1,t+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(t[i].b<ans)
			ans=t[i].a;
		else
			ans=t[i].b;
	}
	cout<<ans<<endl;
	return 0;
}