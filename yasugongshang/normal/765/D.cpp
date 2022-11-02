#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
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
const int N=100005;
int n,tot,a[N],g[N],h[N];
map<int,int> M;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(); if(!M[a[i]]){M[a[i]]=++tot; h[tot]=a[i];}
		g[i]=M[a[i]];
	}
	for(int i=1;i<=tot;i++)if(g[h[i]]!=i){
		puts("-1"); return 0;
	}
	writeln(tot);
	for(int i=1;i<=n;i++)wri(g[i]); puts("");
	for(int i=1;i<=tot;i++)wri(h[i]);
}
//m<n 
//h
//m
//g(x)=b(x) a
//