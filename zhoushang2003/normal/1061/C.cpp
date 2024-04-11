#include<iostream>
#include<cmath>
using namespace std;
const int N=1e5,M=1e6+1,D=1e9+7;
int n,a[N],x,f[M],A;
int main()
{
	cin>>n;
	f[0]=1;
	while(n--&&cin>>x)
	{
		for(int i=1;i*i<=x;i++)
			if(x%i==0)
				(f[x/i]+=f[x/i-1])%=D;
		for(int i=sqrt(x);i>=1;i--)
			if(x%i==0&&i*i!=x)
				(f[i]+=f[i-1])%=D;
	}
	for(int i=1;i<M;i++)
		(A+=f[i])%=D;
	cout<<A;
	return 0;
}