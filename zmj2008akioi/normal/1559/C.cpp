#include <cstdio>
#include <cstring>
int t,n,arr[10010];
bool tag;
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d",&n);
		arr[0]=0,arr[n+1]=1,tag=false;
		for(register int j=1;!(j>n);++j)scanf("%d",&arr[j]);
		for(register int j=0;!(j>n);++j){
			if(arr[j]==0&&arr[j+1]==1){
				tag=true;
				for(register int k=1;!(k>j);++k)printf("%d ",k);
				printf("%d ",n+1);
				for(register int k=j+1;!(k>n);++k)printf("%d ",k);
				break;
			}
		}
		if(!tag)printf("-1");
		putchar('\n');
	}
	return 0;
}