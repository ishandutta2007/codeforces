#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=3e3+5;
int n;
ll ans;
priority_queue<int>q;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read()-i;
		if(q.size()&&q.top()>x){q.push(x);q.push(x);ans+=q.top()-x;q.pop();}
		else q.push(x);
	}
	printf("%lld",ans);
	return 0;
}