#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
#define ld long double
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=300005;
int n,m,rt,sz[N],w[N],W[N],in[N],out[N],tot,ch[N][2],dep[N],fa[N],lazy[N];
inline bool get(int x){
	return ch[fa[x]][1]==x;
}
inline void cao(int x,int y){
	w[x]+=y; lazy[x]+=y;
}
void pushdown(int x){
	if(lazy[x]){
		if(ch[x][0])cao(ch[x][0],lazy[x]); if(ch[x][1])cao(ch[x][1],lazy[x]); lazy[x]=0;
	}
}
inline void update(int x){
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}
inline void rotate(int x){
    int y=fa[x],z=fa[y],o=get(x);
    if(z)ch[z][get(y)]=x;
    ch[y][o]=ch[x][o^1]; if(ch[y][o])fa[ch[y][o]]=y;
    ch[x][o^1]=y; fa[y]=x; fa[x]=z;
    update(y); update(x);
}
void push(int x){
	if(fa[x])push(fa[x]);
	pushdown(x);
}
void splay(int x,int k){
    push(x);
	for(int y,z;fa[x]!=k;rotate(x)){
    	y=fa[x]; z=fa[y];
    	if (z!=k)rotate((get(z)^get(y))?x:y);
 	}
    if(!k)rt=x;
}
void Update(int x){
	while(x){
		update(x); x=fa[x];
	}
}
void insert(int x){
	if(!rt){
		w[rt=tot=1]=x; sz[1]=1; return;
	}
	int now=rt;
	while(now){
		pushdown(now);
		if(w[now]>x){
			if(!ch[now][0]){
				ch[now][0]=++tot; fa[tot]=now; w[tot]=x; sz[tot]=1; splay(tot,0); return;
			}
			now=ch[now][0];
		}else{
			if(!ch[now][1]){
				ch[now][1]=++tot; fa[tot]=now; w[tot]=x; sz[tot]=1; splay(tot,0); return;
			}
			now=ch[now][1];
		}
	}
}
int Alb(int x,bool id){
	int now=rt,res=0,jb=0;
	while(now){
		if(now)jb=now;
		if(w[now]!=x&&((w[now]>x)==id&&(!res||(w[res]>w[now])==id)))res=now; 
		pushdown(now);//cout<<now<<" "<<ch[now][0]<<" "<<ch[now][1]<<endl;
		if(w[now]==x)now=ch[now][id]; else
		if(w[now]>x)now=ch[now][0]; else now=ch[now][1]; 
	}
	splay(jb,0);
	return res;
}
int bao(int x,bool id){
	splay(x,0); x=ch[x][id]; 
	while(ch[x][id^1])x=ch[x][id^1];
	return x;
}
int get(int l,int r){
	int L=Alb(l,0),R=Alb(r,1); //cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
	//cout<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<w[L]<<endl;
	splay(L,0); splay(R,rt);
	return ch[R][0];
}
int Get(int l,int r){
	int L=bao(l,0),R=bao(r,1);
	splay(L,0); splay(R,rt);
	return ch[R][0];
}
void erase(int x){
	int t=Get(x,x);
	ch[fa[t]][get(t)]=0;
	Update(fa[t]); fa[t]=0;
}
int main(){
	insert(0); insert(2e9); //cout<<fa[1]<<" "<<fa[2]<<" "<<w[1]<<" "<<w[2]<<" "<<rt<<endl;
	//cout<<Alb(1,0)<<" "<<ch[2][0]<<endl;
	n=read();
	for(int i=1;i<=n;i++){
		//cout<<fa[2]<<" zyyak "<<fa[fa[2]]<<" "<<rt<<" "<<Alb(10000,1)<<endl;
		int l=read(),r=read(); if(l>r)swap(l,r); 
		int t=get(l,r-1);
		if(t)cao(t,1); 
		//cout<<ch[rt][1]<<" "<<w[rt]<<" "<<rt<<endl;
		//for(int i=2;i;i=fa[i])cout<<i<<endl;
		//cout<<rt<<" flo "<<i<<endl;
		//for(int i=1;i<=tot;i++){cout<<i<<" "<<fa[i]<<" ";cout<<w[i]<<endl;}
		//cout<<rt<<" wzp "<<ch[rt][1]<<endl; if(i==34)return 0;
		if(ch[rt][1]!=2)erase(ch[rt][1]);
		insert(l);
	}
	cout<<sz[rt]-2<<endl;
}
/*

l
[l,r-1]  
[r,inf]  

[l,r-1] 

*/