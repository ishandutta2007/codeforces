//zx2003 tian xia zui cai
#include<bits/stdc++.h>
using namespace std;
const int N=11e5;
int n,m,kk,a[N],b[N],i,j,k,l,mm,S,T,ss[N],tt[N],ans,l1,r1;
inline void upi(int&a,const int&b){a>b?a=b:0;}
char cc[25];
inline void in(int&x){
	scanf("%s",cc);
	for(i=0;i<kk;++i)x|=cc[i]-'0'<<i;
}
int f[N][25],p[25];
int main(){
	scanf("%d%d%d",&n,&m,&kk);in(S);in(T);
	for(i=0;i<1<<kk;++i)for(j=0;j<25;++j)f[i][j]=N;//yi kai shi fu cheng 99 le,ying ying ying
	ans=kk+1;
	for(i=1;i<=n;++i)scanf("%d%d",a+i,b+i);
	ss[n+1]=S;tt[n+1]=T;
	for(i=0;i<kk;++i)p[i]=i;
	for(i=n;i;--i){
		int x,y;
		for(j=0;j<kk;++j){
			if(p[j]==a[i]-1)x=j;
			if(p[j]==b[i]-1)y=j;
		}
		swap(p[x],p[y]);
		for(j=0;j<kk;++j)ss[i]|=(S>>p[j]&1)<<j,tt[i]|=(T>>p[j]&1)<<j;
	}
	for(i=1;i<=n+1;++i)upi(f[ss[i]][0],i);
	for(i=2;i<=1<<kk;i<<=1){
		for(j=0,mm=i>>1;j<1<<kk;j+=i)for(k=0;k<mm;++k){
			for(l=0;l<=kk;++l)upi(f[j+k][l+1],f[j+k+mm][l]);
			for(l=0;l<=kk;++l)upi(f[j+k+mm][l+1],f[j+k][l]);
		}
	}
	for(i=1;i<=n+1;++i)for(j=0;j<=kk;++j)if(f[tt[i]][j]<=i-m && j<=ans){
if(j==0 && i==1001)
++j,--j;
		ans=j,l1=f[tt[i]][j],r1=i-1;
	}
	printf("%d\n%d %d\n",kk-ans,l1,r1);
//	printf("%d\n%d %d\n",kk-ans,1,1);
}