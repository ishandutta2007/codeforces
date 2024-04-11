#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main()
{
	cin>>n>>k;
	if((--n)==0)
	{
		puts("0");
		return 0;
	}
	if(k*(k-1)/2<n)
	{
		puts("-1");
		return 0;
	}
	long long l=1,r=k;
	while(l!=r)
	{
		long long mid=(l+r)>>1;
		if((k-1+k-mid)*mid/2>=n)
			r=mid;
		else
			l=mid+1;
	}
	cout<<l<<endl;
}