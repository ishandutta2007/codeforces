#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <set>
#include <functional>
#include <queue>
#include <map>
#define SIZE 105

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char str[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",&str);
	for(int i=0;i<n;i++)
	{
		if(str[i]=='.') continue;
		for(int j=i+1;j<n;j++)
		{
			int d=j-i;
			int now=i;
			bool up=true;
			for(int k=0;k<4;k++)
			{
				now+=d;
				if(now>=n)
				{
					up=false;
					break;
				}
				if(str[now]=='.')
				{
					up=false;
					break;
				}
			}
			if(up)
			{
				puts("yes");
				return 0;
			}
		}
	}
	puts("no");
	return 0;
}