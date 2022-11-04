#include<bits/stdc++.h>
using namespace std;
int n,H;
char s[15];
double ans;
int main(){
	scanf("%s%d%d",s,&n,&H);
	if (s[0]=='B'){
		printf("%d\n",n);
		return 0;
	}
	double ans=n;
	for (int l=1;l<n;l++)
		for (int h=1;h<=H;h++){
			double tmp=pow(2,h);
			if (h) tmp-=pow(2,h-1)*(1+(l-1)/(pow(2,h)-1));
			ans+=pow(0.5,h*2)*pow(1-pow(0.5,h),l-1)*tmp*(n-l);
		}
	printf("%.10lf\n",ans);
}