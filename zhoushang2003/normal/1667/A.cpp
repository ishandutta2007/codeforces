#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int n,a[N],f[N],c,x,A=1e18;
main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		f[i]=c=0;
		for(int j=i-1;j;j--)
			x=f[j+1]/a[j]+1,f[j]=x*a[j],c+=x;
		for(int j=i+1;j<=n;j++)
			x=f[j-1]/a[j]+1,f[j]=x*a[j],c+=x;
		A=min(A,c);
	}
	cout<<A;
}