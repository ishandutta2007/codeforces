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
int n;
map<int,int> M;
map<int,int>::iterator it;
ll ans;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int x=read(),y=read();
		M[x]=max(M[x],y);
	}
	n=read();
	for(int i=1;i<=n;i++){
		int x=read(),y=read();
		M[x]=max(M[x],y);
	}
	for(it=M.begin();it!=M.end();it++)ans+=it->second;
	cout<<ans<<endl;
}