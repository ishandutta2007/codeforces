#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 101000
typedef double ldb;
ldb ans=1e20,px[maxn],py[maxn];
int n;
int nxt(int x){
	return x==n?1:x+1;
}
ldb cross(ldb x1,ldb y1,ldb x2,ldb y2){
	return x1*y2-y1*x2;
}
ldb dist(ldb x1,ldb y1){
	return sqrt(x1*x1+y1*y1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lf%lf",&px[i],&py[i]);
	for(int i=1;i<=n;++i){
		int j=nxt(i),k=nxt(j);
		ans=min(ans,fabs(cross(px[i]-px[j],py[i]-py[j],px[k]-px[j],py[k]-py[j]))/2/
				dist(px[i]-px[k],py[i]-py[k]));
	}
	printf("%.9lf",ans);
}