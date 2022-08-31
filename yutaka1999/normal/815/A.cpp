#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#define SIZE 105

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE][SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j+1<m;j++)
		{
			if(A[i][j+1]-A[i][j]!=A[0][j+1]-A[0][j])
			{
				puts("-1");
				return 0;
			}
		}
	}
	P ret=P(1000000000,-1);
	int mn=1000000;
	for(int i=0;i<m;i++) mn=min(mn,A[0][i]);
	for(int i=0;i<=mn;i++)
	{
		int cnt=i;
		bool up=true;
		for(int j=0;j<n;j++)
		{
			if(j==0)
			{
				for(int k=0;k<m;k++) cnt+=A[j][k]-i;
			}
			else
			{
				if(A[j][0]<A[0][0]-i) up=false;
				else cnt+=A[j][0]-(A[0][0]-i);
			}
		}
		if(up) ret=min(ret,P(cnt,i));
	}
	printf("%d\n",ret.first);
	for(int i=0;i<=mn;i++)
	{
		if(i!=ret.second) continue;
		for(int j=0;j<i;j++) printf("row %d\n",1);
		for(int j=0;j<n;j++)
		{
			if(j==0)
			{
				for(int k=0;k<m;k++)
				{
					for(int t=0;t<A[0][k]-i;t++) printf("col %d\n",k+1);
				}
			}
			else
			{
				for(int k=0;k<A[j][0]-(A[0][0]-i);k++) printf("row %d\n",j+1);
			}
		}
	}
	return 0;
}