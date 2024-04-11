#include <cstdio>
const int N=2e3+10;
int T,n,ans,a[N];
void cmin(int &x,int y){if(x>y)x=y;}
void cmax(int &x,int y){if(x<y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);int m1=0,m2=1000,ans=0;
		for(int i=0;i<n;++i)scanf("%d",&a[i]);a[n]=a[0];
		for(int i=0;i<n;++i)cmax(ans,a[i]-a[i+1]);
		for(int i=0;i<n-1;++i)cmin(m2,a[i]);
		for(int i=1;i<n;++i)cmax(m1,a[i]);
		cmax(ans,a[n-1]-m2),cmax(ans,m1-a[0]);
		printf("%d\n",ans);
	}
	return 0;
}