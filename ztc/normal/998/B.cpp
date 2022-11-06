#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
priority_queue<int>Q;
int n,i,a[202],b;
bool c[102];
int d[102];
long long cnt=0;
int main()
{
scanf("%d%d",&n,&b);
for(i=1;i<=n;i++)
{
	scanf("%d",&a[i]);
	if(i!=1)cnt+=(a[i-1]&1)*2-1;
	if(!cnt&&i!=1)
	{
		Q.push(-abs(a[i]-a[i-1]));
	}
}
i=0;
while(!Q.empty())
{
	if(b+Q.top()<0)break;
	i+=1;
	b+=Q.top();
	Q.pop();
}
printf("%d",i);
return 0;
}