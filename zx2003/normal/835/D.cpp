#include <algorithm>
#include <cstring>
#include <cstdio>
const int N=100010;
char c[N];
int n,i,sa[N],rk[N],hh[N],j,f[5005][5005],k,s[5005];
inline int min(int a,int b){
	return a>b?b:a;
}
namespace Sa{
	struct node{
		int a,b,i;
		bool operator<(const node&x)const{
			return a==x.a?b<x.b:a<x.a;
		}
	}e[N];
	int n,a[300]={0},b[300]={0},i,d,j,k,f[N],g[N],h[N],p,s,ff[20][N],lo[N];
	inline void getsa(char*c,int*sa,int*rk,int*hh){
		n=strlen(c+1);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		k=0;
		for(i=1;i<=n;++i)++a[c[i]];
		for(i=1;i<=150;++i)
			if(a[i])b[i]=b[i-1]+1;
				else b[i]=b[i-1];
		p=b[150];
		for(i=1;i<=n;++i)rk[i]=b[c[i]];
		for(;i<(n<<2);++i)rk[i]=0;
		for(d=0;p<n;++d){
			for(i=0;i<=p;++i)f[i]=0;
			for(i=1;i<=n;++i)++f[rk[i+(1<<d)]];
			for(i=1;i<=p;++i)f[i]+=f[i-1];
			for(i=1;i<=n;++i)
				g[f[rk[i+(1<<d)]]--]=i;
			for(i=0;i<=n;++i)f[i]=0;
			for(i=1;i<=n;++i)++f[rk[g[i]]];
			s=0;
			for(i=1;i<=p;++i)s+=f[i],f[i]=s-f[i];
			for(i=1;i<=n;++i)
				h[++f[rk[g[i]]]]=g[i];
			g[h[1]]=p=1;
			for(i=2;i<=n;++i)
				if(rk[h[i]]>rk[h[i-1]] || rk[h[i]+(1<<d)]>rk[h[i-1]+(1<<d)])g[h[i]]=++p;else g[h[i]]=p;
			for(i=1;i<=n;++i)rk[i]=g[i];
		}
		for(i=1;i<=n;++i)sa[rk[i]]=i;
		for(i=1;i<=n;hh[rk[i++]-1]=k)
			if(rk[i])for(k?k--:0,j=sa[rk[i]-1];c[i+k]==c[j+k];++k);
	}	
	inline void RMQ(){
		int l=n-1;
		for(i=1;i<=l;++i)ff[0][i]=hh[i];
		for(i=1;1<<i<=l;++i)
			for(int j=1;j<=l-(1<<i)+1;++j)ff[i][j]=min(ff[i-1][j],ff[i-1][j+(1<<(i-1))]);
		for(i=1;i<=l;++i)
			lo[i]=lo[i-1]+((1<<(lo[i-1]+1))<i);
	}
	inline int lcp(int a,int b){
		int x=rk[a],y=rk[b];
		if(x>y)i=x,x=y,y=i;
		--y;
		i=lo[y-x+1];
		return min(ff[i][x],ff[i][y-(1<<i)+1]);
	}
}
int buf[100];
inline void putint(int x){
	if(!x)putchar('0');
		else{
			int xb=0;
			for(;x;x/=10)buf[++xb]=x%10;
			for(;xb;--xb)putchar(buf[xb]+48);
		}
}
int main(){
	scanf("%s",c+1);
	n=strlen(c+1);
	for(i=1;i<=n;++i)c[n+i]=c[n-i+1];
	Sa::getsa(c,sa,rk,hh);
	Sa::RMQ();
	for(i=1;i<=n;++i)f[i][i]=1;
	for(i=1;i<n;++i)
		for(j=1;j<=n-i;++j){
			k=j+i;
			if(Sa::lcp(j,n+n-k+1)>i){
				if(i&1)f[j][k]=min(f[j][j+((i+1)>>1)-1],f[j+((i+1)>>1)][k])+1;
					else f[j][k]=min(f[j][j+(i>>1)-1],f[k-(i>>1)+1][k])+1;
			}
		}
	for(i=1;i<=n;++i)
		for(j=i;j<=n;++j)++s[f[i][j]];
	for(i=n;i;--i)s[i]+=s[i+1];
	for(i=1;i<=n;++i)putint(s[i]),putchar(' ');
	return 0;
}