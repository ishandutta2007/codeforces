#include <cstdio>
int T,n,x,y;
template<typename T>void swp(T &x,T &y){T z=x;x=y;y=z;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&x,&y);if(x>y)swp(x,y);
		if((!x&&!y)||x||(n-1)%y!=0){puts("-1");continue;}
		for(int i=2;i<=n;i+=y)for(int j=i;j<i+y;++j)printf("%d ",i);
		putchar('\n');
	}
	return 0;
}