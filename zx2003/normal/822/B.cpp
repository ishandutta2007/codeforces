#include<cstdio>
char a[1010],b[1010];
int n,m,i,j,l,s,x;
int main(){
	scanf("%d%d%s%s",&n,&m,a+1,b+1);
	l=n;
	for(i=n;i<=m;++i){
		s=0;
		for(j=1;j<=n;++j)
			if(a[j]!=b[i-n+j])++s;
		if(s<l)l=s,x=i;
	}
	printf("%d\n",l);
	for(i=1;i<=n;++i)if(a[i]!=b[x-n+i])printf("%d ",i);
	return 0;
}