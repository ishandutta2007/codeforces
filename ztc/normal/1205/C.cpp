#include<cstdio>
int a[52][52],n,t;
main(){
	a[1][1]=1;a[2][1]=1;
	scanf("%d",&n);a[n][n]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if((i!=1||j!=1)&&(i!=n||j!=n))if((i^j^1)&1){
		if(j==1){printf("? %d %d %d %d\n",i-2,j,i,j);fflush(stdout);scanf("%d",&t);a[i][j]=a[i-2][j]^!t;}
		else if(j==2){printf("? %d %d %d %d\n",i-1,j-1,i,j);fflush(stdout);scanf("%d",&t);a[i][j]=a[i-1][j-1]^!t;}
		else{printf("? %d %d %d %d\n",i,j-2,i,j);fflush(stdout);scanf("%d",&t);a[i][j]=a[i][j-2]^!t;}
	}
	for(int i=2;i<=n;i++)for(int j=1;j<=n;j++)if(i!=2||j!=1)if((i^j)&1){
	    if(j==1){printf("? %d %d %d %d\n",i-2,j,i,j);fflush(stdout);scanf("%d",&t);a[i][j]=a[i-2][j]^!t;}
	    else if(j==2){printf("? %d %d %d %d\n",i-1,j-1,i,j);fflush(stdout);scanf("%d",&t);a[i][j]=a[i-1][j-1]^!t;}
	    else{printf("? %d %d %d %d\n",i,j-2,i,j);fflush(stdout);scanf("%d",&t);a[i][j]=a[i][j-2]^!t;}
	}
	printf("? %d %d %d %d\n",1,2,2,3);
	fflush(stdout);scanf("%d",&t);a[1][2]=a[2][3]^!t;
	for(int i=4;i<=n;i+=2){printf("? %d %d %d %d\n",1,i-2,1,i);fflush(stdout);scanf("%d",&t);a[1][i]=a[1][i-2]^!t;}
	for(int i=1;i<=n-2;i++){
		for(int j=1;j<=n-1;j++){
			if((a[i][j]^a[i+2][j+1])==(a[i+1][j]^a[i+2][j])||(a[i][j]^a[i+2][j+1])==(a[i+1][j]^a[i+1][j+1])||(a[i][j]^a[i+2][j+1])==(a[i][j+1]^a[i+1][j+1])){
				printf("? %d %d %d %d\n",i,j,i+2,j+1);
				fflush(stdout);
				scanf("%d",&t);
				t^=a[i][j]==a[i+2][j+1];
				printf("!\n");
				for(int p=1;p<=n;p++){
					for(int q=1;q<=n;q++)printf("%d",(p^q)&1?a[p][q]^t:a[p][q]);
					putchar('\n');
				}
			}
		}
	}
}