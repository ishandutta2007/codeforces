#include<cstdio>
#include<ctime>
const int N=100005;
int n,i,p,g,a[N],w,x,y,z;
char c[N];
inline bool isp(int p){
	for(register int i=2;i*i<=p;++i)if(p%i==0)return 0;
	return 1;
}
inline int pow(int x,int y,int p){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%p)if(y&1)ans=1ll*ans*x%p;return ans;
}
inline int getg(int p){
	register int g=2,i;
	for(;;++g){
		for(i=1;i<=w;++i)
			if(pow(g,a[i],p)==1)break;
		if(i>w)return g;
	}
}
int main(){
	scanf("%d%s",&n,c+1);
	for(i=1;i<=n;++i)c[i]^=48;p=1;
	while(clock()<800){
		for(p+=n;!isp(p);p+=n);
		w=0;
		for(i=2;i*i<=p-1;++i)if((p-1)%i==0)a[++w]=i,a[++w]=(p-1)/i;
		g=getg(p);
		z=pow(g,(p-1)/n,p);
		for(i=x=1,y=0;i<=n;++i,x=1ll*x*z%p)
			y=(y+1ll*x*c[i])%p;
		if(y)return puts("NO"),0;
	}
	puts("YES");
	return 0;
}