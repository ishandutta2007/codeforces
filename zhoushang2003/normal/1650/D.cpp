#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int t,n,x,p[N],A[N];
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>x,p[x]=i;
		for(int i=n;i;i--)
		{
			A[i]=p[i]%i;
			for(int j=1;j<i;j++)
				(p[j]-=A[i]-i)%=i;
		}
		for(int i=1;i<=n;i++)
			cout<<A[i]<<' ';
		cout<<'\n';
	}
}