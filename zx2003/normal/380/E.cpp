#include<bits/stdc++.h>
using namespace std;
const int N=300010;
int n,b[N],i,j,l[N],r[N],u,v,p[N],k;
double x,y,z,ans;
bool cmp(int x,int y){
	return b[x]<b[y];
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",b+i);
		l[i]=i-1;
		r[i]=i+1;
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;++i){
		x=y=0;
		z=1;
		u=v=k=p[i];
		for(j=1;j<=45;++j){
			if(u)x+=(u-l[u])*z,u=l[u];
			if(v<=n)y+=(r[v]-v)*z,v=r[v];
			z/=2;
		}
		l[r[k]]=l[k];
		r[l[k]]=r[k];
		ans+=x*y*b[k]/2;
	}
	printf("%.6f\n",ans/n/n);
	return 0;
}