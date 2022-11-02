#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
int main()
{
	cin>>n;
	if(n%3)
	{
		puts("0");
		return 0;
	}
	n/=3;
	for(long long i=1;i*i*i<=n;++i)
		if(n%i==0)
			for(long long n1=n/i,j=sqrt(n1);j>=i;--j)
				if(n1%j==0)
				{
					long long n2=n1/j;
					if(i+j<=n2)
						break;
					if((i+j+n2)%2==0)
					{
						if(i==j && j==n2) ans+=1;
						else if(i==j || j==n2 || n2==i) ans+=3;
						else ans+=6;
					}
				}
	cout<<ans<<endl;
	return 0;
}