#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#define SIZE 100005

using namespace std;

int in[SIZE];

int fx(int x)
{
	if(x%2) return x*(x-1)/2;
	return x*(x-1)/2+(x-2)/2;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int dm;
		scanf("%d %d",&dm,&in[i]);
	}sort(in,in+m,greater <int>());
	int ret=0;
	for(int i=0;i<min(n,m)&&fx(i+1)<n;i++) ret+=in[i];
	printf("%d\n",ret);
	return 0;
}