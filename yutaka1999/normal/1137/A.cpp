#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#define SIZE 1005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE][SIZE];
int low[SIZE][SIZE],up[SIZE][SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&A[i][j]);
			low[i][j]=up[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		vector <int> vx;
		for(int j=0;j<m;j++) vx.push_back(A[i][j]);
		sort(vx.begin(),vx.end());
		vx.erase(unique(vx.begin(),vx.end()),vx.end());
		for(int j=0;j<m;j++)
		{
			int p=lower_bound(vx.begin(),vx.end(),A[i][j])-vx.begin();
			low[i][j]=max(low[i][j],p);
			up[i][j]=max(up[i][j],(int) vx.size()-p-1);
		}
	}
	for(int j=0;j<m;j++)
	{
		vector <int> vx;
		for(int i=0;i<n;i++) vx.push_back(A[i][j]);
		sort(vx.begin(),vx.end());
		vx.erase(unique(vx.begin(),vx.end()),vx.end());
		for(int i=0;i<n;i++)
		{
			int p=lower_bound(vx.begin(),vx.end(),A[i][j])-vx.begin();
			low[i][j]=max(low[i][j],p);
			up[i][j]=max(up[i][j],(int) vx.size()-p-1);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) printf("%d ",low[i][j]+up[i][j]+1);
		puts("");
	}
	return 0;
}