#include<bits/stdc++.h>
using namespace std;
const int N=4e5+1;
int n,m,a[N],p[N],r,A;
int main()
{
	cin>>n>>m;
	m=m*8/n;
	m=(1<<min(30,m));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	p[1]=1;
	for(int i=2;i<=n;i++)
		if(a[i]==a[i-1])
			p[i]=p[i-1];
		else
			p[i]=p[i-1]+1;
	for(int i=1;i<=n;i++)
	{
		while(r<n&&p[r+1]<=p[i]+m-1)
			r++;
		A=max(A,r-i+1);
	}
	cout<<n-A;
	return 0;
}