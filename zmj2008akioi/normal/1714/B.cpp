#include <cstdio>
const int N=1e6+10;
int T,n,a[N];
bool vis[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)vis[i]=false;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		a[0]=a[1];
		for(int i=n;~i;--i){
			if(vis[a[i]]){printf("%d\n",i);break;}
			vis[a[i]]=true;
		}
	}
	return 0;
}