#include<cstdio>
#include<algorithm>
using namespace std;
typedef double db;
db t,t1,t2,dis1,dis2,tp;
int T,L,s1,s2,n,l,r,a[100005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&L);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		a[0]=0;a[n+1]=L;
		l=1;r=n;
		s1=1;s2=1;t=0.0;dis1=0.0;dis2=(db)L;
		while(l<=r)
		{
			t1=((db)a[l]-dis1)/(db)s1;
			t2=(dis2-(db)a[r])/(db)s2;
			t+=(tp=min(t1,t2));
			dis1+=tp*(db)s1;
			dis2-=tp*(db)s2;
			if(t1<=t2)l++,s1++;
			else r--,s2++;
		}
		t+=(dis2-dis1)/((db)s1+(db)s2);
		printf("%.10f\n",t);
	}
	return 0;
}