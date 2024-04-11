#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
bool v;
int t,n,a[N];
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		v=false;
		for(int i=1;i<n;i++)
			if(abs(a[i]-a[i+1])>1)
			{
				cout<<"YES"<<'\n'<<i<<' '<<i+1<<'\n';
				v=true;
				break;
			}
		if(!v)
			cout<<"NO"<<'\n';
	}
	return 0;
}