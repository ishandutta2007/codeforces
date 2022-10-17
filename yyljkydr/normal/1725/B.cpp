#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	long long k;
	cin>>n>>k;
	vector<long long> a(n+5);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.begin()+n+1);
	int pos=0,ans=0;
	for(int i=n;i>=1;i--)
	{
		long long t=k/a[i];
		pos+=t;
//		cerr<<i<<' '<<pos<<endl;
		if(pos<i)ans++;
		else break;
	}
	cout<<ans<<endl;
	return 0;
}