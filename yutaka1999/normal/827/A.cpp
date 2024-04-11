#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <functional>
#define SIZE 2000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char ans[SIZE];
char str[SIZE];
set <int> zan;
set <int>::iterator it;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<SIZE;i++) zan.insert(i);
	int mx=0;
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		int L=strlen(str);
		int c;
		scanf("%d",&c);
		while(c--)
		{
			int s;
			scanf("%d",&s);s--;
			mx=max(mx,s+L);
			while(1)
			{
				it=zan.lower_bound(s);
				if(it==zan.end()) break;
				int to=*it;
				if(to>=s+L) break;
				zan.erase(to);
				ans[to]=str[to-s];
			}
		}
	}
	for(it=zan.begin();it!=zan.end();it++)
	{
		if(*it<mx) ans[*it]='a';
	}
	printf("%s\n",ans);
	return 0;
}