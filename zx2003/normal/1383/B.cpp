#include<bits/stdc++.h>
const int N=1e5+5;
int T,n,a[N],i,j,s;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);s=0;
		for(i=1;i<=n;++i)scanf("%d",a+i),s^=a[i];
		if(!s){puts("DRAW");continue;}
		for(i=0;1<<i<=s;++i);--i;
		int c1=0,c0=0;
		for(j=1;j<=n;++j)if(a[j]>>i&1)++c1;else ++c0;
		puts((c1%4==1?1:c0&1)?"WIN":"LOSE");
	}
}