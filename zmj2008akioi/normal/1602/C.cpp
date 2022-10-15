#include <cstdio>
#include <cstring>
int t,n,arr[200010],count[60];
bool able[200010];
int main(){
	scanf("%d",&t);
	do{
		scanf("%d",&n);
		memset(count,0,sizeof(count));
		for(register int i=1;i<=n;++i)able[i]=true;
		for(register int i=1;i<=n;++i){
			scanf("%d",&arr[i]);
			for(register int j=0;j<30;++j)if(arr[i]&(1<<j))++count[j];
		}
		for(register int i=0;i<30;++i)for(register int j=1;j<=n;++j)if(count[i]%j!=0)able[j]=false;
		for(register int i=1;i<=n;++i)if(able[i])printf("%d ",i);
		putchar('\n');
	}while(--t);
	return 0;
}