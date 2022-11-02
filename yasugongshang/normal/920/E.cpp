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
#define getchar gc
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
int n,m,tong[N],father[N],size[N],q[N],tot,vis[N];
inline int getfather(int x){
	return father[x]==x?x:father[x]=getfather(father[x]);
}
vector<int> v[N];
int main(){
	n=read(); m=read();
	while(m--){
		int s=read(),t=read(); if(s>t)swap(s,t);
		v[t].push_back(s);
	}
	for(int i=1;i<=n;i++){
		father[i]=i; size[i]=1;
		for(int j=1;j<=tot;j++)vis[j]=tong[q[j]]=0;
		for(int j=0;j<v[i].size();j++){
			tong[getfather(v[i][j])]++;
		}
		for(int j=1;j<=tot;j++){
			int k=q[j];
			if(tong[k]<size[k]){
				size[i]+=size[k]; father[k]=i; vis[j]=1; 
			}
		}
		int tt=0;
		for(int j=1;j<=tot;j++)if(!vis[j])q[++tt]=q[j];
		tot=tt;
		q[++tot]=i;
		//cout<<size[q[1]]<<" "<<size[q[2]]<<endl;
	}
	for(int i=1;i<=tot;i++)q[i]=size[q[i]];
	sort(&q[1],&q[tot+1]);
	writeln(tot);
	for(int i=1;i<=tot;i++){
		write(q[i]); putchar(' ');
	}
}