#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,a[N],v,c[N];
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		c[1]=v=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],c[a[i]]++;
		for(int i=1;i<=n;i++)
			if(a[i%n+1]-a[i]>1)
				v=1;
		puts(c[1]!=1||v?"NO":"YES");
	}
}