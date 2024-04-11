#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	ll sum=0;
	/*
		sum = sum{ aj * (j - 1) }
		d = sum - ( i - 1 ) * ( n - i ) * ai
	*/
	int pos=0;
	int all=n;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		pos++;
		if(sum-(ll) (pos-1)*(all-pos)*a<k)
		{
			printf("%d\n",i+1);
			pos--;
			all--;
		}
		else sum+=(ll) a*(pos-1);
	}
	return 0;
}