#include <cstdio>
#include <cstring>
int t,n,ans,arr[150010],bkt[150010];
inline int max(int x,int y){return x>y?x:y;}
int main(){
	scanf("%d",&t);
	do{
		scanf("%d",&n);
		ans=-1;
		memset(bkt,0,sizeof(bkt));
		for(register int i=1;i<=n;++i){
			scanf("%d",&arr[i]);
			if(bkt[arr[i]])ans=max(ans,n-(i-bkt[arr[i]]));
			bkt[arr[i]]=i;
		}
		printf("%d\n",ans);
	}while(--t);
	return 0;
}