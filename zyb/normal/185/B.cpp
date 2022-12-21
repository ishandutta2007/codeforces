#include<stdio.h>
using namespace std;
int s,a,b,c;
int main() {
	scanf("%d%d%d%d",&s,&a,&b,&c);
	if (a==0) {
		if (b==0) {
			if (c!=0) printf("%.14lf %.14lf %.14lf\n",0.0,0.0,s*1.);
			else printf("%.14lf %.14lf %.14lf\n",0.0,0.0,0.0);
		}
		else if (c==0) printf("%.14lf %.14lf %.14lf\n",0.0,s*1.,0.0);
		else printf("%.14lf %.14lf %.14lf\n",0.0,s*1.*(b*1./(b+c)),s*1.0*(c*1.0/(b+c)));
	}
	else {
		if (b==0) {
			if (c==0) printf("%.14lf %.14lf %.14lf\n",s*1.,0.0,0.0);
			else printf("%.14lf %.14lf %.14lf\n",s*1.*(a*1./(a+c)),0.0,s*1.*c*1./(a+c)); 
		}
		else {
			if (c==0) printf("%.14lf %.14lf %.14lf\n",s*1.*(a*1./(a+b)),s*1.*(b*1./(a+b)),0.0); 
			else printf("%.14lf %.14lf %.14lf\n",s*1.*(a*1./(a+b+c)),s*1.*(b*1./(a+b+c)),s*1.*(c*1./(a+b+c))); 
		}
	}
}