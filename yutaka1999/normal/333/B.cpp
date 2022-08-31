#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 1005

using namespace std;

bool w[SIZE];
bool h[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) w[i]=h[i]=true;
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);x--;y--;
		w[x]=false;
		h[y]=false;
	}
	int ret=0;
	for(int i=1;i<n-1;i++)
	{
		int s=i,e=n-i-1;
		if(s==e)
		{
			if(w[s]||h[s]) ret++;
		}
		else
		{
			int cnt=w[s]+w[e]+h[s]+h[e];
			ret+=cnt;
		}
		w[s]=w[e]=h[s]=h[e]=false;
	}
	printf("%d\n",ret);
	return 0;
}