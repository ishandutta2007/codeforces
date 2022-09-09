#include<bits/stdc++.h>
const int N=55;
int aa[N][N];
int a[N][N],i,j,n;
inline int ask(int x1,int y1,int x2,int y2){
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int x;scanf("%d",&x);return x;
}
inline void out(){
	puts("!");
	for(i=1;i<=n;++i,puts(""))for(j=1;j<=n;++j)printf("%d",a[i][j]);
	fflush(stdout);
	exit(0);
}
int main(){
	scanf("%d",&n);
//for(i=1;i<=n;++i)for(j=1;j<=n;++j)scanf("%d",aa[i]+j);
	a[1][1]=1;a[n][n]=0;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if((i+j)%2==0){
		if(i==1 && j==1)continue;
		if(i==n && j==n)continue;
		if(j==2)a[i][j]=a[i-1][j-1]^!ask(i-1,j-1,i,j);
			else if(j==1)a[i][j]=a[i-2][j]^!ask(i-2,j,i,j);
					else a[i][j]=a[i][j-2]^!ask(i,j-2,i,j);
	}
	a[1][2]=0;
	for(i=1;i<=n;++i){
		for(j=i&1?4:5;j<=n;j+=2)a[i][j]=a[i][j-2]^!ask(i,j-2,i,j);
		if(i%2==0)a[i][1]=a[i][3]^!ask(i,1,i,3);
		if(i<n){
			if(i%2==0)a[i+1][2]=a[i][1]^!ask(i,1,i+1,2);
				else a[i+1][3]=a[i][2]^!ask(i,2,i+1,3);
		}
	}
	for(i=2;i<=n;++i)for(j=1;j<n;++j)if(a[i][j]!=a[i-1][j+1]){
		int t;
		if(i<n){
//			if((i+j)%2==0)y=a[i+1][j+1];else y=a[i-1][j];
			t=a[i+1][j+1]^a[i-1][j]^!ask(i-1,j,i+1,j+1);
		}else{
			t=a[i-2][j]^a[i][j+1]^!ask(i-2,j,i,j+1);
		}
		for(i=1;i<=n;++i)for(j=1;j<=n;++j)if((i+j)%2==1)a[i][j]^=t;
		out();
	}
	for(i=1;i+2<=n;++i)for(j=1;j<n;++j)if((a[i][j]==a[i+1][j+1])==(a[i+1][j]==a[i+2][j+1])){
		int t=ask(i,j,i+2,j+1);
		if(t)t=a[i][j]^a[i+2][j+1];else t=!(a[i][j]^a[i+2][j+1]);
		for(i=1;i<=n;++i)for(j=1;j<=n;++j)if((i+j)%2==1)a[i][j]^=t;
		out();
	}
	return 0;
}