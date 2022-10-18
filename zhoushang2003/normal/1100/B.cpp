#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,m,x,c[N],a[N],M; 
int main()
{
	cin>>n>>m;
	c[0]=n;
	while(m--&&cin>>x)
	{
		c[a[x]++]--,c[a[x]]++;
		if(!c[M])
			cout<<1,M++;
		else
			cout<<0;
	}
	return 0;
}