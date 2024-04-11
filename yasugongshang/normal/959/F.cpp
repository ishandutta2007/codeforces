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
const int N=100005,K=20,mod=1000000007;
int n,q,ans[N];
struct datastruct{
	int a[K],sz;
	bool insert(int x){
		for(int i=K-1;i>=0;i--)if(x>>i&1){
			if(!a[i]){
				a[i]=x; return 1;
			}
			x^=a[i];
		}
		sz++;
		return 0;
	}
	int query_mx(){
		int ans=0;
		for(int i=K-1;i>=0;i--)if((ans^a[i])>ans)ans^=a[i];
		return ans;
	}
	bool find(int x){
		for(int i=K-1;i>=0;i--)if(x>>i&1)x^=a[i];
		return x?0:1;
	}
}T[N];
int main(){
	n=read(); q=read(); ans[0]=1;
	for(int i=1;i<=n;i++){
		T[i]=T[i-1]; T[i].insert(read()); ans[i]=(ans[i-1]<<1)%mod;
	}
	for(int i=1;i<=q;i++){
		int pos=read(),x=read();
		if(T[pos].find(x))writeln(ans[T[pos].sz]); else puts("0");
	}
}