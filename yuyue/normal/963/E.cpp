#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#pragma GCC optimize(2)
#pragma GCC target("avx")
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int mod=1e9+7;
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
int n,R,tt;
LL a[4];
#define id(x,y) bd[x+R][y+R]
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
const int M=7850;
int c[M][M];
LL b[M];
int d,vis[M],ps[M],bd[200][200];
void gauss(){
	d=2*R;
	F(i,1,tt){
		for (int j=i;j<=min(tt,i+d);j++){
			if (c[j][i]){
				if (i^j) swap(c[j],c[i]);
				break;
			}
		}
		LL iv=mod-fast(c[i][i],mod-2);
		for (int j=i+1;j<=min(tt,i+d);j++){
			LL t=iv*c[j][i]%mod;
			F(x,i,min(i+2*d,tt)) c[j][x]=(c[j][x]+(LL)t*c[i][x])%mod;
			b[j]=(b[j]+b[i]*t)%mod;
		}
	}
	DF(i,tt,1){
		F(j,max(1,i-d),min(tt,i+d)){
			if (j^i) b[i]=(b[i]+(LL)(mod-c[i][j])*b[j])%mod;
		}
		b[i]=b[i]*fast(c[i][i],mod-2)%mod;
	}
}
int main(){
	R=read();
	int sm=0;
	F(i,0,3) a[i]=read(),sm+=a[i];
	sm=fast(sm,mod-2);
	F(i,0,3) a[i]=a[i]*sm%mod;
	F(i,-R,R){
		F(j,-R,R){
			if (i*i+j*j<=R*R){
				id(i,j)=++tt;
			}
		}
	}
//	cout<<tt<<"\n";
	F(i,-R,R){
		F(j,-R,R){
			if (i*i+j*j<=R*R){	
				int u=id(i,j);
				c[u][u]=1;
				F(k,0,3){
					int nx=i+dx[k],ny=j+dy[k];
					if (nx*nx+ny*ny<=R*R){
						int v=id(nx,ny);
						c[u][v]=mod-a[k];
					}
				}
				b[u]=1;
			}
		}
	}
	gauss();
	cout<<b[id(0,0)]<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/