#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<complex>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
int sum[N][10];
inline int f(int x){
	int ans=1;
	while(x){
		if(x%10)ans=ans*(x%10);
		x/=10;
	}
	return ans;
}
inline int g(int x){
	if(x<10)return x;
	else return g(f(x));
}
int main(){
	for(int i=1;i<N;i++){
		for(int j=1;j<=9;j++)sum[i][j]=sum[i-1][j];
		sum[i][g(i)]++;
	}
	int q=read();
	while(q--){
		int l=read(),r=read(),x=read();
		writeln(sum[r][x]-sum[l-1][x]);
	}
}