#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#define SIZE 55

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int dist[SIZE][SIZE];
int mx[SIZE],id[SIZE];
int n;

void construct()
{
	for(int i=0;i<n;i++)
	{
		mx[i]=0;
		for(int j=0;j<n;j++)
		{
			mx[i]=max(mx[i],dist[i][j]);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&dist[i][j]);
		}
	}
	memset(id,-1,sizeof(id));
	for(int i=1;i<=n-1;i++)
	{
		construct();
		int pos=-1;
		for(int j=0;j<n;j++)
		{
			if(mx[j]==i)
			{
				pos=j;
				break;
			}
		}
		id[pos]=i;
		for(int j=0;j<n;j++) dist[pos][j]=dist[j][pos]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(id[i]==-1) id[i]=n;
		if(i!=0) printf(" ");
		printf("%d",id[i]);
	}puts("");
	return 0;
}