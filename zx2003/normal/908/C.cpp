#include<bits/stdc++.h>
int n,x[1005],r,i,j,z;
double y[1005];
int main(){
	scanf("%d%d",&n,&r);
	for(i=1;i<=n;++i){
		scanf("%d",x+i);y[i]=r;
		for(j=1;j<i;++j){
			z=x[i]-x[j];
			if(2*r>=z)y[i]=std::max(y[i],y[j]+sqrt(4*r*r-z*z));
		}
	}
	for(i=1;i<=n;++i)printf("%.8lf ",y[i]);
	return 0;
}