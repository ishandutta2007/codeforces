#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5,D=1e9+7;
int n,a[N],s,f[N],A,x;
int P(int a,int b)
{
	x=1;
	for(;b;b/=2,a=a*a%D)
		if(b&1)
			x=x*a%D;
	return x;
}
main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=a[i];
	f[1]=(s-1)*(s-1)%D*P(s,D-2)%D;
	for(int i=1;i<N-1;i++)
		f[i+1]=(2*f[i]-f[i-1]-(s-1)*P(s-i,D-2))%D;
	for(int i=1;i<=n;i++)
		(A+=f[a[i]])%=D;
	cout<<(A+D)%D;
}