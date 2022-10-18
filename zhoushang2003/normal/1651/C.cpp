#include<bits/stdc++.h>
using namespace std;
const int N=1e6,I=1e9;
int t,n,A,B,C,D,a[N],b[N];
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		A=B=C=D=I;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i],A=min(A,abs(b[i]-a[1])),B=min(B,abs(b[i]-a[n]));
		for(int i=1;i<=n;i++)
			C=min(C,abs(a[i]-b[1])),D=min(D,abs(a[i]-b[n]));
		cout<<min(min(abs(a[1]-b[n]),A+D)+min(abs(a[n]-b[1]),B+C),min(abs(a[1]-b[1]),A+C)+min(abs(a[n]-b[n]),B+D))<<'\n';
	}
}