#include<bits/stdc++.h>
using namespace std;
const int S=2;
struct matrix
{
	long long a[S][S];
}f,g;
long long n,k,l,mod;
inline long long power(long long x,long long y)
{
	long long t=1;
	for(; y; x=x*x%mod,y>>=1)
		if(y&1) t=t*x%mod;
	return t;
}
matrix operator *(const matrix &m1,const matrix &m2)
{
	matrix tmp={{}};
	for(int i=0;i<S;++i)
		for(int j=0;j<S;++j)
			for(int k=0;k<S;++k)
				(tmp.a[i][k]+=m1.a[i][j]*m2.a[j][k])%=mod;
	return tmp;
}
inline matrix power(matrix x,long long y)
{
	matrix t={{{1,0},{0,1}}};
	for(; y; x=x*x,y>>=1)
		if(y&1) t=t*x;
	return t;
}
int main()
{	
	cin>>n>>k>>l>>mod;
	if(mod==1 || (l<64 && (k>>l)))
	{
		puts("0");
		return 0;
	}
	f.a[0][0]=f.a[0][1]=f.a[1][0]=1;
	g=power(f,n);
	long long t1=power(2,n),t2=(g.a[0][0]+g.a[0][1])%mod,ans=1;
	t1=(t1+mod-t2)%mod;
	for(int i=0;i<l;++i)
	{
		if(i>=61 || (k&(1ll<<i))==0)
			ans=ans*t2%mod;
		else
			ans=ans*t1%mod;
	}
	cout<<ans<<endl;
	return 0;
}