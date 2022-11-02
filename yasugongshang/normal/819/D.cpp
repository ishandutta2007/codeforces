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
const int N=200005;
int T,n,a[N],S,rk[N],ans[N];
map<int,vector<int> > v;
inline bool cmp(int a,int b){
	return rk[a]==rk[b]?a>b:rk[a]<rk[b];
}
int exgcd(int a,int b,int &x,int &y){
    if(b==0){x=a;y=0;return a;}
    else{
        int d=exgcd(b,a%b,y,x);
        y-=a/b*x;
        return d;
    }
}
int main(){
	T=read(); n=read();
	for(int i=0;i<n;i++){
		a[i]=read(); if(i>1)a[i]=(a[i]+a[i-1])%T;
	}
	S=(a[n-1]+a[0])%T; a[0]=0;
	int t=__gcd(S,T),SS=S/t,TT=T/t,x,y; 
	exgcd(SS,-TT,x,y); //cout<<SS<<" "<<TT<<" "<<x<<" "<<y<<endl;
	for(int i=0;i<n;i++){
		v[a[i]%t].push_back(i);
		int zs=a[i]-a[i]%t;
		zs/=t; //cout<<zs<<endl;
		rk[i]=((ll)x*zs%TT+TT)%TT;
	}
	for(auto i:v){
		auto zz=i.second;
		sort(zz.begin(),zz.end(),cmp);
		int sz=zz.size();
		//for(auto j:zz)cout<<j<<endl; puts("");
		for(int j=0;j<sz;j++)ans[zz[j]]=j+1==sz?rk[zz[0]]+TT-rk[zz[j]]:rk[zz[j+1]]-rk[zz[j]];
	}
	for(int i=0;i<n;i++)wri(ans[i]);
}
/*
(x*S+aj)=k*y

S*i%T=zs

zs+T*j=i*S
*/