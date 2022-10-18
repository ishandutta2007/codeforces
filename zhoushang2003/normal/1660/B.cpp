#include<bits/stdc++.h>
using namespace std;
int t,n,a[999999];
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1),puts(a[n]-a[n-1]>1?"NO":"YES");
	}
}