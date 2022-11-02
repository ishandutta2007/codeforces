#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define int long long
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
const int N=1<<18;
int n,q,a[N];
ll sum;
signed main(){
	n=read(); q=read();
	for(int i=0;i<(1<<n);i++){
		a[i]=read(); sum+=a[i];
	}
	double t=pow(0.5,n); 
	printf("%.7lf\n",(double)sum*t);
	for(int i=1;i<=q;i++){
		int x=read(),y=read(); sum+=y-a[x]; a[x]=y;
		printf("%.7lf\n",(double)sum*t);
	} 
}