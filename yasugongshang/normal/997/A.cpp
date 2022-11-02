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
const int N=300005;
char ch[N];
int n,x,y,tot;
signed main(){
	n=read(); x=read(); y=read();
	scanf("%s",ch+1);
	for(int i=2;i<=n;i++)if(ch[i]!=ch[i-1]){
		tot++; 
	}
	tot++;
	if(tot==1&&ch[1]=='1')puts("0"); else 
	if(x<y)cout<<x*(tot/2-(ch[1]=='1'||ch[n]=='1'))+y<<endl;
	else cout<<y*(tot/2+(ch[1]=='0'&&ch[n]=='0'))<<endl;
}