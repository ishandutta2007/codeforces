#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
long long n,m,x[N],g,p;
long long G(long long x,long long y)
{
	if(x%y==0)
		return y;
	return G(y,x%y);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	g=x[2]-x[1];
	for(int i=2;i<n;i++)
		g=G(g,x[i+1]-x[i]);
	for(int i=1;i<=m;i++)
	{
		cin>>p;
		if(g%p==0)
		{
			cout<<"YES"<<endl<<x[1]<<" "<<i;
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}