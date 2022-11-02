#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<complex>
using namespace std;
typedef long long ll;
#define int long long
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
const int N=400005,K=20;
int n,f[N][K],g[N][K],cnt,father[N],val[N],deep[N];
inline void insert(int nod,int fa,int w){
	//cout<<nod<<" "<<fa<<endl;
	father[nod]=fa; deep[nod]=deep[fa]+1;
	val[nod]=w;
	f[nod][0]=fa;
	g[nod][0]=w;
	for(int i=1;i<K;i++){
		f[nod][i]=f[f[nod][i-1]][i-1];
		g[nod][i]=g[nod][i-1]+g[f[nod][i-1]][i-1];
	}
	//if(nod==3)cout<<f[nod][1]<<" "<<g[nod][1]<<endl;
}
inline int find(int dq,int x){
	if(val[dq]>=x||dq==0)return dq;
	return find(father[dq],x);
}
signed main(){
	int q=read(),last=0,cnt=1; deep[1]=1;
	while(q--){
		int op=read(),p=read(),q=read();
		p=p^last; q=q^last;
		if(op==1){
			insert(++cnt,find(p,q),q);
		}else{
			int ans=0;
			for(int i=K-1;i>=0;i--)if(p&&g[p][i]<=q){
				q-=g[p][i]; ans+=min((ll)1<<i,deep[p]); p=f[p][i];
			}
			writeln(last=ans);
		}
	}
}