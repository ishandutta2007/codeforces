#include<cstdio>
#include<cstring>
const int N=105,M=10000000;
int n,m,i,j,x,a[N][N],d[M],l,k;
bool rr[N],cc[N];
char b[M];
int main(){
	scanf("%d%d",&n,&m);
	x=600;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j){
			scanf("%d",&a[i][j]);
			if(a[i][j]<x)x=a[i][j];
		}
	if(x){
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)a[i][j]-=x;
		if(n<m){
			for(i=1;i<=n;++i)
				for(j=1;j<=x;++j)d[++l]=i,b[l]='r';
		}else{
			for(i=1;i<=m;++i)
				for(j=1;j<=x;++j)d[++l]=i,b[l]='c';			
		}
	}
	for(x=1;x;){
		memset(rr,0,sizeof rr);
		memset(cc,0,sizeof cc);
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				if(!a[i][j])rr[i]=cc[j]=1;
		x=0;
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				if(a[i][j]){
					x=a[i][j];
					if(rr[i]){
						if(cc[j])return puts("-1"),0;
						for(k=1;k<=x;++k){
							d[++l]=j;
							b[l]='c';
						}
						for(k=1;k<=n;++k){
							a[k][j]-=x;
							if(a[k][j]<0)return puts("-1"),0;
						}
					}
					if(cc[j]){
						for(k=1;k<=x;++k){
							d[++l]=i;
							b[l]='r';
						}
						for(k=1;k<=m;++k){
							a[i][k]-=x;
							if(a[i][k]<0)return puts("-1"),0;
						}
					}
				}
	}
	printf("%d\n",l);
	for(i=1;i<=l;++i)
		if(b[i]=='r')printf("row %d\n",d[i]);
			else printf("col %d\n",d[i]);
	return 0;
}