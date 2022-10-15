#include <cstdio>
const int N=1e6+10;
int T,n,xl,xr,yl,yr,a[N];
void cmin(int &x,int y){if(x>y)x=y;}
void cmax(int &x,int y){if(x<y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		xl=xr=yl=yr=0;
		for(int x,y,i=1;i<=n;++i){
			scanf("%d %d",&x,&y);
			if(!y)cmin(xl,x),cmax(xr,x);
			else cmin(yl,y),cmax(yr,y);
		}
		printf("%d\n",(xr-xl+yr-yl)<<1);
	}
	return 0;
}