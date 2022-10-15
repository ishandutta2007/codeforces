#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
int H,M;
int g[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
inline bool pd(int h,int m){
	int x=g[h/10],y=g[h%10],z=g[m/10],w=g[m%10];
	if(z==-1 || y==-1 || x==-1 || w==-1)return 0;
	int h1=w*10+z,m1=y*10+x;
	if(0<=h1 && h1<H && 0<=m1 && m1<M){
		printf("%02d:%02d\n",h,m);
		return 1;
	}
	return 0;
}
int h,m;
inline void work(){
	H=read(),M=read(),h=read(),m=read();bool fir=0;
	for(int j=m;j<M;j++)if(pd(h,j))return;
	for(int i=(h+1)%H;i!=h;(++i)%=H)
		for(int j=0;j<M;j++)if(pd(i,j))return;
	for(int j=0;j<m;j++)if(pd(h,j))return;
	puts("nmsl"); 
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}