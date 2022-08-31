#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100

using namespace std;
typedef pair <int,int> P;
typedef pair <int,P> PP;

vector <PP> vec;
int ans[105][105];
int sz;

int main()
{
	int k;
	scanf("%d",&k);
	for(sz=3;sz*(sz-1)*(sz-2)/6<=k;sz++);sz--;
	memset(ans,0,sizeof(ans));
	k-=sz*(sz-1)*(sz-2)/6;
	for(int x=0;x<sz;x++)
	{
		for(int y=0;y<sz;y++)
		{
			if(x==y) continue;
			ans[x][y]=1;
		}
	}
	for(;k>0&&sz<=SIZE;sz++)
	{
		int d;
		for(d=2;d*(d-1)/2<=k;d++);d--;
		for(int i=0;i<d;i++)
		{
			ans[i][sz]=1;
			ans[sz][i]=1;
		}
		k-=d*(d-1)/2;
	}printf("%d\n",SIZE);
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			printf("%d",ans[i][j]);
		}printf("\n");
	}return 0;
}