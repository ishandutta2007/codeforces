#include<bits/stdc++.h>
int sld[8],n,i,j,k,a[6],b[6],c[6],ans=-1;
double rg[7][2]={{0,0},{1.0/2,1},{1.0/4,1.0/2},{1.0/8,1.0/4},{1.0/16,1.0/8}
,{1.0/32,1.0/16},{-1,1.0/32}};
bool bb[6];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		for(j=1;j<=5;++j){
			scanf("%d",a+j);
			if(a[j]!=-1)++sld[j];
		}
		if(i==1)memcpy(b,a,sizeof b);
		if(i==2)memcpy(c,a,sizeof c);
	}
	for(i=1;i<=5;++i){
		int x=b[i]==-1?1000:b[i];
		int y=c[i]==-1?1000:c[i];
		if(x<y)bb[i]=1;else bb[i]=0;
	}
	for(i=0;i<=1000000;++i){
		double p;
		int p1=0,p2=0;
		for(j=1;j<=5;++j){
			if(!bb[j] && b[j]!=-1)p=(i+sld[j])*1.0/(i+n);
				else p=sld[j]*1.0/(i+n);
			for(k=1;k<=6;++k)if(rg[k][0]<p && p<=rg[k][1])break;
			if(b[j]!=-1)p1+=k*500-2*k*b[j];
			if(c[j]!=-1)p2+=k*500-2*k*c[j];
		}
		if(p1>p2)break;
	}
	if(i>1000000)i=-1;
	printf("%d\n",i);
	return 0;
}