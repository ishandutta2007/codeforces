#include<bits/stdc++.h>
int n,r,i,c[269999],z,g;
long long tot;
int main(){
	scanf("%d%d",&n,&r);
	for(i=0;i<1<<n;++i)scanf("%d",c+i),tot+=c[i];
	printf("%.10f\n",tot*1.0/(1<<n));
	for(;r--;)scanf("%d%d",&z,&g),tot+=g-c[z],printf("%.10f\n",tot*1.0/(1<<n)),c[z]=g;
}