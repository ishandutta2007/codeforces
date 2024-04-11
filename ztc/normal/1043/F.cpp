#include<stdio.h>
#include<bits/stdc++.h>
int a[300002],b[300002],c[300002],d[300002],e[300002],Next[300002],top=0,n,m,s[10],l;
inline int gcd(int p,int q){return q?gcd(q,p%q):p;}
inline bool dfs(int p,int g){
	if(g==l+1)return d[p];
	return dfs(p*s[g],g+1)|dfs(p,g+1);
}
int main(){
	for(int i=2;i<=300000;i++){
		if(!c[i])b[++top]=i,c[i]=1,e[i]=i;
		for(int j=1;j<=top&&b[j]*i<=300000;j++){
			e[b[j]*i]=b[j];c[b[j]*i]=c[i]+(i%b[j]!=0);if(i%b[j]==0)break;
		}
	}scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int p;a[i]=1;scanf("%d",&p);
		while(p!=1){a[i]*=e[p];while(e[p]==e[p/e[p]])p/=e[p];p/=e[p];}
	}std::sort(a+1,a+n+1);m=n;n=0;
	for(int i=1;i<=m;i++)if(a[i]!=a[i+1])a[++n]=a[i];
	if(a[1]==1)return printf("1")&0;m=n;n=0;
	for(int i=1;i<=m;i++){
		l=0;for(int p=a[i];p!=1;p/=e[p]){if(e[p]!=s[l])s[++l]=e[p];}
		if(!dfs(1,1))a[++n]=a[i];d[a[i]]=1;
	}m=0;for(int i=1;i<=n;i++)if(c[a[i]]==1){if(m)return printf("2")&0;m=a[i];}
	if(m){
		for(int i=1;i<=n;i++)if(a[i]%m)return printf("2")&0;
		return printf("-1")&0;
	}l=0;for(int i=1;i<=n;i++)l=gcd(a[i],l);
	if(l!=1)return printf("-1")&0;
	for(int i=1;i<=300000;i++)d[i]=9;
	Next[0]=a[1];d[a[1]]=1;
	for(int i=2;i<=n;i++){d[a[i]]=1;l=0;
		for(int j=Next[0];j;j=Next[j]){
			int k=gcd(j,a[i]);
			if(d[k]>d[j]+1)d[k]=d[j]+1;
			if(!l&&j>a[i])l=j;
		}for(int j=a[i];j>=1;j--)if(d[j]<=1e7)Next[j]=l,l=j;
		Next[0]=l;
	}printf("%d",d[1]);
}