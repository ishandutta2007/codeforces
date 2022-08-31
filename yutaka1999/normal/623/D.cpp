#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 105

using namespace std;
typedef long double ld;
typedef pair <ld,int> P;

ld pb[SIZE];
ld now[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		pb[i]=1.0-(ld) p/100.0;
	}
	ld ret=(ld) n,mul=1.0;
	priority_queue <P> que;
	for(int i=0;i<n;i++)
	{
		now[i]=pb[i];
		mul*=1.0-now[i];
		que.push(P((1.0-now[i]*pb[i])/(1.0-now[i]),i));
	}
	ret+=1.0-mul;
	for(int i=0;i<500000;i++)
	{
		P p=que.top();que.pop();
		mul*=p.first;
		ret+=1.0-mul;
		int v=p.second;
		now[v]*=pb[v];
		que.push(P((1.0-now[v]*pb[v])/(1.0-now[v]),v));
	}
	printf("%.10f\n",(double) ret);
	return 0;
}