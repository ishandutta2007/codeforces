#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair <int,int> P;
typedef pair <int,P> PP;

int main()
{
	priority_queue <PP,vector <PP>,greater <PP> > que;
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		que.push(PP(0,P(abs(m+1-2*i),i)));
	}
	for(int i=0;i<n;i++)
	{
		PP p=que.top();que.pop();
		printf("%d\n",p.second.second);
		p.first++;
		que.push(p);
	}
	return 0;
}