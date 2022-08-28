#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE],B[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	ll ret=0;
	int sz=0;
	priority_queue <P> que;
	for(int i=0;i<n;i++)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(a<=d&&b<=c) continue;
		if(a+b<=c+d)
		{
			if(a>=d) ret+=a-d;
			else ret-=b-c;
			continue;
		}
		ret+=a+c;
		A[sz]=a+b,B[sz]=c+d;
		que.push(P(A[sz],sz));
		sz++;
	}
	int turn=0;
	while(!que.empty())
	{
		P p=que.top();que.pop();
		//printf("%d : %d %d\n",turn,p.first,p.second);
		if(turn==1) ret-=p.first;
		int v=p.second;
		if(A[v]==p.first) que.push(P(B[v],v));
		turn^=1;
	}
	printf("%lld\n",ret);
	return 0;
}