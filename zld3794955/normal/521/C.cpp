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
const int N=100100,mod=1000000007;
int n,k;
long long d[N]={1},re[N]={1,1},red[N]={1,1},bp[N]={1},s[N]={};
char ch[N]={};
inline long long C(int n,int m)
{
	return n<m || m<0 ? 0ll : d[n]*red[m]%mod*red[n-m]%mod;
}
void init()
{
	cin>>n>>k>>(ch+1);
	for(int i=1;i<=n;++i)
		d[i]=(d[i-1]*i)%mod;
	for(int i=2;i<=n;++i)
	{
		long long a=mod/i,b=mod%i;
		re[i]=((-a*re[b])%mod+mod)%mod;
		red[i]=(red[i-1]*re[i])%mod;
	}
	for(int i=1;i<=n;++i)
		bp[i]=(bp[i-1]*10)%mod;
}
void work()
{
	for(int i=1;i<=n;++i)
		s[i]=(s[i-1]+bp[i-1]*C(n-i-1,k-1))%mod;
	long long ans=0;
	for(int i=1;i<=n;++i)
		ans+=(s[n-i]+(bp[n-i]*C(i-1,k))%mod) * (ch[i]-'0')%mod;
	cout<<ans%mod<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}