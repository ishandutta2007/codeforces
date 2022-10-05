#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
using namespace std;

int n,a[1010][4],c[5],f[666],g[666];

int U(int &x,int y){ x=min(x,y); }
#define has(s,t,u,v) s+t*5+u*25+v*125
#define C(x,y) (x?x+1:a[i][y])
#define D(x,y,z) (y<1&&y+z>0&&x<=z?0:x)

int main(){
	cin>>n>>c[1]>>c[2]>>c[3]>>c[4];
	rep(i,0,3){
		getchar();
		rep(j,1,n) a[j][i]=getchar()=='*';
	}
	memset(f,33,sizeof f); f[0]=0;
	rep(i,1,n){
		memset(g,33,sizeof g);
		rep(s,0,3) rep(t,0,3) rep(u,0,3) rep(v,0,3)
			U(g[has(C(s,0),C(t,1),C(u,2),C(v,3))],f[has(s,t,u,v)]);
		memcpy(f,g,sizeof g);
		rep(j,0,3) rep(k,1,min(4-j,i)) rep(s,0,4) rep(t,0,4) rep(u,0,4) rep(v,0,4)
			U(f[has(D(s,j,k),D(t,j-1,k),D(u,j-2,k),D(v,j-3,k))],f[has(s,t,u,v)]+c[k]);
	}
	cout<<f[0];
}