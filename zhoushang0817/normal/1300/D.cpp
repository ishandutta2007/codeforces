#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,a[N],b[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	if(n&1)
	{
		cout<<"NO";
		return 0;
	}
	for(int i=1;i<=n/2;i++)
		if(a[i]+a[n/2+i]!=a[1]+a[n/2+1]||b[i]+b[n/2+i]!=b[1]+b[n/2+1])
		{
			cout<<"NO";
			return 0;
		}
	cout<<"YES";
	return 0;
}