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
const int N=110;
double f[N][N][N]={};
int r,s,t;
int main()
{	
	cin>>r>>s>>t;
	f[r][s][t]=1;
	for(int i=r;i>=0;--i)
		for(int j=s;j>=0;--j)
			for(int k=t;k>=0;--k)
			{
				double p1=i*j,p2=j*k,p3=k*i;
				if(j && k)
					f[i][j][k-1]+=f[i][j][k]*p2/(p1+p2+p3);
				if(i && j)
					f[i][j-1][k]+=f[i][j][k]*p1/(p1+p2+p3);
				if(k && i)
					f[i-1][j][k]+=f[i][j][k]*p3/(p1+p2+p3);
			}
	double s1=0,s2=0,s3=0;
	for(int i=1;i<=r;++i)
		s1+=f[i][0][0];
	for(int j=1;j<=s;++j)
		s2+=f[0][j][0];
	for(int k=1;k<=t;++k)
		s3+=f[0][0][k];
	printf("%.12f %.12f %.12f\n",s1,s2,s3);
	return 0;
}