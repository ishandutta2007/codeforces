#include<bits/stdc++.h>
using namespace std;
const int T=100;
long long n,ans[T]={},tot=0;
int main()
{	
	cin>>n;
	for(int s=0;s<=60;++s)
	{
		long long v=(1ll<<s)-1;
		long long l=0,r=(long long)sqrt(n);
		while(l!=r)
		{
			long long mid=(l+r+1)>>1;
			if((double)(mid+mid+1.0)*(v+mid)>n)
				r=mid-1;
			else
				l=mid;
		}
		if((l+l+1)*(v+l)==n)
			ans[++tot]=(l+l+1)<<s;
	}
	sort(ans+1,ans+tot+1);
	if(tot==0)
		puts("-1");
	else
		for(int i=1;i<=tot;++i)
			printf("%I64d\n",ans[i]);
	return 0;
}