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
const int N=100100,M=100100;
int n,m;
double ans=0,p[M]={},S=0;
int main()
{	
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
	{
		p[i]=pow(i*1.0/m,n)-S;
		S+=p[i];
	}
	//for(int i=1;i<=m;++i)
	//	cout<<p[i]<<' ';
	//cout<<endl;
	for(int i=1;i<=m;++i)
		ans+=p[i]*i;
	printf("%.12f\n",ans);
	return 0;
}