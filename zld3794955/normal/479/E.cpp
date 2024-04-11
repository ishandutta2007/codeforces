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
const int mod=1000000007,N=5050,K=5050;
int n,a,b,k,up=0;
int f[N][K]={},s[N][K]={};
int main()
{	
	cin>>n>>a>>b>>k;
	if(a>b)
		up=n-b,a-=b;
	else
		up=b-1,a=b-a;
	f[0][a]=1;
	//cout<<"a="<<a<<endl;
	for(int i=1;i<=a;++i)
		s[0][a]=1;
	for(int i=0;i<k;++i)
	{
		long long d[N]={};
		for(int j=1;j<=up;++j)
		{
			d[1]+=f[i][j];
			d[j]-=f[i][j];
			d[j+1]+=f[i][j];
			d[min(up,j+j-1)+1]-=f[i][j];
		}
		long long tmp=0;
		for(int j=1;j<=up;++j)
		{
			tmp+=d[j];
			f[i+1][j]=tmp%mod;
		}
	}/*
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=up;++j)
			cout<<f[i][j]<<' ';
		cout<<endl;
	}*/	
	int ans=0;
	for(int i=1;i<=up;++i)
		(ans+=f[k][i])%=mod;
	cout<<ans<<endl;
	return 0;
}