#include<bits/stdc++.h>
using namespace std;
int n,a[105],i,j,k,l,tot,c[105];
int f[105][10005],ans;
void upd(int&a,int b){a=min(a+b,2);}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),tot+=a[i],++c[a[i]];
	f[0][0]=1;
	for(i=1;i<=100;++i)if(c[i]){
		for(k=n;k;--k)for(j=tot;j>=i;--j)
			for(l=1;l<=c[i] && l<=k && l*i<=j;++l)upd(f[k][j],f[k-l][j-l*i]);
	}
	if(tot%n==0 && n<=c[tot/n])ans=n;
	for(i=n-1;i;--i)for(j=0;j<=tot;++j)if(f[i][j]==1){
		if(j%i==0 && i<=c[j/i])ans=max(ans,i);
		if((tot-j)%(n-i)==0 && n-i<=c[(tot-j)/(n-i)])ans=max(ans,n-i);
		if(j%i==0 && i<=c[j/i] && (tot-j)%(n-i)==0 && n-i<=c[(tot-j)/(n-i)])ans=n;
	}
	printf("%d\n",ans);
	return 0;
}