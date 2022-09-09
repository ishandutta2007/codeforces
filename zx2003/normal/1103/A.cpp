#include<bits/stdc++.h>
char c[1005];
bool cov[6][6],delr[6],delc[6];
int i,j,k;
int main(){
	scanf("%s",c+1);
	for(i=1;c[i];++i){
		if(c[i]=='0'){
			for(k=1;k<=4;++k){
				for(j=1;j<=3;++j)if(!cov[j][k] && !cov[j+1][k])break;
				if(j<=3)break;
			}
			if(j==4){
++j,--j;
}
			cov[j][k]=cov[j+1][k]=1;
		}else{
			for(j=1;j<=4;++j){
				for(k=1;k<=3;++k)if(!cov[j][k] && !cov[j][k+1])break;
				if(k<=3)break;
			}
			if(j==5){
++j,--j;
}
			cov[j][k]=cov[j][k+1]=1;
		}
		printf("%d %d\n",j,k);
		for(j=1;j<=4;++j){delr[j]=1;for(k=1;k<=4;++k)delr[j]=delr[j] && cov[j][k];}
		for(j=1;j<=4;++j){delc[j]=1;for(k=1;k<=4;++k)delc[j]=delc[j] && cov[k][j];}
		for(j=1;j<=4;++j)if(delr[j])for(k=1;k<=4;++k)cov[j][k]=0;
		for(j=1;j<=4;++j)if(delc[j])for(k=1;k<=4;++k)cov[k][j]=0;
	}
	return 0;
}