#include<cstdio>
#include<algorithm>
const int N=105,M=2005;
int n,i,j,f[N][M],t[N],d[N],p[N],pre[N][M],ans,i1,i2,a[N],w,id[N];
struct node{
	int t,d,p,id;
	bool operator<(const node&rhs)const{
		return d<rhs.d; 
	}
}b[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d%d",&b[i].t,&b[i].d,&b[i].p),b[i].id=i;
	std::sort(b+1,n+b+1);
	for(i=1;i<=n;++i)t[i]=b[i].t,d[i]=b[i].d,p[i]=b[i].p,id[i]=b[i].id;
	for(i=1;i<=n;++i){
		for(j=t[i];j<d[i];++j){
			if(f[i-1][j]>f[i-1][j-t[i]]+p[i])f[i][j]=f[i-1][j],pre[i][j]=j;
				else f[i][j]=f[i-1][j-t[i]]+p[i],pre[i][j]=j-t[i];
			if(f[i][j]>ans)
				ans=f[i][j],i1=i,i2=j;
		}
		for(j=0;j<t[i];++j)f[i][j]=f[i-1][j],pre[i][j]=j;
	}
	if(!ans)return puts("0\n0"),0;
	printf("%d\n",ans);
	for(i=i1,j=i2;j;j=pre[i--][j])
		if(pre[i][j]!=j)
			a[++w]=id[i];
	printf("%d\n",w);
	for(i=w;i;--i)printf("%d ",a[i]);
	return 0;
}