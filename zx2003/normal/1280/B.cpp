#include<bits/stdc++.h>
const int N=65;
int T,r,c,i,j;
char a[N][N];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&r,&c);
		for(i=1;i<=r;++i)scanf("%s",a[i]+1);
		int cta=0,ctp=0;
		for(i=1;i<=r;++i)for(j=1;j<=c;++j)(a[i][j]=='A'?cta:ctp)++;
		if(!ctp){puts("0");continue;}
		if(!cta){puts("MORTAL");continue;}
		int ca[4]={0,0,0,0},cp[4]={0,0,0,0};
		for(j=1;j<=c;++j){
			ca[0]+=a[1][j]=='A',cp[0]+=a[1][j]=='P';
			ca[2]+=a[r][j]=='A',cp[2]+=a[r][j]=='P';
		}
		for(i=1;i<=r;++i){
			ca[1]+=a[i][c]=='A',cp[1]+=a[i][c]=='P';
			ca[3]+=a[i][1]=='A',cp[3]+=a[i][1]=='P';
		}
		if(!cp[0] || !cp[1] || !cp[2] || !cp[3]){puts("1");continue;}
		for(i=1;i<=r;++i){
			for(j=1;j<=c;++j)if(a[i][j]=='P')break;
			if(j>c)break;
		}
		if(i<=r){puts("2");continue;}
		for(j=1;j<=c;++j){
			for(i=1;i<=r;++i)if(a[i][j]=='P')break;
			if(i>r)break;
		}
		if(j<=c){puts("2");continue;}
		if(a[1][1]=='A' || a[1][c]=='A' || a[r][c]=='A' || a[r][1]=='A'){puts("2");continue;}
		puts(ca[0] || ca[1] || ca[2] || ca[3]?"3":"4");
	}
	return 0;
}