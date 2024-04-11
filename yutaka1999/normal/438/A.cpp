#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 1005

using namespace std;
typedef pair <int,int> P;

bool up[SIZE][SIZE];
int val[SIZE];
P in[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
		in[i]=P(val[i],i);
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		up[a][b]=up[b][a]=true;
	}
	sort(in,in+n);
	int ret=0;
	for(int i=n-1;i>=0;i--)
	{
		int v=in[i].second;
		for(int j=0;j<n;j++)
		{
			if(up[v][j])
			{
				ret+=val[j];
				up[v][j]=up[j][v]=false;
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}