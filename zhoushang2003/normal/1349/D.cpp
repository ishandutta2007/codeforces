#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+1,D=998244353;
int t,n,m,a[N],f[N],A;
int Q(int a,int b)
{
	t=1;
	while(b)
	{
		if(b&1)
			(t*=a)%=D;
		(a*=a)%=D,b/=2;
	}
	return t;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],m+=a[i];
	f[0]=n-1;
	for(int i=1;i<m;i++)
		f[i]=(n-1)*(m+i*f[i-1]%D)%D*Q(m-i,D-2)%D;
	for(int i=m-1;i>=0;i--)
		(f[i]+=f[i+1])%=D;
	for(int i=1;i<=n;i++)
		(A+=f[a[i]])%=D;
	cout<<(A+(D-f[0])*(n-1))%D*Q(n,D-2)%D;
	return 0;
}