#include<stdio.h>
#include<algorithm>
#define abs __builtin_llabs
long long a[3000002][3],g[3000002][3],h[3000002],l,r,n,m,p[3000002];char c[5]="LUDR";
int main(){
	scanf("%lld%lld",&n,&m);a[0][0]=a[0][1]=a[0][2]=0;
	for(long long i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		a[i][1]+=a[i][2],a[i][2]=a[i][1]-a[i][2]*2;long long hdhd,AK,IOI;
		if((hdhd=abs(a[i][1]-a[i-1][1]))>(AK=a[i][0]-a[i-1][0])||(IOI=abs(a[i][2]-a[i-1][2]))>AK||((hdhd^AK|IOI^AK)&1))return puts("NO")&0;
	}for(long long i=0;i<=n;i++)g[i][1]=-(a[i][0]/m),g[i][0]=a[i][0]%m,g[i][2]=a[i][1],h[i]=i;
	std::sort(h,h+n+1,[](long long p,long long q){return g[p][0]==g[q][0]?g[p][1]<g[q][1]:g[p][0]<g[q][0];});l=-m;r=m;
	g[n+1][0]=m;g[n+1][1]=1;g[n+1][2]=0;h[n+1]=n+1;
	for(long long i=1;i<=n+1;i++){
		long long a=g[h[i]][1]-g[h[i-1]][1],b=g[h[i]][2]-g[h[i-1]][2],c=g[h[i]][0]-g[h[i-1]][0];
		if(a<0)a=-a,b=-b;long long L=-c-b,R=c-b;
		if(a){
			long long u=L/a,v=R/a;u+=u*a<L,v-=v*a>R;
			if(l<u)l=u;if(r>v)r=v;
		}
	}if((l^m)&1)l++;if((r^m)&1)r--;
	if(l>r)return puts("NO")&0;
	for(long long i=0;i<=n;i++)g[i][1]=g[i][1]*l+g[i][2];g[n+1][0]=m;g[n+1][1]=l;h[n+1]=n+1;
	for(long long i=0,j=0,d=0;i<m;i++){
		while(g[h[j+1]][0]==i)j++;
		if(g[h[j+1]][1]-d==i-g[h[j+1]][0])d--;
		else p[i]|=1,d++;
	}for(long long i=0;i<=n;i++)g[i][1]=-(a[i][0]/m),g[i][0]=a[i][0]%m,g[i][2]=a[i][2],h[i]=i;
	std::sort(h,h+n+1,[](long long p,long long q){return g[p][0]==g[q][0]?g[p][1]<g[q][1]:g[p][0]<g[q][0];});l=-m;r=m;
	g[n+1][0]=m;g[n+1][1]=1;g[n+1][2]=0;h[n+1]=n+1;
	for(long long i=1;i<=n+1;i++){
		long long a=g[h[i]][1]-g[h[i-1]][1],b=g[h[i]][2]-g[h[i-1]][2],c=g[h[i]][0]-g[h[i-1]][0];
		if(a<0)a=-a,b=-b;long long L=-c-b,R=c-b;
		if(a){
			long long u=L/a,v=R/a;u+=u*a<L,v-=v*a>R;
			if(l<u)l=u;if(r>v)r=v;
		}
	}if((l^m)&1)l++;if((r^m)&1)r--;
	if(l>r)return puts("NO")&0;
	for(long long i=0;i<=n;i++)g[i][1]=g[i][1]*l+g[i][2];g[n+1][0]=m;g[n+1][1]=l;h[n+1]=n+1;
	for(long long i=0,j=0,d=0;i<m;i++){
		while(g[h[j+1]][0]==i)j++;
		if(g[h[j+1]][1]-d==i-g[h[j+1]][0])d--;
		else p[i]|=2,d++;
	}for(long long i=0;i<m;i++)putchar(c[p[i]]);
}