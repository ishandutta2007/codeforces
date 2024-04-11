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
#define SIZE 105

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	int ret=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		ret=max(ret,A[i]);
	}
	while(1)
	{
		bool up=true;
		int S=0,T=0;
		for(int i=0;i<n;i++)
		{
			S+=A[i];
			T+=ret-A[i];
		}
		if(S<T) break;
		ret++;
	}
	printf("%d\n",ret);
	return 0;
}