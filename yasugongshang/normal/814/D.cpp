#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
const int N=1005;
int n,nextt[N<<1],son[N],rd[N],ed[N<<1],nedge,deep1[N],deep2[N];
struct data{
	int x,y,r;
}a[N];
long long ans;
double eps=1e-13;
inline long long sqr(int x){
	return (long long)x*x;
}
inline double juli(int c,int d){
	return sqrt(sqr(a[c].x-a[d].x)+sqr(a[c].y-a[d].y));
}
inline void aedge(int a,int b){//cout<<a<<" "<<b<<" "<<endl;
	nextt[++nedge]=son[a]; rd[b]++;
	son[a]=nedge;
	ed[nedge]=b;
}
inline void dfs(int p){int zs;
	if((deep1[p]&1)==(deep2[p]&1)){
		zs=1; if(!(deep1[p]&1))ans+=sqr(a[p].r); else ans-=sqr(a[p].r);
	}else{
		if(deep1[p]&1)zs=2; else zs=1; ans+=sqr(a[p].r);
	}//cout<<p<<" "<<ans<<" "<<deep1[p]<<" "<<deep2[p]<<endl;
	for(int i=son[p];i;i=nextt[i]){
		deep1[ed[i]]=deep1[p]; deep2[ed[i]]=deep2[p];
		if(zs==1)deep1[ed[i]]++; else deep2[ed[i]]++;
		dfs(ed[i]);
	}
}
inline bool cmp(data a,data b){
	return a.r>b.r;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].x=read(); a[i].y=read(); a[i].r=read();
	}
	sort(&a[1],&a[n+1],cmp);//for(int i=1;i<=n;i++)cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].r<<endl;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(!rd[j]){
		if(juli(j-i,j)+a[j].r<a[j-i].r+eps)aedge(j-i,j);
	}
	for(int i=1;i<=n;i++)if(!rd[i])dfs(i);
	printf("%.8lf\n",ans*M_PI);
}