#include<stdio.h>
inline int Min(int p,int q){return p<q?p:q;}
inline int Max(int p,int q){return p>q?p:q;}
int n,m,t,a[1002][1002];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
		for(int d=2;d<=n+m+1>>1;d++){
			int c[2]={0,0};
			for(int i=1,j=d-1;j;i++,j--)if(i<=n&&j<=m)c[a[i][j]]++,c[a[n+1-i][m+1-j]]++;
			ans+=Min(c[0],c[1]);
		}printf("%d\n",ans);
	}
}