#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1,D=1e9+7;
int t,a[N],b[N],n,l,r,A,x,y;
int P(int a,int b)
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
int C(int x,int y)
{
	if(x<0||y<0||x<y)
		return 0;
	return a[x]*b[y]%D*b[x-y]%D;
}
signed main()
{
	a[0]=1;
	for(int i=1;i<N;i++)
		a[i]=a[i-1]*i%D;
	b[N-1]=P(a[N-1],D-2);
	for(int i=N-1;i>0;i--)
		b[i-1]=b[i]*i%D;
	cin>>t;
	while(t--&&cin>>n>>l>>r)
	{
		A=min(1-l,r-n)*C(n,n/2);
		if(n&1)
			A*=2;
		for(int i=min(1-l,r-n)+1;i<=min(1-l,r-n)+n;i++)
		{
			x=n-min(n,r-i),y=max(0ll,l+i-1),A+=C(n-x-y,n/2-x);
			if(n&1)
				A+=C(n-x-y,n/2+1-x);
		}
		cout<<A%D<<'\n';
	}
	return 0;
}