#include<stdio.h>
int a[100002],b[100002],n,m,k,x,t;
int main(){
	scanf("%d",&t);while(getchar()!='\n');
	while(t--){
		n=0;m=0;
		while((a[++n]=getchar()-'0')>=0);n--;
		while((b[++m]=getchar()-'0')>=0);m--;
		for(int i=1;i<=n;i++){if(i>=n+1-i)break;a[i]^=a[n+1-i]^=a[i]^=a[n+1-i];}
		for(int i=1;i<=m;i++){if(i>=m+1-i)break;b[i]^=b[m+1-i]^=b[i]^=b[m+1-i];}
		for(x=1;x<=m;x++)if(b[x])break;
		if(x==n+1){
			printf("0\n");
			break;
		}else{k=0;
			for(int i=x;i<=n&&!a[i];i++)k++;
			printf("%d\n",k);
		}
	}
}