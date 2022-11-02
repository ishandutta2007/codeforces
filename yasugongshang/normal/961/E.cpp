#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair

#define int long long
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x=0; char ch=gc(); bool positive=1;
	for (;!isdigit(ch);ch=gc())if(ch=='-')positive=0;
	for (;isdigit(ch);ch=gc())x=x*10+ch-'0';
	return positive?x:-x;
}
inline void write(int a){
    if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	if(a<0){
		a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=1000005;
int n,a[N],ff[N],last[N],v[N][2],kk,ans;
void upd(int x,int y){for(;x<N;x+=x&(-x))ff[x]+=y;}
int find(int x){int ans=0;for (;x;x-=x&(-x))ans+=ff[x];return ans;}
void add(int x,int y){v[++kk][0]=last[x];v[kk][1]=y;last[x]=kk;}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=min(n,read()),add(a[i],i),ans-=a[i]>=i;
	for(int i=1;i<=n;i++){
		upd(1,1);upd(a[i]+1,-1);
		for(int k=last[i];k;k=v[k][0])ans+=find(v[k][1]);
	}
	writeln(ans/2);
}