#include<bits/stdc++.h>
int T,n,m,a[305][305],i,j,b;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		bool fl=1;
		for(i=1;i<=n;++i)for(j=1;j<=m;++j){
			scanf("%d",a[i]+j);
			b=(i>1)+(i<n)+(j>1)+(j<m);
			if(b<a[i][j])fl=0;else a[i][j]=b;
		}
		if(!fl){puts("NO");continue;}
		puts("YES");
		for(i=1;i<=n;++i)for(j=1;j<=m;++j)printf("%d%c",a[i][j],j==m?'\n':' ');
	}
}