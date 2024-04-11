#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cassert>
#define SIZE 100005
#define MX 12

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[MX][SIZE];
int pos[MX][SIZE];
int n,m;

bool check(int a,int b)
{
	for(int i=0;i<m;i++)
	{
		if(pos[i][a]+1!=pos[i][b])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
			A[i][j]--;
			pos[i][A[i][j]]=j;
		}
	}
	ll ret=0;
	for(int i=0;i<n;)
	{
		int b=i;
		for(;i+1<n&&check(A[0][i],A[0][i+1]);i++);
		ll L=i-b+1;
		ret+=L*(L+1)/2;
		i++;
	}
	printf("%lld\n",ret);
	return 0;
}