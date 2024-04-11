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
const int N=300005;
int n,mx,ans[N],q[N],a[N];
set<int> s;
void S(int &a,int b){
	a=max(a,b);
}
inline bool cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){a[i]=read(); mx=max(mx,a[i]);}
	for(int i=1;i<n;i++){
		S(ans[abs(abs(i-1-(n-i-1))-1)],min(a[i],a[i+1]));
	}
	for(int i=1;i<=n;i++){
		S(ans[abs(abs(i-1-(n-i))-1)],a[i]);
	}
	for(int i=2;i<n;i++)ans[i]=max(ans[i-2],ans[i]);
	ans[n-1]=max(ans[n-1],mx);
	for(int i=0;i<n;i++)wri(ans[i]);
}