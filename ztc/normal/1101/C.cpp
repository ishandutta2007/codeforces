#include<stdio.h>
#include<queue>
struct node
{
	int l,r,id;
	bool operator<(const node &n)const{if(n.l==l)return n.r<r;return n.l<l;};
}r;
std::priority_queue<node>Q;
int n,i,t,k;
bool a[200002];
main()
{
	scanf("%d",&t);
	while(t--)
	{
		while(n)a[n--]=0;scanf("%d",&n);
		while(!Q.empty())Q.pop();
		for(r.id=1;r.id<=n;r.id++)
		{
			scanf("%d%d",&r.l,&r.r);
			Q.push(r);
		}r=Q.top();Q.pop();a[r.id]=1;k=r.r;
		for(i=2;i<=n;i++)
		{
			if(k<Q.top().l)break;
			r=Q.top();a[r.id]=1;
			Q.pop();
			if(k<r.r)k=r.r;
		}
		if(Q.empty())printf("-1");
		else for(i=1;i<=n;i++)printf("%d ",1+a[i]);
		putchar('\n');
	}
}