#include <cstdio>
int t,n,l,a,b,y,ans,arr[110];
int main(){
	scanf("%d",&t);
	do{
		scanf("%d %d",&n,&l);
		y=0;
		for(register int i=1;i<=n;++i)scanf("%d",&arr[i]);
		for(register int i=0;i<l;++i){
			a=b=0;
			for(register int j=1;j<=n;++j){
				if(arr[j]&(1<<i))++a;
				else ++b;
			}
			if(a>b)y+=1<<i;
		}
		printf("%d\n",y);
	}while(--t);
	return 0;
}