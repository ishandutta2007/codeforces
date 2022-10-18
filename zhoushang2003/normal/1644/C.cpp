#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int t,n,x,a[N],s[N],A[N],l;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>x)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i],s[i]=s[i-1]+a[i];
		memset(A,0,sizeof(A)); 
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				l=j-i+1,A[l]=max(A[l],s[j]-s[i-1]+l*x);
		for(int i=n-1;~i;i--)
			A[i]=max(A[i],A[i+1]-x);
		for(int i=1;i<=n;i++)
			A[i]=max(A[i],A[i-1]);
		for(int i=0;i<=n;i++)
			cout<<A[i]<<' ';
		puts("");
	}
}