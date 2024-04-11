#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
list<int> l[100010];
int main()
{
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	int i,x;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		l[x%m].push_back(x);
	}
	for(i=0;i<m;i++)
		if(l[i].size()>=k)
		{
			printf("Yes\n");
			while(k--)
			{
				printf("%d ",l[i].front());
				l[i].pop_front();
			}
			return 0;
		}
	printf("No\n");
	return 0;
}