#include<stdio.h>
#include<queue>
struct node
{
	int num,id;
	bool operator<(const node &u)const{return num<u.num;}
}r;
int n,m,k,b;
bool a[200002];
long long cnt=0;
std::priority_queue<node>Q;
main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b);
		Q.push(node{b,i});
	}
	for(int i=1;i<=m*k;i++)
	{
		r=Q.top();Q.pop();
		cnt+=(long long)(r.num);a[r.id]=1;
	}b=0;printf("%lld\n",cnt);cnt=0;
	for(int i=1;i<=n&&cnt<k-1;i++)if((b+=a[i])==m)printf("%d ",i),b=0,cnt++;
}