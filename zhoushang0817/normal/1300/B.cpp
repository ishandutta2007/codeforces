#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int t,n,a[N];
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=2*n;i++)
			cin>>a[i];
		sort(a+1,a+2*n+1);
		cout<<abs(a[n+1]-a[n])<<'\n';
	}
	return 0;
}