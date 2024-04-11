#include<stdio.h>
int n,a[502],f[502][502],t[502];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		f[i][i]=a[i];
		for(int j=i+1;j<=n;j++){
			f[i][j]=0;
			for(int k=i;k<j;k++)
				if(f[i][k]&&f[i][k]==f[k+1][j])f[i][j]=f[i][k]+1;
		}
	}for(int i=1;i<=n;i++){
		t[i]=1e9;
		for(int j=0;j<i;j++)if(f[j+1][i]&&t[j]+1<t[i])t[i]=t[j]+1;
	}printf("%d",t[n]);
}