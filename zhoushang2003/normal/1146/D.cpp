#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
bool v[N];
long long m,a,b,x,y,f[N],A;
int main()
{
	cin>>m>>a>>b;
	for(int i=1;i<a;i++)
		f[i]=1e18;
	v[0]=true;
	while(!v[(x+a*N-b)%a])
	{
		if(x>=b)
			f[x-b]=f[x];
		else
			f[(x+a*N-b)%a]=max(f[x],(x+a*N-b)%a+b);
		x=(x+a*N-b)%a,v[x]=true;
	}
	for(int i=0;i<a;i++)
		if(i<=m)
			x=min(m+1,f[i])-i,y=x/a,A+=y*(y+1)/2*a+(x-y*a)*(y+1);
	cout<<(m+1)*(m+2)/2-A;
	return 0;
}