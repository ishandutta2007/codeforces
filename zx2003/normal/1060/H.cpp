#include<bits/stdc++.h>
using namespace std;
const int N=15;
int d,mo,i,j,k,C[N][N],a[N][N],v[N],c,x;
int poww(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
void gauss(){
	for(i=0;i<=d;++i){
		for(j=i;!a[j][i];++j);if(j>i){for(k=0;k<=d;++k)swap(a[j][k],a[i][k]);swap(v[j],v[i]);}
		for(j=0;j<=d;++j)if(j!=i){
			x=1ll*poww(a[i][i],mo-2)*(mo-a[j][i])%mo;
			for(k=0;k<=d;++k)a[j][k]=(a[j][k]+1ll*x*a[i][k])%mo;
			v[j]=(v[j]+1ll*x*v[i])%mo;
		}
	}
	for(i=0;i<=d;++i)v[i]=1ll*v[i]*poww(a[i][i],mo-2)%mo;
}
int be=10,one=be-1,zero=be-2;
void add(int x,int y,int z){printf("+ %d %d %d\n",x,y,z);}
void powe(int x){printf("^ %d %d\n",x,x);}
void getzero(int x){
	int v=mo-1;
	for(;v;v>>=1,add(be,be,be))if(v&1)add(be,zero,zero);
}
void mul(int x,int v){
	add(x,zero,be);
	add(zero,zero,x);
	for(;v;v>>=1,add(be,be,be))if(v&1)add(x,be,x);
}
int be2=100;
void sqr(int x){
	add(zero,x,be2);
	for(i=1;i<=d;++i)add(one,be2+i-1,be2+i);
	for(i=0;i<=d;++i)powe(be2+i),mul(be2+i,v[i]);
	add(zero,zero,x);
	for(i=0;i<=d;++i)add(x,be2+i,x);
}
int main(){
	scanf("%d%d",&d,&mo);
	for(int i=**C=1;i<N;++i)for(int j=*C[i]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	for(c=0;c<=d;++c)for(i=0;i<=d;++i)a[c][i]=1ll*C[d][c]*poww(i,d-c)%mo;v[2]=1;
	gauss();
	getzero(zero);
	add(1,2,3);sqr(1);sqr(2);sqr(3);
	mul(1,mo-1);mul(2,mo-1);add(1,2,4);add(3,4,5);
	mul(5,poww(2,mo-2));puts("f 5");
	return 0;
}