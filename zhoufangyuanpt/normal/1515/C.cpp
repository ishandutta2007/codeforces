#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node{int x,p;};
inline bool operator<(node x,node y){return x.x>y.x;}
priority_queue<node> Q;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,m,x;scanf("%d%d%d",&n,&m,&x);
		while(!Q.empty())Q.pop();
		for(int i=1;i<=m;i++)Q.push({0,i});
		puts("YES");
		for(int i=1;i<=n;i++)
		{
			int c;scanf("%d",&c);
			int x=Q.top().x,p=Q.top().p;
			printf("%d ",p);
			Q.pop();Q.push({x+c,p});
		}
		printf("\n");
	}
	return 0;
}