#include <cstdio>
const int N=1e6+10;
int T,n,z,a[N];
inline void cmax(int &x,int y){if(x<y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&z);int ans=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),cmax(ans,z|a[i]);
		printf("%d\n",ans);
	}
	return 0;
}