#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
	long long ss=0;
	for(int i=c;i<=d;i++)
	{
		if(b+c<=i)break;
		if(a+b>i)ss=ss+1ll*(b-a+1)*(c-b+1);
		else if(a+c>i&&2*b>i)
		{
			ss=ss+1ll*(b-(i-b)+(b-a))*(i-b-a+1)/2;
			ss=ss+1ll*(b-a+1)*(c-(i-a));
		}
		else if(a+c>i&&2*b<=i)
		{
			ss=ss+1ll*(1+(b-a))*(i-a-(i-b))/2;
			ss=ss+1ll*(b-a+1)*(c-(i-a));
		}
		else if(a+c<=i&&2*b>i)ss=ss+1ll*(b-(i-b)+b-(i-c))*(c-b+1)/2;
		else ss=ss+1ll*(1+b-(i-c))*(c-(i-b))/2;
	}
	printf("%lld\n",ss);
	return 0;
}