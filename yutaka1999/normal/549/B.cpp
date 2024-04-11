#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <queue>
#define SIZE 105

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char mp[SIZE][SIZE];
int A[SIZE],deg[SIZE];
bool use[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&mp[i]);
		for(int j=0;j<n;j++)
		{
			if(mp[i][j]=='1')
			{
				deg[j]++;
			}
		}
	}
	bool ok=true;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		if(A[i]==deg[i])
		{
			ok=false;
		}
	}
	if(ok)
	{
		printf("%d\n",n);
		for(int i=0;i<n;i++)
		{
			if(i!=0) printf(" ");
			printf("%d",i+1);
		}puts("");
		return 0;
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int c=-1;
		for(int j=0;j<n;j++)
		{
			if(!use[j]&&A[j]==0)
			{
				c=j;
				break;
			}
		}
		if(c==-1) break;
		use[c]=true;
		cnt++;
		for(int j=0;j<n;j++)
		{
			if(mp[c][j]=='1')
			{
				A[j]--;
			}
		}
	}
	bool f=true;
	printf("%d\n",cnt);
	for(int i=0;i<n;i++)
	{
		if(use[i])
		{
			if(!f) printf(" ");
			printf("%d",i+1);
			f=false;
		}
	}
	puts("");
	return 0;
}