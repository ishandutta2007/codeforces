#include <cstdio>
#include <algorithm>
using namespace std;
const int N=200000;
const int o=1000000007;
struct point{
	int x,y;
	inline bool operator < (const point t) const{
		if (x!=t.x) return x<t.x;
		return y<t.y;
	}
};
point p[3000];
int fac[300000],inv[300000];
int f[3000][30],h[3000][30];
int i,j,k,l,m,n,s,t;
inline int power(int x,int y){
    int s=1;
    for (;y;y/=2,x=1ll*x*x%o)
        if (y&1) s=1ll*s*x%o;
    return s;
}
void pre_C(){
	fac[0]=1;
	for (i=1;i<=N;i++)
		fac[i]=1LL*fac[i-1]*i%o;
	inv[N]=power(fac[N],o-2);
	for (i=N-1;i>=0;i--)
		inv[i]=1LL*inv[i+1]*(i+1)%o;
}
int C(int x,int y){
	return 1LL*inv[y]*inv[x-y]%o*fac[x]%o;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for (i=1;i<=k;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+k+1);
	k++,p[k].x=n,p[k].y=m;
	pre_C();
	for (i=1;i<=k;i++)
		for (j=0;j<=25;j++)
		{
			f[i][j]=C(p[i].x-1+p[i].y-1,p[i].x-1);
			if (j<25)
				for (l=1;l<i;l++)
					if ((p[l].x<=p[i].x) && (p[l].y<=p[i].y))
						f[i][j]=(f[i][j]-1LL*C(p[i].x-p[l].x+p[i].y-p[l].y,p[i].x-p[l].x)*f[l][j]%o+o)%o;
			for (l=0;l<j;l++)
				f[i][j]=(f[i][j]-f[i][l]+o)%o;
		}
	for (j=0;j<=25;j++)
		s=(s+1LL*f[k][j]*t)%o,t=t-t/2;
	s=1LL*s*inv[n+m-2]%o*fac[n-1]%o*fac[m-1]%o;
	printf("%d",s);
}