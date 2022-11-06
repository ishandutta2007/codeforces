#include<stdio.h>
inline int Max(int a,int b){return a>b?a:b;}
int a[100002][5],n,m;long long ans=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		while(getchar()!='\n');
		for(int j=1;j<=m;j++)a[j][getchar()-'A']++;
	}for(int i=1;i<=m;i++)scanf("%d",&n),ans+=Max(Max(Max(Max(a[i][4],a[i][3]),a[i][2]),a[i][1]),a[i][0])*n;
	printf("%lld",ans);
}