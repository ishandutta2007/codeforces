#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long t,n,a[N],x,y;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		x=-1e9,y=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],x=max(x,a[i]),y=max(y,x-a[i]);
		for(long long i=0;;i++)
			if((1<<i)-1>=y)
			{
				cout<<i<<'\n';
				break;
			}
	}
}