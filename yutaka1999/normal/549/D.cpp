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

int imos[SIZE][SIZE];
char mp[SIZE][SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",&mp[i]);
	int cnt=0;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			if(i+1<n) imos[i][j]+=imos[i+1][j];
			if(j+1<m) imos[i][j]+=imos[i][j+1];
			if(i+1<n&&j+1<m) imos[i][j]-=imos[i+1][j+1];
			int vl=mp[i][j]=='W'?1:-1;
			if(vl!=imos[i][j])
			{
				cnt++;
				imos[i][j]=vl;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}