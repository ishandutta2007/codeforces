#include<stdio.h>
int a[2002][2002],b[2002][2002],c[2002][2002],ans[2002][2002],x[2002][2],y[2002][2],anss=0,n,k,cntt=0;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		while(getchar()!='\n');
		for(int j=1;j<=n;j++)a[i][j]=getchar()=='B';
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(a[i][j]){
			if(!x[i][0])x[i][0]=j;x[i][1]=j;
			if(!y[j][0])y[j][0]=i;y[j][1]=i;
		}
	}for(int i=1;i<=n;i++){
		if(x[i][0]==0&&x[i][1]==0)cntt++;
		else{
			int l=x[i][1]-k+1,r=x[i][0];
			for(int j=l;j<=r;j++)b[i][j]=1;
		}
	}for(int i=1;i<=n;i++){
		if(y[i][0]==0&&y[i][1]==0)cntt++;
		else{
			int l=y[i][1]-k+1,r=y[i][0];
			for(int j=l;j<=r;j++)c[j][i]=1;
		}
	}
	for(int j=1;j<=n-k+1;j++){
		for(int i=1;i<=n;i++)b[i][j]+=b[i-1][j];
		for(int i=1;i<=n-k+1;i++)ans[i][j]+=b[i+k-1][j]-b[i-1][j];
	}for(int j=1;j<=n-k+1;j++){
		for(int i=1;i<=n;i++)c[j][i]+=c[j][i-1];
		for(int i=1;i<=n-k+1;i++)ans[j][i]+=c[j][i+k-1]-c[j][i-1];
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(ans[i][j]>anss)anss=ans[i][j];
	printf("%d",anss+cntt);
}