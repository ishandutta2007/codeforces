#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a,b,ans=1,i;

int main()
{
	cin>>a>>b;
	for(i=a+1;i<=b;i++)
	{
//		cout<<i<<" ";
//		cout<<ans<<" ";
		ans*=(i%10);
//		cout<<ans<<endl;
		ans%=10;
		if(ans==0)
		{
			cout<<0;
			return 0;
		}
	}
	cout<<ans;
}