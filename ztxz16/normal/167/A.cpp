#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n,i;
double a,d,t,v,x1,time_now,ans_now;

int main()
{
    scanf("%d %lf %lf",&n,&a,&d);
    for(i=1;i<=n;i++)
    {
		scanf("%lf %lf",&t,&v);
		x1=(v/2)*(v/a);
		if (x1>d)
			time_now=sqrt((d*2/a));
		else time_now=v/a+(d-x1)/v;
		time_now+=t;
		if (i==1 || time_now>ans_now)
			ans_now=time_now,printf("%.10lf\n",ans_now);
		else printf("%.10lf\n",ans_now);
	}
    return 0;
}