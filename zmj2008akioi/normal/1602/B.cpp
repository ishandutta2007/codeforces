#include <cstdio>
int t,n,m,k,x,arr[2010],bucket[2010],rec[2010][2010];
inline int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&t);
	do{
		scanf("%d",&n);
		for(register int i=1;i<=n;++i)scanf("%d",&rec[0][i]);
		for(register int i=1;i<=n;++i){
			for(register int j=1;j<=n;++j)bucket[j]=0;
			for(register int j=1;j<=n;++j)++bucket[rec[i-1][j]];
			for(register int j=1;j<=n;++j)rec[i][j]=bucket[rec[i-1][j]];
		}
		scanf("%d",&m);
		for(register int i=1;i<=m;++i){
			scanf("%d %d",&x,&k);
			printf("%d\n",rec[min(k,n)][x]);
		}
	}while(--t);
	return 0;
}