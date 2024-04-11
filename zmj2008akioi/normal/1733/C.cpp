#include <cstdio>
const int N=1e5+10;
int T,n,m,x,top,a[N],l[N],r[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),m=top=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if((a[i]&1)==(a[1]&1))x=i;
		}
		for(int i=1;i<x;++i)if((a[i]&1)==(a[x]&1))++top,l[top]=i,r[top]=x;
		for(int i=2;i<=n;++i)if((a[i]&1)^(a[1]&1))++top,l[top]=1,r[top]=i;
		printf("%d\n",top);for(int i=1;i<=top;++i)printf("%d %d\n",l[i],r[i]);
	}
	return 0;
}