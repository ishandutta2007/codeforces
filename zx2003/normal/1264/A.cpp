#include<bits/stdc++.h>
const int N=4e5+5;
int T,n,p[N],v[N],c[N],m,i,j,k,s[N];
int main(){
	scanf("%d",&T);
	for(;T--;){
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d",p+i);
		if(n==1){puts("0 0 0");continue;}
		m=0;
		for(i=1;i<=n/2;++i)!m || v[m]>p[i]?v[++m]=p[i],c[m]=1:++c[m];
		if(v[m]==p[i])--m;
		if(m<3){puts("0 0 0");continue;}
		for(j=2;j<=m;++j)s[j]=s[j-1]+c[j];
		for(j=2;j<m;++j)if(s[j]>c[1] && s[m]-s[j]>c[1])break;
		if(j<m)printf("%d %d %d\n",c[1],s[j],s[m]-s[j]);else puts("0 0 0");
	}
	return 0;
}