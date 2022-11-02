#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct order
{
	int a,b,num;
}t[N]={};
int n,p,k;
int main()
{
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&t[i].a,&t[i].b);
		t[i].num=i;
	}
	sort(t+1,t+n+1,[](const order &x,const order &y)
					{return x.b<y.b || (x.b==y.b && x.a>y.a);});
	sort(t+p-k+1,t+n+1,[](const order &x,const order &y)
					{return x.a<y.a || (x.a==y.a && x.b<y.b);});
	sort(t+1,t+n-k+1,[](const order &x,const order &y)
					{return x.b<y.b || (x.b==y.b && x.a>y.a);});
	for(int i=n-k+1;i<=n;++i)
		printf("%d ",t[i].num);
	int tot=p-k,minb=1<<30,maxa=0;
	for(int i=n-k+1;i<=n;++i)
		if(t[i].b<minb || (t[i].b==minb && t[i].a>maxa))
			minb=t[i].b,maxa=t[i].a;
	for(int i=n-k;i>=1 && tot;--i)
		if(t[i].b<minb || (t[i].b==minb && t[i].a>=maxa))
			--tot,printf("%d ",t[i].num);
	printf("\n");
	return 0;
}