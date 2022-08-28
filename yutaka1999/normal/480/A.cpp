#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#define SIZE 5005

using namespace std;
typedef pair <int,int> P;

P pos[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		pos[i]=P(a,b);
	}
	sort(pos,pos+n);
	int last=pos[n-1].second;
	for(int i=n-2;i>=0;i--)
	{
		if(last>=pos[i].first)
		{
			last=pos[i].first;
		}
		else
		{
			if(last<pos[i].second)
			{
				printf("%d\n",pos[n-1].first);
				return 0;
			}
			last=pos[i].second;
		}
	}
	printf("%d\n",pos[n-1].second);
	return 0;
}