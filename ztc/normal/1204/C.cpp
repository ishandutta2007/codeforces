#include<stdio.h>
#include<queue>
int a[102][102],n,m,b[1000002],p,ans=0;char c[102];std::queue<int>Q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",c);
		for(int j=1;j<=n;j++)a[i][j]=c[j-1]=='1'?1:1000000000;a[i][i]=0;
	}scanf("%d",&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)if(a[j][i]+a[i][k]<a[j][k])a[j][k]=a[j][i]+a[i][k];
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		if(p==0){p=i;Q.push(b[i]);}
		else if(i-p!=a[b[p]][b[i]]){Q.push(b[i-1]);p=i-1;}
	}Q.push(b[m]);printf("%d\n",Q.size());
	while(!Q.empty()){printf("%d ",Q.front());Q.pop();}
}