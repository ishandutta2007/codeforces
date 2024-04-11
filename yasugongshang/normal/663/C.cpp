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
const int N=200005;
int n,m,sz[N],size[N],father[N],ans,a[N],b[N],c[N],vvv[N];
inline int getfather(int x){
	return  father[x]==x?x:father[x]=getfather(father[x]);
}
inline void uni(int a,int b){
	int t1=getfather(a),t2=getfather(b);
	father[t1]=t2; 
}
inline int calc(){
	int ans=0;
	memset(sz,0,sizeof(sz)); memset(size,0,sizeof(size));
	for(int i=1;i<=2*n;i++)father[i]=i;
	for(int i=1;i<=m;i++){
		if(c[i]){uni(a[i],b[i]); uni(a[i]+n,b[i]+n);}else{uni(a[i],b[i]+n); uni(a[i]+n,b[i]);}
	}
	for(int i=1;i<=2*n;i++){
		sz[getfather(i)]++; size[getfather(i)]+=i>n;
	}
	for(int i=1;i<=n;i++)if(getfather(i)==getfather(i+n)){
		ans+=1e9; return ans;
	}
	else{
		//if(getfather(i)==i)cout<<i<<" "<<size[i]<<" "<<sz[i]<<endl;
		//if(getfather(i+n)==i+n)cout<<i<<" "<<size[i+n]<<" "<<sz[i+n]<<endl;
		if(getfather(i)==i){
			if(size[i]<sz[i]-size[i])vvv[i]=1; else vvv[i]=0; ans+=min(size[i],sz[i]-size[i]);
		}
		if(getfather(i+n)==i+n){
			if(size[i+n]<=sz[i+n]-size[i+n])vvv[i+n]=1; else vvv[i+n]=0; ans+=min(size[i+n],sz[i+n]-size[i+n]);
		}
	}
	return ans;
}
int main(){
	n=read(); m=read();
	for(int i=1;i<=2*n;i++)father[i]=i; 
	for(int i=1;i<=m;i++){
		a[i]=read(); b[i]=read(); c[i]=(getchar()=='B'); 
	}
	int ans=calc(); int tt=ans; //writeln(ans);
	for(int i=1;i<=m;i++)c[i]^=1;
	ans=min(ans,calc());
	if(ans>=1e9)puts("-1"); else{
		if(ans==tt)for(int i=1;i<=m;i++)c[i]^=1;
		calc();
		writeln(ans/2);
		for(int i=1;i<=n;i++){
			if(vvv[getfather(i+n)]){
				write(i); putchar(' ');
			}
		}
	}
}