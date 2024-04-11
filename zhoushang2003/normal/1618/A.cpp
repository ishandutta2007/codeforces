#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=9;
int t,a[N];
signed main()
{
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=7;i++)
			cin>>a[i];
		cout<<a[1]<<' '<<a[2]<<' '<<a[7]-a[1]-a[2]<<'\n';
	}
	return 0;
}