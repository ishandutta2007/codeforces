#include <cstdio>
#include <cstring>
typedef long long LL;
const int N=5e3+10;
const LL inf=0x3f3f3f3f3f3f3f3f;
int T,n,x,y;LL rec[2][2],f[N][2],g[N][2];
bool a[N],b[N];char s[N];
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
void rd(bool *a){
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)a[i]=s[i]^48;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&x,&y),rd(a),rd(b);
		for(int i=1;i<=n;++i)a[i]^=b[i];
		memset(f,0x3f,sizeof(f)),f[0][0]=0;
		for(int i=1;i<=n;++i){
			memset(g,0x3f,sizeof(g));
			rec[0][0]=rec[0][1]=rec[1][0]=rec[1][1]=inf;
			for(int j=n;~j;--j){
				for(int k=0;k<2;++k)cmin(rec[k][j&1],f[j][k]+(LL)j*y);
				for(int k=0;k<2;++k){
					for(int w=0;w<1+(i>2);++w){
						int v=w*y;
						cmin(g[j+k+w][a[i]^w],rec[k][j&1]-(LL)j*y+v);
						cmin(g[j+(k^1)+w][a[i]^1^w],rec[k][j&1]+x-(LL)j*y+v);
						cmin(g[j+k+w][a[i]^1^w],rec[k][(j&1)^1]-(LL)j*y+v);
						cmin(g[j+(k^1)+w][a[i]^w],rec[k][(j&1)^1]+x-(LL)j*y+v);
					}
				}
			}
			memcpy(f,g,sizeof(f));
		}
		if(f[0][0]==inf)puts("-1");
		else printf("%lld\n",f[0][0]);
	}
	return 0;
}