#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> vec[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++)
	{
		int c;
		scanf("%d",&c);
		int now=-1,mx=-1;
		for(int j=0;j<c;j++)
		{
			int a;
			scanf("%d",&a);a--;
			vec[i].push_back(a);
		}
	}
	int mx=0;
	for(int i=0;i<k;i++)
	{
		if(vec[i][0]==0)
		{
			for(int j=0;j<vec[i].size();j++)
			{
				int t=vec[i][j];
				if(t==j) mx=j;
			}
		}
	}
	mx++;
	int ret=n-k;
	ret-=mx-1;
	printf("%d\n",ret+(n-mx));
	return 0;
}