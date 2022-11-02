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
const int N=100005,M=1200000*17;
int nxt[M][2],mn[M],nodecnt;
int q,vis[N];
struct trie{
	int rt;
	void insert(int x){
		if(!rt){rt=++nodecnt; mn[rt]=1e9;} int p=rt; mn[rt]=min(mn[rt],x);
		for(int i=16;i>=0;i--){
			int t=x>>i&1;
			if(!nxt[p][t]){
				nxt[p][t]=++nodecnt; mn[nodecnt]=1e9;
			}
			p=nxt[p][t]; mn[p]=min(mn[p],x);
		}
	}
	int find(int s,int x){
		if(!rt||mn[rt]>s)return -1; int p=rt;
		for(int i=16;i>=0;i--){
			int t=x>>i&1;
			if(nxt[p][t^1]&&mn[nxt[p][t^1]]<=s)p=nxt[p][t^1];
			else p=nxt[p][t];
		}
		return mn[p];
	}
}T[N];
int main(){
	q=read(); 
	while(q--){
		int t=read();
		if(t==1){
			int x=read();
			if(!vis[x]){
				vis[x]=1;
				for(int i=1;i*i<=x;i++)if(x%i==0){
					T[i].insert(x);
					if(i*i!=x)T[x/i].insert(x);
				}
			}
		}else{
			int x=read(),k=read(),s=read();
			if(x%k==0)writeln(T[k].find(s-x,x)); else puts("-1");
		}
	}
	return 0;
}