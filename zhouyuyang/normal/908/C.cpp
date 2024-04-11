#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n,r,a[1010];
double b[1010];
inline double sqr(double x){return x*x;}
int main()
{
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),b[i]=r;
		for(int j=1;j<i;j++)if(a[i]-a[j]<=2*r)b[i]=max(b[i],b[j]+2*sqrt(sqr(r)-sqr((double)(a[i]-a[j])/2)));
		printf("%.7lf ",b[i]);
	}
	return 0;
}