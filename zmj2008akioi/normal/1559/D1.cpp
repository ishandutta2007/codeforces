#include <cstdio>
int n,u,v,m1,m2,cnt,f1[1010],f2[1010],add1[1010],add2[1010];
int find(int x,int *f){
	if(f[x]!=x)f[x]=find(f[x],f);
	return f[x];
}
int main(){
	scanf("%d %d %d",&n,&m1,&m2);
	for(register int i=1;!(i>n);++i)f1[i]=f2[i]=i;
	for(register int i=0;i<m1;++i)scanf("%d %d",&u,&v),f1[find(u,f1)]=find(v,f1);
	for(register int i=0;i<m2;++i)scanf("%d %d",&u,&v),f2[find(u,f2)]=find(v,f2);
	for(register int i=1;!(i>n);++i)for(register int j=i+1;!(j>n);++j)if(find(i,f1)!=find(j,f1)&&find(i,f2)!=find(j,f2))f1[find(i,f1)]=find(j,f1),f2[find(i,f2)]=find(j,f2),++cnt,add1[cnt]=i,add2[cnt]=j;
	printf("%d\n",cnt);
	for(register int i=1;!(i>cnt);++i)printf("%d %d\n",add1[i],add2[i]);
	return 0;
}