#include<stdio.h>
int n,k,t;
char c[2002],d[2002];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%s",&n,&k,c+1);
		for(int i=1;i<=n;i++){
			if(i+1>>1<=k-1)d[i]=i&1?'(':')';
			else d[i]=i<=(n+(k-1)*2)/2?'(':')';
		}printf("%d\n",n);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(d[i]==c[j]){
					char tmp;
					for(int k=i;k+k<i+j;k++)tmp=c[k],c[k]=c[i+j-k],c[i+j-k]=tmp;
					printf("%d %d\n",i,j);break;
				}
			}
		}
	}
}