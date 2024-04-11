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
const int N=100010,V=105,mod=1000000007;
struct matrix
{
	long long a[V][V];
}m1{{}},m2{{}},ans{{}};
int n,x,v{101},t[V]={};
matrix operator *(const matrix &m1,const matrix &m2)
{
	static matrix tmp{{}};
	for(int i=0;i<=v;++i)
		for(int j=0;j<=v;++j)
			tmp.a[i][j]=0;
	for(int i=0;i<=v;++i)
		for(int j=0;j<=v;++j)
			for(int k=0,x=m1.a[i][j]; k<=v; ++k)
				(tmp.a[i][k]+=x*m2.a[j][k])%=mod;
	return tmp;
}
void print_matrix(const matrix &m,int size)
{
	for(int i=0;i<=size;++i)
	{
		for(int j=0;j<=size;++j)
			cout<<m.a[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
}
int main()
{	
	cin>>n>>x;
	for(int i=1,d=0;i<=n;++i)
	{
		cin>>d;
		++t[d];
	}
	for(int i=0;i<=v;++i)
		ans.a[i][i]=1;
	m1=ans;
	for(int i=2;i<=v;++i)
		m1.a[i][1]=t[i-1];
	for(int i=1;i<=v;++i)
		m2.a[i-1][i]=1;
	m2.a[0][0]=1;
	//print_matrix(m1,5);
	//print_matrix(m2,5);
	m1=m2*m1;
	//print_matrix(m1,5);
	++x;
	while(x)
	{
		if(x&1)
			ans=m1*ans;
		m1=m1*m1;
		x>>=1;
	}
	//print_matrix(ans,5);
	cout<<ans.a[0][1]<<endl;
	return 0;
}