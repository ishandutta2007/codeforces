#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
	return (rand()<<16|rand())%x;
}
const int N=100005;
int n,d[N],ans,pos,sum;
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		d[x]++; d[y]++;
	}
	for(int i=1;i<=n;i++)if(d[i]>2){ans++; pos=i;}
	if(ans>1){
		puts("No"); return 0;
	}
	puts("Yes");
	if(ans==0)pos=1;
	for(int i=1;i<=n;i++)if(i!=pos&&d[i]==1){
		sum++;
	}
	writeln(sum);
	for(int i=1;i<=n;i++)if(i!=pos&&d[i]==1){
		write(pos); putchar(' '); writeln(i);
	}
}