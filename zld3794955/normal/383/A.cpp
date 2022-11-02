#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,k,tot=0;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&k);
		tot+=k;
		if(k==0)
			ans+=tot;
	}
	cout<<ans<<endl;
}