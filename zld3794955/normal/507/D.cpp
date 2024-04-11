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
const int N=1010,K=110;
int n,k,m;
long long p[N]={1},p2[N]={1},f[2][10][K]={},ans=0;
int main()
{	
	cin>>n>>k>>m;
	for(int i=1;i<=n;++i)
		p[i]=(p[i-1]*10)%m;
	if(k==1)
	{
		cout<<p[n-1]*9%m<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i)
		p2[i]=(p2[i-1]*10-1)%k+1;
	int pre=1,now=0;
	for(int i=0;i<=9;++i)
		f[now][i][(i-1)%k+1]=1;
	for(int i=1;i<n;++i)
	{
		swap(pre,now);
		for(int d=0;d<=9;++d)
		{
			ans+=f[pre][d][k]*(p[n-i-1]*9%m)%m;
			f[pre][d][k]=0;
		}
		for(int d=0;d<=9;++d)
			for(int j=0;j<=k;++j)
				f[now][d][j]=0;
		for(int d=0;d<=9;++d)
			for(int j=0;j<=k;++j)
				for(int l=0;l<=9;++l)
					(f[now][l][(j+l*p2[i]-1)%k+1]+=f[pre][d][j])%=m;
	}
	for(int d=0;d<=9;++d)
	{
		ans+=f[now][d][k];
		f[now][d][k]=0;
	}
	cout<<ans%m<<endl;
	return 0;
}