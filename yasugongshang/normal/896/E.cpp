#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return rand()%x;
}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int block=400,N=100005,B=N/block+5;
int n,m,mx[N],val[N],a[N],tag[N],s[N],belong[N],L[B],R[B],tong[B][N],f[N];
inline int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void update(int x){
	while(!tong[x][mx[x]])mx[x]--;
}
void build(int x,int l,int r,int de){
	for(int i=L[x];i<=R[x];i++){a[i]=val[find(i)]; tong[x][a[i]]=0; s[i]=1;}
	for(int i=l;i<=r;i++)if(a[i]-tag[x]>de)a[i]-=de;
	for(int i=L[x];i<=R[x];i++){
		if(tong[x][a[i]]){s[tong[x][a[i]]]+=s[i]; f[i]=tong[x][a[i]];}
		else{tong[x][a[i]]=i; f[i]=i; val[i]=a[i];}
	}
	//cout<<tong[x][a[4]]<<" "<<a[4]<<" "<<l<<" "<<r<<" "<<tag[x]<<" "<<de<<endl;
	update(x);
}
inline void gao(int x,int y){
	if(2*y+tag[x]>mx[x]){
		for(int i=tag[x]+y+1;i<=mx[x];i++)if(tong[x][i]){
			if(!tong[x][i-y]){
				val[tong[x][i]]=i-y; swap(tong[x][i],tong[x][i-y]);
			}else{
				s[tong[x][i-y]]+=s[tong[x][i]]; f[tong[x][i]]=tong[x][i-y]; tong[x][i]=0;
			}
		}
		update(x);
	}else{
		for(int i=tag[x]+1;i<=tag[x]+y;i++)if(tong[x][i]){
			if(!tong[x][i+y]){
				val[tong[x][i]]=i+y; swap(tong[x][i],tong[x][i+y]);
			}else{
				s[tong[x][i+y]]+=s[tong[x][i]]; f[tong[x][i]]=tong[x][i+y]; tong[x][i]=0;
			}
		}
		tag[x]+=y; 
	}
	//cout<<x<<" "<<tong[x][100]<<" "<<mx[x]<<endl;
}
void insert(int l,int r,int x){
	if(belong[l]==belong[r]){
		build(belong[l],l,r,x); return;
	}
	build(belong[l],l,R[belong[l]],x); build(belong[r],L[belong[r]],r,x);
	for(int i=belong[l]+1;i<belong[r];i++)gao(i,x);
}
int ask(int l,int r,int x){
	int ans=0;
	if(belong[l]==belong[r]){
		for(int i=l;i<=r;i++)if(val[find(i)]-tag[belong[l]]==x)ans++; return ans;
	}
	for(int i=l;i<=R[belong[l]];i++)if(val[find(i)]-tag[belong[l]]==x)ans++;
	for(int i=L[belong[r]];i<=r;i++)if(val[find(i)]-tag[belong[r]]==x)ans++;
	for(int i=belong[l]+1;i<belong[r];i++)if(x+tag[i]<N)ans+=s[tong[i][x+tag[i]]];
	return ans;
}
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		val[i]=a[i]=read(); if(i%block==1)L[belong[i]=belong[i-1]+1]=i; else belong[i]=belong[i-1]; f[i]=R[belong[i]]=i; mx[belong[i]]=N-1;
	}
	for(int i=1;i<=belong[n];i++)build(i,L[i],R[i],0);
	for(int i=1;i<=m;i++){
		int op=read(),l=read(),r=read(),x=read();
		if(op==1)insert(l,r,x); else writeln(ask(l,r,x));
	}
}