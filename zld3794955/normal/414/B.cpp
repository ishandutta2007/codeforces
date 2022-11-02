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
const int N=2020,mod=1000000007;
int n,k,d[N][100]={},tot[N]={},f[N][N]={};
void init()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			if(i%j==0)
				d[i][++tot[i]]=j;
	for(int i=1;i<=n;++i)
		f[1][i]=1;
}
void dp()
{
	for(int i=2;i<=k;++i)
		for(int j=1;j<=n;++j)
			for(int l=1;l<=tot[j];++l)
			{
				f[i][j]+=f[i-1][d[j][l]];
				if(f[i][j]>=mod)
					f[i][j]-=mod;
			}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		ans+=f[k][i];
		if(ans>=mod)
			ans-=mod;
	}
	printf("%d\n",ans);
}
int main()
{	
	init();
	dp();
	return 0;
}