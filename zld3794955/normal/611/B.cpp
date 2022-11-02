#include<bits/stdc++.h>
using namespace std;
long long a,b;
int main()
{	
	cin>>a>>b;
	int tot=0;
	for(int i=1;i<=62;++i)
	{
		long long now=(1ll<<i)-1;
		for(int j=0;j<i-1;++j)
		{
			now^=(1ll<<j);
			tot+=(a<=now && now<=b);
			now^=(1ll<<j);
		}
	}
	cout<<tot<<endl;
	return 0;
}