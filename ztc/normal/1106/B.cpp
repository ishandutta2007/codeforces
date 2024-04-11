#include<stdio.h>
#include<queue>
#define Min(a,b) (a<b?a:b)
struct node
{
	int v,id;
	bool operator<(const node &u)const{if(u.v==v)return u.id<id;return u.v<v;}
};
int a[100002],b[100002],n,m,c,d,e;
long long cnt;
std::priority_queue<node>Q;
main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		Q.push(node{a[i],i});
	}
	while(m--)
	{
		scanf("%d%d",&c,&d);cnt=0;
		if(b[c])
		{
			e=Min(b[c],d);
			b[c]-=e;d-=e;cnt+=(long long)e*(long long)a[c];
		}
		while(!Q.empty()&&d)
		{
			c=Q.top().id;
			e=Min(b[c],d);
			b[c]-=e;d-=e;cnt+=(long long)e*(long long)a[c];
			if(!b[c])Q.pop();
		}
		printf("%lld\n",d?0:cnt);
	}
}