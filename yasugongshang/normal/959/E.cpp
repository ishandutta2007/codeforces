#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
unordered_map<ll,ll> M;
ll solve(ll x){
	if(M.count(x))return M[x];
	for(int i=40;i>=0;i--)if(x>>i&1){
		return M[x]=solve(((ll)1<<i)-1)+solve(x-((ll)1<<i))+((ll)1<<i);
	}
}
int main(){
	ll x=read()-1;
	M[0]=0;
	cout<<solve(x)<<endl;
}