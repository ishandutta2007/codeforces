#include<bits/stdc++.h>
using namespace std;
const int N=14e4;
int n,k,a,i,j,l,f[N*2][2][2],x,y,u,v,b[N];
int main(){
	scanf("%d%d",&n,&k);for(i=1;i<=k;++i)scanf("%d",&a),b[a-1]=1;
	for(i=(1<<n)-1;i>=1<<n-1;--i){
		x=b[(i<<1)-(1<<n)];y=b[(i<<1|1)-(1<<n)];
		if(x==y)for(j=0;j<2;++j)for(l=0;l<2;++l)f[i][j][l]=j==x && l==x?x:-(1<<25);
			else for(j=0;j<2;++j)for(l=0;l<2;++l)f[i][j][l]=j!=l?1:-(1<<25);
	}
	for(;i;--i){
		int i1,i2,i3,i4,i5,i6,i7;
		for(i1=0;i1<2;++i1)for(i2=0;i2<2;++i2)f[i][i1][i2]=-(1<<25);
		for(int i1=0;i1<2;++i1)
		for(int i2=0;i2<2;++i2)
		for(int i3=0;i3<2;++i3)
		for(int i4=0;i4<2;++i4)
		for(int i5=0;i5<2;++i5)
		for(int i6=0;i6<2;++i6)
		for(int i7=0;i7<2;++i7){
			int w=f[i<<1][i1][i2]+f[i<<1|1][i3][i4];
			auto opt=[&](int&x,int&y,int o){w+=x|y;if(o==1)swap(x,y);};
			x=i1;y=i3;opt(x,y,i5);
			u=i2;v=i4;opt(u,v,i6);
			opt(y,u,i7);
			f[i][x][y]=max(f[i][x][y],w);
		}
	}
	x=0;
	for(i=0;i<2;++i)for(j=0;j<2;++j)x=max(x,f[1][i][j]);
	printf("%d\n",x+(k>0));
	return 0;
}