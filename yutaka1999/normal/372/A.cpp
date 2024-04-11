#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 500005

using namespace std;

int in[SIZE];
int n;

bool ok(int x)
{
	for(int i=0;i<x;i++)
	{
		int tg=(n-x)+i;
		if(in[i]*2>in[tg]) return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	sort(in,in+n);
	int s=0,e=n/2+1;
	while(e-s>1)
	{
		int med=(s+e)/2;
		if(ok(med)) s=med;
		else e=med;
	}
	printf("%d\n",n-s);
}