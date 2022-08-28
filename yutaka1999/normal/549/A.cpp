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
#define SIZE 55

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char mp[SIZE][SIZE];
char now[10];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",&mp[i]);
	int cnt=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<m-1;j++)
		{
			int sz=0;
			for(int p=0;p<2;p++)
			{
				for(int q=0;q<2;q++)
				{
					now[sz++]=mp[i+p][j+q];
				}
			}
			sort(now,now+sz);
			if(now[0]=='a'&&now[1]=='c'&&now[2]=='e'&&now[3]=='f')
			{
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}