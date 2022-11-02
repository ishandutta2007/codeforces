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
const int T=200020,mod=1000000007;
int r,g,h=0,f[T]={};
int main()
{	
	cin>>r>>g;
	while(h*(h+1)/2 <= r+g)
		++h;
	--h;
	//cout<<"h="<<h<<endl;
	if(r<g)
		swap(r,g);
	f[0]=1;
	for(int i=1;i<=h;++i)
		for(int j=g;j>=i;--j)
			f[j]=(f[j]+f[j-i])%mod;
	int l=min(g,r+g-h*(h+1)/2),ans=0;
	//for(int i=0;i<=g;++i)
	//	cout<<f[i]<<' ';
	//cout<<endl;
	//cout<<"l="<<l<<endl;
	for(int i=g-l;i<=g;++i)
		ans=(ans+f[i])%mod;
	cout<<ans<<endl;
	return 0;
}