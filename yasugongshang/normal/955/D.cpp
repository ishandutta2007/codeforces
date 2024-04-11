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
inline void write(ll a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=500005,M=N<<1,K=26;
struct SAM{
	int tot,last,go[M][K],pre[M],len[M],mi[M],mx[M],q[M],id[M];
	void init(){
		mi[last=tot=1]=N;
	}
	void add(int c){
		int np=++tot,p=last; mi[np]=N;
		len[np]=len[p]+1; last=np;
		for(;p&&!go[p][c];p=pre[p])go[p][c]=np;
		if(!p)pre[np]=1; else{
			int q=go[p][c];
			if(len[p]+1==len[q])pre[np]=q; else{
				int nq=++tot; memcpy(go[nq],go[q],sizeof(go[q]));
				mi[nq]=N;
				len[nq]=len[p]+1;
				pre[nq]=pre[q];
				pre[np]=pre[q]=nq;
				while(go[p][c]==q){
	                go[p][c]=nq;
	                p=pre[p];
	            }
			}
		}
	}
	void solve(){
		for(int i=1;i<=tot;i++)q[i]=i;
		sort(&q[1],&q[tot+1]);
		for(int i=1;i<=tot;i++){
			mx[pre[q[i]]]=max(mx[pre[q[i]]],mx[q[i]]); mi[pre[q[i]]]=min(mi[pre[q[i]]],mi[q[i]]); id[pre[q[i]]]=min(id[pre[q[i]]],id[q[i]]);
		}
	}
}T[2];
char s[N],t[N];
int f[N],g[N];
int main(){
	int n=read(),m=read(),k=read();
	scanf("%s%s",s+1,t+1);
	T[0].init(); T[1].init(); 
	for(int i=1;i<=n;i++){T[0].add(s[i]-'a'); if(i>=k)T[0].mx[T[0].last]=T[0].mi[T[0].last]=i; T[0].id[T[0].last]=i;}
	for(int i=n;i;i--){T[1].add(s[i]-'a'); if(i+k-1<=n)T[1].mx[T[1].last]=T[1].mi[T[1].last]=i;}
	int zs=1; for(int i=1;i<=m;i++)zs=T[0].go[zs][t[i]-'a'];
	if(zs){
		puts("Yes");
		cout<<max(1,T[0].id[zs]-max(m,k*2)+1)<<" "<<max(1,T[0].id[zs]-max(m,k*2)+1)+k<<endl; return 0;
	}
	T[0].solve(); T[1].solve();
	f[0]=g[m+1]=1;
	for(int i=1;i<=m;i++)f[i]=T[0].go[f[i-1]][t[i]-'a']; for(int i=m;i;i--)g[i]=T[1].go[g[i+1]][t[i]-'a'];
	//for(int i=1;i<=m;i++)cout<<f[i]<<" "<<g[i]<<endl;
	for(int i=max(1,m-k);i<=k&&i<=m;i++)if(f[i]&&g[i+1]){
  		//cout<<T[0].mi[f[i]]<<" frasf "<<T[1].mx[g[i+1]]<<endl;
		//cout<<f[i]<<" "<<g[i]<<endl;
		if(T[0].mi[f[i]]<T[1].mx[g[i+1]]){
			puts("Yes");
			cout<<T[0].mi[f[i]]-k+1<<" "<<T[1].mx[g[i+1]]<<endl; return 0;
		}
	}
	puts("No");
}