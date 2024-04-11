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
const int N=110,M=110;
int n,m,a[N][M]={},b[N][M]={};
int main()
{	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		fill(a[i]+1,a[i]+m+1,1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>b[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(b[i][j]==0)
			{
				for(int k=1;k<=n;++k)
					a[k][j]=0;
				for(int k=1;k<=m;++k)
					a[i][k]=0;
			}
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			int flag=0;
			for(int k=1;k<=n;++k)
				flag|=a[k][j];
			for(int k=1;k<=m;++k)
				flag|=a[i][k];
			if(flag!=b[i][j])
			{
				puts("NO");
				return 0;
			}
		}
	puts("YES");
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}