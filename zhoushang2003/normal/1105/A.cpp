#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,a[N],c,I,A=1e9;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int t=1;t<101;t++)
	{
		c=0;
		for(int i=0;i<n;i++)
			if(abs(a[i]-t)>1)
				c+=abs(a[i]-t)-1;
		if(c<A)
			I=t,A=c;
	}
	cout<<I<<" "<<A;
	return 0;
}