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
#define SIZE 105

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int cnt[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int r;
		scanf("%d",&r);
		for(int j=0;j<r;j++)
		{
			int c;
			scanf("%d",&c);c--;
			cnt[c]++;
		}
	}
	for(int i=0;i<SIZE;i++)
	{
		if(cnt[i]==n)
		{
			printf("%d ",i+1);
		}
	}puts("");
	return 0;
}