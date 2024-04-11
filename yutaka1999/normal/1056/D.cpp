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
#include <cassert>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int par[SIZE];
int nd[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&par[i]);
		par[i]--;
	}
	for(int i=n-1;i>=0;i--)
	{
		if(nd[i]==0) nd[i]=1;
		if(i>0) nd[par[i]]+=nd[i];
	}
	sort(nd,nd+n);
	for(int i=0;i<n;i++) printf("%d ",nd[i]);
	puts("");
	return 0;
}