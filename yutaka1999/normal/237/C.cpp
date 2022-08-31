#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 1000003

using namespace std;

bool prime[1000005];
int a,b,k;

void make()
{
	for(int i=0;i<=SIZE;i++) prime[i]=true;
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i<=SIZE;i++)
	{
		if(prime[i])
		{
			for(int j=i*2;j<=SIZE;j+=i)
			{
				prime[j]=false;
			}
		}
	}
}
bool ok(int x)
{
	if(a+x-1>b) return true;
	int sum=0;
	for(int i=a;i<a+x;i++) if(prime[i]) sum++;
	if(sum<k) return false;
	for(int i=a+x;i<=b;i++)
	{
		if(prime[i]) sum++;
		if(prime[i-x]) sum--;
		if(sum<k) return false;
	}return true;
}
int main()
{
	make();
	scanf("%d %d %d",&a,&b,&k);
	int s=0,e=SIZE;
	while(e-s>1)
	{
		int med=(s+e)/2;
		if(ok(med)) e=med;
		else s=med;
	}
	if(a+e-1>b) printf("%d\n",-1);
	else printf("%d\n",e);
	return 0;
}