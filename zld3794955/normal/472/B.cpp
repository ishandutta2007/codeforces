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
const int F=2020;
int s[F]={},n,k,v=0;
int main()
{	
	cin>>n>>k;
	for(int i=1,x=0;i<=n;++i)
	{
		cin>>x;
		++s[x];
		v=max(x,v);
	}
	for(int i=v;i>=1;--i)
		s[i]+=s[i+1];
	int ans=0;
	for(int i=2;i<=v;++i)
	{
		//cout<<"s[i]="<<s[i]<<endl;
		int x=(s[i]+k-1)/k;
		//cout<<"x="<<x<<endl;
		ans+=x+x-1;
	}
	ans+=v-1;
	cout<<ans<<endl;
	return 0;
}