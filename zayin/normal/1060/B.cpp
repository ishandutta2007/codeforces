#include<bits/stdc++.h>
#define maxn 100
using namespace std;
typedef long long LL;

LL n,ans;
int main()
{
	cin>>n;
	while (n>9)
	{
		if (n%10==9)
			ans+=9,n/=10;
		else
			ans+=10+n%10,n=n/10-1;
	}
	cout<<ans+n<<endl;
	return 0;
}