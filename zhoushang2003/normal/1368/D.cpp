#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,a[N],c[N],t,A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<20;j++)
			if((a[i]>>j)&1)
				c[j]++;
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int j=0;j<20;j++)
			if(c[j]>=i)
				t|=(1<<j);
		A+=t*t;
	}
	cout<<A;
	return 0;
}