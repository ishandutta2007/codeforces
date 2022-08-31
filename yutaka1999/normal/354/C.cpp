#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1000005

using namespace std;

int imos[SIZE];
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int mn=SIZE-1;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		imos[max(1,a-k)]++;
		imos[a+1]--;
		mn=min(mn,a);
	}
	for(int i=1;i<SIZE;i++) imos[i]+=imos[i-1];
	for(int i=mn;i>0;i--)
	{
		int num=0;
		for(int j=i;j<SIZE;j+=i) num+=imos[j];
		if(num>=n)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}