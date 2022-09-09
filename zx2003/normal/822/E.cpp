#include<cstdio>
#include<cstring>
const int N=200010;
int n,x,i,g[N][105],j,k,T,m;
char s[N],*t;
inline void up(int&a,int b){if(a<b)a=b;}
inline int min(int a,int b){return a>b?b:a;}
inline void swap(int&a,int&b){static int t;t=a;a=b;b=t;}
namespace Sa{
	struct node{
		int a,b,i;
		bool operator<(const node&x)const{
			return a==x.a?b<x.b:a<x.a;
		}
	}e[N];
	int n,a[300]={0},b[300]={0},i,d,j,k,p,s;
	int sa[N],rk[N],hh[N];
	inline void getsa(char*c){
		static int f[N],g[N],h[N];
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
	int f[20][N],lo[N];
	inline void init(){
		register int i,j;
		for(i=1;i<n;++i)f[0][i]=hh[i];
		for(i=1;1<<i<=n;++i)
			for(j=1;j<=n-(1<<i);++j)
				f[i][j]=min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
		for(i=2,lo[1]=0;i<=n;++i){
			lo[i]=lo[i-1];
			if(1<<(lo[i-1]+1)<i)++lo[i];
		}
	}
	inline int lcp(int x,int y){
		static int l;x=rk[x],y=rk[y];
		if(x>y)swap(x,y);--y;l=lo[y-x+1];
		return min(f[l][x],f[l][y-(1<<l)+1]);
	}
}
inline int lcp(int x,int y){return Sa::lcp(x,y+n+1);}
int main(){
	//freopen("strings.in","r",stdin),freopen("strings.out","w",stdout);
	//scanf("%d",&T);
	T=1;
	while(T--){
		memset(g,0,sizeof g);
    	scanf("%d%s%d",&n,s+1,&m);s[n+1]='#';scanf("%s%d",t=s+n+2,&x);
    	Sa::getsa(s);Sa::init();
    	i=lcp(1,1);
    	g[lcp(1,1)][1]=i;
    	for(i=0;i<n;++i)
        	for(j=0;j<=x;++j){
            	up(g[i+1][j],g[i][j]);
            	if(g[i][j]<m)k=lcp(i+1,g[i][j]+1),up(g[i+k][j+1],g[i][j]+k);
        	}
    	for(i=0;i<=x;++i)if(g[n][i]==m)break;
    	puts(i<=x?"YES":"NO");
    }
    return 0;
}