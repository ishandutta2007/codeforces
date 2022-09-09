#include<bits/stdc++.h>
using namespace std;
const int mo=998244353,N=22;
inline void add(int&x,const int&y){x+=y-mo;x+=x>>31&mo;}
int main(){
	static int n,m,x[9],y[9],i,j,sx,sy,j1,j2,j3,j4,f[35][2][2][N][N][N][N],z;
	static int nx[33],ny[33],px[33],py[33],nxx,nyy,pxx,pyy;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i)scanf("%d%d",x+i,y+i);
	for(i=0;i<1<<n;++i)for(j=0;j<n;++j)if(i>>j&1)(x[j]>0?px:nx)[i]+=abs(x[j]),(y[j]>0?py:ny)[i]+=abs(y[j]);
	nxx=max(1,nx[i-1]);nyy=max(1,ny[i-1]);pxx=max(1,px[i-1]);pyy=max(1,py[i-1]);
	f[0][0][0][0][0][0][0]=1;
	for(i=0;i<30;++i)for(sx=0;sx<2;++sx)for(sy=0;sy<2;++sy)
		for(j1=0;j1<nxx;++j1)for(j2=0;j2<nyy;++j2)for(j3=0;j3<pxx;++j3)for(j4=0;j4<pyy;++j4)
			if(z=f[i][sx][sy][j1][j2][j3][j4])for(j=0;j<1<<n;++j){
		int k1=j1+nx[j],k2=j2+ny[j],k3=j3+px[j],k4=j4+py[j],b1=k1&1,b2=k2&1,b3=k3&1,b4=k4&1,mb=m>>i&1;
		if(b1==b3 && b2==b4)add(f[i+1][b3==mb?sx:b3>mb][b4==mb?sy:b4>mb][k1>>1][k2>>1][k3>>1][k4>>1],z);
	}
	printf("%d\n",(f[i][0][0][0][0][0][0]+mo-1)%mo);
	return 0;
}