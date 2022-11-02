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
const int N=1000005;
int n,k,a[N],ycl[10000005];
inline bool check(int x){
	for(int i=0;i<x;i++)ycl[i]=0;
	for(int i=x;i<2*x&&i<=10000000;i++)ycl[i]=1;
	for(int i=2*x;i<=10000000;i++)ycl[i]=ycl[i>>1]+ycl[i-(i>>1)];
	int sum=0;
	for(int i=1;i<=n;i++){
		if((sum+=ycl[a[i]])>=k)return 1;
	}
	return 0;
}
int main(){
	n=read(); k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int l=0,r=1e7;
	while(l<r){
		int mid=l+r>>1; mid++;
		if(check(mid))l=mid; else r=mid-1;
	}
	writeln(l?l:-1);
}