#include <cstdio>
#include <cstring>
const int M=8,N=2e5+10;
const int rv[4]={0,2,1,3};
char s[2][N];int n,ans,a[2][N],nx[2][N],f[2][N][M];
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
int gd(int x,int d){return (x>>d)&1;}
int sd(int x,int d,int t){return x^((gd(x,d)^t)<<d);}
int calc(int i,int j){return a[i][j+1]+(a[i^1][j+1]<<1)+(a[i^1][j]<<2);}
int main(){
	scanf("%d %s %s",&n,s[0]+1,s[1]+1);
	for(int i=0;i<2;++i)for(int j=1;j<=n;++j)a[i][j]=s[i][j]^48;
	nx[0][n+2]=nx[1][n+2]=n+2,memset(f,0xc0,sizeof(f)),f[0][1][calc(0,1)]=0;
	for(int i=0;i<2;++i)for(int j=n+1;j;--j)nx[i][j]=a[i][j]?j:nx[i][j+1];
	for(int i=1;i<=n;++i){
		for(int j=4;j<8;++j){
			for(int t=0;t<2;++t){
				int w=f[t][i][j];
				cmax(f[t][i][j^4],w);
				if(j&1){
					cmax(f[t^1][i][sd(rv[j^4],1,0)],w+1);
					cmax(f[t][i+1][sd(calc(t,i+1),2,gd(j,1))],w+1);
				}
				else cmax(f[t^1][i][rv[j^4]],w+1);
			}
		}
		for(int j=0;j<4;++j){
			for(int t=0;t<2;++t){
				int w=f[t][i][j];
				if(j&1)cmax(f[t][i+1][sd(calc(t,i+1),2,gd(j,1))],w+1);
				if(j&2){
					int p=sd(calc(t^1,i+1),2,0),h=nx[t][i+2];
					if(h==i+2)cmax(f[t^1][i+1][sd(p,1,0)],w+1);
					else cmax(f[t^1][i+1][p],w+1);
					if(h<=n)cmax(f[t][h][calc(t,h)],w+1);
				}
				if(!j){
					int d1=nx[t][i+2],d2=nx[t^1][i+2],p1,p2;
					if(d1>n&&d2>n){cmax(ans,w);continue;}
					p1=d1-i,p2=d2-i+1;
					if(d1<=n)cmax(f[t][d1][calc(t,d1)],w+1);
					if(p2<p1)cmax(f[t^1][d2][calc(t^1,d2)],w+1);
					if(p2==p1)cmax(f[t^1][d2][sd(calc(t^1,d2),1,0)],w+1);
				}
			}
		}
	}
	printf("%d",ans);return 0;
}