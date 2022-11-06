#include<stdio.h>
#include<queue>
#include<stack>
#define Min(a,b) (a<b?a:b)
int n;
long long cnt,a;
std::priority_queue<long long>Q;
std::stack<long long>S;
main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lld",&a);
		Q.push(a);cnt+=a*a;
	}
	while(Q.size()>S.size())
	{
		S.push(Q.top());
		Q.pop();
	}
	while(!Q.empty()&&!S.empty())
	{
		cnt+=Q.top()*S.top()*2;
		Q.pop();S.pop();
	}printf("%lld",cnt);
}