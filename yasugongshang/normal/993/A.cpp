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
struct P{
	ll x,y;
	void Read(){x=read()+300,y=read()+300;}
}p[10];
bool operator <(P a,P b){
	return a.x==b.x?(a.y<b.y):(a.x<b.x);
}
ll a,b,c,d,has[1000][1000];
int main(){
	a=read(),b=read();read();read();c=read();d=read();read();read();
	if (a>c)swap(a,c);
	if (b>d)swap(b,d);
	a+=300,b+=300,c+=300,d+=300;
	for(int i=a;i<=c;i++)for(int j=b;j<=d;j++)has[i][j]=1;
	for(int i=1;i<=4;i++)p[i].Read();
	sort(&p[1],&p[5]);
	ll l=p[1].y,r=p[1].y,mid=(p[1].x+p[4].x)>>1;
	for(int i=p[1].x;i<=p[4].x;i++){
		for(int j=l;j<=r;j++)if (has[i][j])return puts("YES"),0;
		if(i<mid)--l,++r;
		else	++l,--r;
	}puts("NO");
}