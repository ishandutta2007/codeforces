#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
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
const int N=100005;
int n,k,a,b,c,d,q[N],tot;
int main(){
	n=read(); k=read(); 
	if(n==4||k<=n){
		puts("-1"); return 0;
	}
	a=read(); b=read(); c=read(); d=read(); 
	for(int i=1;i<=n;i++)if(i!=a&&i!=b&&i!=c&&i!=d)q[++tot]=i; 
	cout<<a<<" "<<c<<" ";
	for(int i=1;i<=tot;i++)cout<<q[i]<<" "; cout<<d<<" "<<b<<endl;
	cout<<c<<" "<<a<<" "; 
	for(int i=1;i<=tot;i++)cout<<q[i]<<" "; cout<<b<<" "<<d<<endl;
}