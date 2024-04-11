#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair <int,int> P;

priority_queue <P,vector <P>,greater <P> > que[2];

int main()
{
	int n;
	scanf("%d",&n);
	bool up=true;
	for(int i=1;i<=n;i++)
	{
		int v,s;
		scanf("%d %d",&v,&s);
		que[v].push(P(s,i));
		if(s!=0) up=false;
	}
	if(up)
	{
		int c1=que[0].top().second,c2=que[1].top().second;
		que[0].pop();que[1].pop();
		printf("%d %d %d\n",c1,c2,0);
		while(!que[0].empty())
		{
			P p=que[0].top();que[0].pop();
			printf("%d %d %d\n",c2,p.second,0);
		}
		while(!que[1].empty())
		{
			P p=que[1].top();que[1].pop();
			printf("%d %d %d\n",c1,p.second,0);
		}
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		P p1=que[0].top(),p2=que[1].top();
		que[0].pop();que[1].pop();
		if(p1.first<p2.first)
		{
			p2.first-=p1.first;
			printf("%d %d %d\n",p1.second,p2.second,p1.first);
			que[1].push(p2);
		}
		else
		{
			p1.first-=p2.first;
			printf("%d %d %d\n",p1.second,p2.second,p2.first);
			que[0].push(p1);
		}
	}
	return 0;
}