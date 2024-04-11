#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,a[N],t,x;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		t=a[i]+x,x=max(t,x);
		cout<<t<<' ';
	}
	return 0;
}