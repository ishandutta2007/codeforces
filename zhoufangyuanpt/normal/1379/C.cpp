#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
template<typename T>
inline T mymax(T x,T y){return x>y?x:y;}
template<typename T>
inline T mymin(T x,T y){return x<y?x:y;}
struct node
{
	int x,y,p;
}a[110000],b[110000];
int p[110000];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,m;scanf("%d%d",&m,&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].p=i;
		}
		for(int i=1;i<=n;i++)b[i]=a[i];
		sort(a+1,a+n+1,[](node x,node y){return x.x>y.x;});
		for(int i=1;i<=n;i++)p[a[i].p]=i;
		sort(b+1,b+n+1,[](node x,node y){return x.y<y.y;});
		long long j=mymin(n,m),s=0,ss=0;
		for(int i=1;i<=j;i++)s=s+a[i].x;
		for(int i=1;i<=n;i++)
		{
			while(j>=1&&a[j].x<=b[i].y)s=s-a[j--].x;
			int k=m-j;
			if(p[b[i].p]<=j)k++,s-=b[i].x;
			ss=mymax(ss,s+1ll*(k>0)*b[i].x+1ll*(k>0)*(k-1)*b[i].y);
			if(p[b[i].p]<=j)s+=b[i].x;
		}
		printf("%lld\n",ss);
	}
	return 0;
}