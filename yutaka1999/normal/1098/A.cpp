#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> vec[SIZE];
int par[SIZE],dep[SIZE];
int sum[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	dep[0]=1;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&par[i]);par[i]--;
		vec[par[i]].push_back(i);
		dep[i]=dep[par[i]]+1;
	}
	for(int i=0;i<n;i++) scanf("%d",&sum[i]);
	for(int i=0;i<n;i++)
	{
		if(dep[i]%2==0)
		{
			int L=sum[par[i]];
			int R=1000000000;
			for(int j=0;j<vec[i].size();j++)
			{
				int to=vec[i][j];
				R=min(R,sum[to]);
			}
			if(L>R)
			{
				puts("-1");
				return 0;
			}
			if(vec[i].empty()) sum[i]=L;
			else sum[i]=R;
		}
	}
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		int a=sum[i];
		if(i>0) a-=sum[par[i]];
		ret+=a;
	}
	printf("%lld\n",ret);
	return 0;
}