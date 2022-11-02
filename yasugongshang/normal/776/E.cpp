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
#define int long long
#define mp make_pair
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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
int n,k;
inline int f(int x){
	int zs=x;
	for(int i=2;i*i<=x;i++)if(x%i==0){
		zs=zs/i*(i-1); while(x%i==0)x/=i;
	}
	if(x>1)zs=zs/x*(x-1);
	return zs;
}
inline int g(int x){
	return x;
}
inline int fk(int n,int k){
	int ans=g(n);
	for(int i=1;i<=k;i++){if(i&1)ans=f(ans); else ans=g(ans); if(ans==1)return 1;}
	return ans;
}
signed main(){
	int n=read(),k=read();
	cout<<fk(n,k)%1000000007<<endl;
}