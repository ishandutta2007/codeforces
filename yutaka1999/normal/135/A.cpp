#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005

using namespace std;

int in[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	sort(in,in+n);
	if(in[n-1]!=1) in[n-1]=1;
	else in[n-1]=2;
	sort(in,in+n);
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",in[i]);
	}
	puts("");
	return 0;
}