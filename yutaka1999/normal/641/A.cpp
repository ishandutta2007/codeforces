#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;

char str[SIZE];
int dist[SIZE];
bool use[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",&str);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&dist[i]);
		if(str[i]=='<') dist[i]*=-1;
	}
	int now=0;
	while(1)
	{
		use[now]=true;
		now+=dist[now];
		if(now<0||now>=n) break;
		if(use[now])
		{
			puts("INFINITE");
			return 0;
		}
	}
	puts("FINITE");
	return 0;
}