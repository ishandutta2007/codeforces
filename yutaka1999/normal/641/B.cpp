#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 105

using namespace std;

int id[SIZE][SIZE];
int ans[SIZE][SIZE];

int main()
{
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			id[i][j]=i*m+j;
		}
	}
	for(int i=0;i<q;i++)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			int r;
			scanf("%d",&r);r--;
			int last=id[r][0];
			for(int j=0;j+1<m;j++) id[r][j]=id[r][j+1];
			id[r][m-1]=last;
		}
		else if(tp==2)
		{
			int c;
			scanf("%d",&c);c--;
			int last=id[0][c];
			for(int j=0;j+1<n;j++) id[j][c]=id[j+1][c];
			id[n-1][c]=last;
		}
		else
		{
			int r,c,x;
			scanf("%d %d %d",&r,&c,&x);r--;c--;
			int a=id[r][c]/m,b=id[r][c]%m;
			ans[a][b]=x;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(j!=0) printf(" ");
			printf("%d",ans[i][j]);
		}puts("");
	}
	return 0;
}