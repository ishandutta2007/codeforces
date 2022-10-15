#include <bits/stdc++.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define ll long long
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;	
}
const int N=2e5+5;
int n,nn,m,t,h[N];
ll mn[N][18],mx[N][18],z1[N],z2[N],d[N];
inline int chkmx(int x,int y){return z1[x]>z1[y]?x:y;}
inline int chkmn(int x,int y){return z2[x]<z2[y]?x:y;}
inline void pre(){
	for(int i=1;i<=nn;i++)mx[i][0]=mn[i][0]=i;
	for(int j=1;j<=t;j++)
		for(int i=1;i<=nn-(1<<j)+1;i++)
			mn[i][j]=chkmn(mn[i][j-1],mn[i+(1<<(j-1))][j-1]),
			mx[i][j]=chkmx(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
}
inline int qmx(int x,int y){
	if(x>y)return 0;int k=log2(y-x+1);
	return chkmx(mx[x][k],mx[y-(1<<k)+1][k]);	
}
inline int qmn(int x,int y){
	if(x>y)return 0;int k=log2(y-x+1);
	return chkmn(mn[x][k],mn[y-(1<<k)+1][k]);	
}
int main(){
	n=read(),m=read(),nn=n<<1,t=log2(nn);
	for(int i=1;i<=n;i++)d[i%n+1]=d[i%n+1+n]=read();
	for(int i=1;i<=n;i++)h[i]=h[i+n]=read()*2;
	for(int i=1;i<=nn;i++)d[i]+=d[i-1];
	z1[0]=-1e18,z2[0]=1e18;
	for(int i=1;i<=nn;i++)z1[i]=d[i]+h[i],z2[i]=d[i]-h[i];
	pre();
	while(m--){
		int x=read()-1,y=read()+1;
		if(x<y)x+=n;swap(x,y);
		int maxn=qmx(x,y),minx=qmn(x,maxn);ll ans=0;
		if(maxn==minx)ans=max(z1[qmx(maxn+1,y)]-z2[minx],z1[maxn]-z2[qmn(x,minx-1)]);
		else ans=z1[maxn]-z2[minx];
		printf("%lld\n",ans);
	}
	return 0;	
}