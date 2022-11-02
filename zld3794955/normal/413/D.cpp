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
const int N=2010,S=1025,mod=1000000007;
int n,k,a[N]={},s,f[N][S]={};
void init()
{
	scanf("%d%d",&n,&k);
	s=1<<(k-1);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		a[i]>>=1;
	}
}
void work()
{
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<s;++j)
		{
			if(a[i]!=1)
			{
				if(j&1)
					(f[i][2]+=f[i-1][j])%=mod;
				else
					(f[i][j+2]+=f[i-1][j])%=mod;
			}
			if(a[i]!=2)
				(f[i][j+1]+=f[i-1][j])%=mod;
		}
	/*
	cout<<"s="<<s<<endl;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=s;++j)
			cout<<f[i][j]<<' ';
		cout<<endl;
	}
	*/
	long long ans=0,now=1;
	for(int i=n;i>=1;--i)
	{
		(ans+=f[i][s]*now)%=mod;
		if(a[i]==0)
			(now*=2)%=mod;
	}
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}