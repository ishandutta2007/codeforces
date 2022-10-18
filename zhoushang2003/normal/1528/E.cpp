#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6,D=998244353,U=499122177,V=166374059;
int n,f[N],g[N],A;
main()
{
	cin>>n,f[0]=g[0]=1;
	for(int i=1;i<=n;i++)
		f[i]=(f[i-1]+f[i-1]*g[i-2]+f[i-1]*(f[i-1]+1)%D*U)%D,g[i]=(g[i-1]+f[i])%D;
	A=2*(f[n]+f[n-1]*g[n-2]%D*(g[n-2]+1)%D*U+f[n-1]*(f[n-1]+1)%D*g[n-2]%D*U+f[n-1]*(f[n-1]+1)%D*(f[n-1]+2)%D*V)%D-1;
	for(int i=0;i<n-1;i++)
		(A+=(f[i]-1)*(f[n-i-1]-f[n-i-2]))%=D;
	cout<<(A+D)%D;
}