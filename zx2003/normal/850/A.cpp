#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=1005;
struct point{
	int a,b,c,d,e;
	void got(){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	}
	bool operator!=(point x){
		return a!=x.a || b!=x.b || c!=x.c || d!=x.d || e!=x.e;
	}
}a[N];
struct vec{
	int a,b,c,d,e;
}z;
vec operator-(point a,point b){
	return (vec){b.a-a.a,b.b-a.b,b.c-a.c,b.d-a.d,b.e-a.e};
}
int operator*(vec a,vec b){
	return a.a*b.a+a.b*b.b+a.c*b.c+a.d*b.d+a.e*b.e;
}
int n,i,j,k,ans[N],xb;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)a[i].got();
	if(n>50)return puts("0"),0;
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j)if(a[i]!=a[j]){
			z=a[j]-a[i];
			for(k=1;k<=n;++k)
				if(a[j]!=a[k] && a[k]!=a[i] && z*(a[k]-a[i])>0)break;
			if(k<=n)break;
		}
		if(j>n)ans[++xb]=i;
	}
	printf("%d\n",xb);
	for(i=1;i<=xb;++i)printf("%d\n",ans[i]);
	return 0;
}