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
const int N=1<<22|5;
int father[N],tong[N],vis[N],m,n,ans,jb[N],a[N];
inline int getfather(int x){
	return father[x]==x?x:father[x]=getfather(father[x]);
}
inline void mer(int a,int b){
	//cout<<a<<" "<<b<<endl;
	int t1=getfather(a),t2=getfather(b);
	if(t1!=t2)father[t1]=t2;
}
void dfs(int x,int id){
	if(vis[x]){
		if(jb[x])mer(jb[x],id);
		return;
	}else vis[x]=1;
	for(int i=0;i<m;i++)if(x>>i&1)dfs(x^(1<<i),id);
	if(tong[x])mer(id,tong[x]);
}
int main(){
	m=read(); n=read();
	for(int i=1;i<=n;i++){
		tong[a[i]=read()]=i; jb[a[i]]=i; father[i]=i;
	}
	for(int i=1;i<(1<<m);i++)for(int j=0;j<m&&jb[i]==0;j++)if(i>>j&1)jb[i]|=jb[i^(1<<j)];
	for(int i=1;i<=n;i++)dfs(a[i]^((1<<m)-1),i); 
	for(int i=1;i<=n;i++)ans+=getfather(i)==i;
	writeln(ans);
}