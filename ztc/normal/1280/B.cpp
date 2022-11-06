#include<stdio.h>
char c[102][102];
int n,m,s,l;
int main(){
	scanf("%d",&s);
	while(s--){
		scanf("%d%d",&n,&m);bool f=0,t=1;
		for(int i=1;i<=n;i++)scanf("%s",&c[i][1]);
		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)if(c[i][j]=='P')t=0;}f|=t;t=1;
        if(f){puts("0");continue;}
		for(int i=1;i<=n;i++)if(c[i][1]=='P')t=0;f|=t;t=1;
		for(int i=1;i<=n;i++)if(c[i][m]=='P')t=0;f|=t;t=1;
		for(int i=1;i<=m;i++)if(c[1][i]=='P')t=0;f|=t;t=1;
		for(int i=1;i<=m;i++)if(c[n][i]=='P')t=0;f|=t;t=1;
		if(f){puts("1");continue;}
		for(int i=2;i<n;i++){for(int j=1;j<=m;j++)if(c[i][j]=='P')t=0;f|=t;t=1;}
		for(int i=2;i<m;i++){for(int j=1;j<=n;j++)if(c[j][i]=='P')t=0;f|=t;t=1;}
		if(c[1][1]=='A'||c[1][m]=='A'||c[n][1]=='A'||c[n][m]=='A')f=1;
		if(f){puts("2");continue;}t=0;
		for(int i=1;i<=n;i++)if(c[i][1]=='A')t=1;f|=t;t=0;
		for(int i=1;i<=n;i++)if(c[i][m]=='A')t=1;f|=t;t=0;
		for(int i=1;i<=m;i++)if(c[1][i]=='A')t=1;f|=t;t=0;
		for(int i=1;i<=m;i++)if(c[n][i]=='A')t=1;f|=t;t=0;
		if(f){puts("3");continue;}
		for(int i=2;i<n;i++){for(int j=2;j<m;j++)if(c[i][j]=='A')t=1;f|=t;t=0;}
		if(f){puts("4");continue;}
		puts("MORTAL");
	}
}