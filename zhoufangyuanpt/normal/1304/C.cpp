#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int a,l,r;
}a[110];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,l,r;scanf("%d%d",&n,&l);r=l;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].a,&a[i].l,&a[i].r);
		}
		sort(a+1,a+n+1,[](node x,node y){return x.a<y.a;});
		bool bk=true;a[0].a=0;
		for(int i=1;i<=n;i++)
		{
			l-=a[i].a-a[i-1].a;r+=a[i].a-a[i-1].a;
			if(a[i].l<=r&&l<=a[i].r)
			{
				l=max(l,a[i].l);
				r=min(r,a[i].r);
			}
			else{bk=false;break;}
		}
		puts(bk?"YES":"NO");
	}
	return 0;
}