#include <cstdio>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
int o[200000],w1[10],w2[10],x[200000],y[200000],z[200000];
int h,i,j,k,l,m,n,t,u,v;
double p,q;
inline int Rand(){
	return rand()<<15|rand();
}
int main(){
	srand((int) time(0));
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	for (h=1;h<=10;h++){
		l=n;
		for (i=1;i<=n;i++)
			o[i]=i;
		for (j=1,k=m;(j<=80) && (k<l);j++){
			u=o[Rand()%l+1],v=o[Rand()%l+1];
			if (1LL*x[u]*y[v]==1LL*y[u]*x[v])
				continue;
			q=1.0*(1LL*x[u]*z[v]-1LL*x[v]*z[u])/(1LL*x[v]*y[u]-1LL*x[u]*y[v]);
			p=(-q*y[u]-z[u])/x[u];
			t=0;
			for (i=1;i<=l;i++)
				if (fabs(x[o[i]]*p+y[o[i]]*q+z[o[i]])<1e-12)
					t++;
			if (t>=(l-1)/k+1){
				t=0;
				for (i=1;i<=l;i++)
					if (fabs(x[o[i]]*p+y[o[i]]*q+z[o[i]])>1e-12)
						t++,o[t]=o[i];
				l=t,w1[k]=u,w2[k]=v,k--;
			}
		}
		if (k>=l){
			puts("YES");
			printf("%d\n",m-k+l);
			for (i=k+1;i<=m;i++)
				printf("%d %d\n",w1[i],w2[i]);
			for (i=1;i<=l;i++)
				printf("%d %d\n",o[i],-1);
			return 0;
		}
	}
	puts("NO");
}