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
const int N=2200;
int n,a[N]={},ans=0;
void dfs(int s)
{
	if(s*2>n)
		return;
	dfs(s*2);
	dfs(s*2+1);
	int a1=max(a[s*2],a[s*2+1]),a2=min(a[s*2],a[s*2+1]);
	//cout<<"s="<<s<<" a1="<<a1<<" a2="<<a2<<endl;
	a[s]+=a1;
	ans+=a1-a2;
}
int main()
{	
	cin>>n;
	n=(1<<(n+1))-1;
	for(int i=2;i<=n;++i)
		cin>>a[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}