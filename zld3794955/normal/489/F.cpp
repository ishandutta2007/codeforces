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
const int N=505;
int n,m,mod,c1,c2;
long long f[N][N]={};
bool b[N][N]={};
void init()
{
	scanf("%d%d%d\n",&n,&m,&mod);
	int t[N]={};
	for(int i=1;i<=m;++i)
	{
		char ch[N]={};
		scanf("%s\n",ch+1);
		for(int j=1;j<=n;++j)
			t[j]+=ch[j]=='1';
	}
	for(int i=1;i<=n;++i)
	{
		if(t[i]==0)
			++c1;
		if(t[i]==1)
			++c2;
	}
	f[0][0]=1;
	b[0][0]=true;
}
long long work(int x,int y)
{
	if(x<0 || y<0)
		return 0ll;
	if(b[x][y])
		return f[x][y];
	b[x][y]=true;
	f[x][y]+=work(x-1,y)*x%mod*y;
	f[x][y]+=work(x-2,y+2)*(x*(x-1)/2%mod);
	f[x][y]+=work(x,y-2)*(y*(y-1)/2%mod);
	return f[x][y]%=mod;
}
int main()
{	
	init();
	cout<<work(c1,c2)<<endl;
	return 0;
}