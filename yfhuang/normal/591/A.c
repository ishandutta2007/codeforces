/*n~m*/
#include <stdio.h>
#include <string.h>

int main(){
	int l,p,q;
	while(scanf("%d%d%d",&l,&p,&q)==3){
		double ans=p*(double)l/(p+q);
		printf("%lf\n",ans);
    }
    return 0;
}