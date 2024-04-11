#include<stdio.h>
#include<string.h>
double f[2][410];
int main(){
	int x,k,i,j,t;
	double p;
	scanf("%d%d%lf",&x,&k,&p);
	p*=.01;
	for(i=0;i<=k;i++){
		for(j=x+i;~j&1;j>>=1)f[0][i]+=1;
	}
	t=0;
	for(i=0;i<k;i++){
		memset(f[t^1],0,sizeof(f[t^1]));
		for(j=0;j<=k;j++){
			f[t^1][j<<1]+=(f[t][j]+1.)*p;
			f[t^1][j]+=f[t][j+1]*(1.-p);
		}
		t^=1;
	}
	printf("%.7lf",f[t][0]);
}