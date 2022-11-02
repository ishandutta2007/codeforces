#include<iostream>
#include<cstdio>
using namespace std;
const int N=100010;
long long n,r[N]={0,1};
int main()
{	
	cin>>n;
	if(n==1)
	{
		puts("YES\n1");
		return 0;
	}
	if(n==4)
	{
		puts("YES\n1\n3\n2\n4");
		return 0;
	}
	for(int i=2;i<n;++i)
	{
		if(n%i==0)
		{
			puts("NO");
			return 0;
		}
		r[i]=((-(n/i)*r[n%i])%n+n)%n;
	}
	puts("YES");
	cout<<1<<endl;
	for(int i=2;i<n;++i)
		cout<<i*r[i-1]%n<<endl;
	cout<<n<<endl;
	return 0;
}