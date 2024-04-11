#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
signed main(){
	int n=read(),L=read(),v1=read(),v2=read(),k=read();
	double l=(double)l/v1,r=1e9;
	v2-=v1;
	for(int i=1;i<=100;i++){
		double mid=(l+r)/2;
		double nn=L-mid*v1;
		double tim=nn/v2;
		if((n+k-1)/k*tim+(n-1)/k*tim*v2/(v1+v1+v2)<=mid)r=mid; else l=mid;
	}
	printf("%.7lf\n",l);
}
/*
SAM
for(int i=1;i<=n;i++)w[i]=read();
for(int i=1;i<=n;i++)a[i]=read();
for(int i=1;i<=n;i++)b[i]=read();
for(int i=1;i<=n;i++)f[i]=read();

*/