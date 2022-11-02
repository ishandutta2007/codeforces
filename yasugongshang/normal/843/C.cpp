#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
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
	write(a); putchar('\n');
}
const int N=200005;
int nedge,peo[N],f[N],father[N],q[N],tot,top,son[N],nextt[N<<1],ed[N<<1],sum,vis[N],n;
int ans[N*2][3],gen[N];
inline void aedge(int a,int b){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b;
}
void get(int p,int fa){
	peo[p]=1; f[p]=0;
	for(int i=son[p];i;i=nextt[i])if(!vis[ed[i]]&&ed[i]!=fa){
		get(ed[i],p); peo[p]+=peo[ed[i]]; f[p]=max(f[p],peo[ed[i]]);
	}
	f[p]=max(f[p],sum-peo[p]); if(f[p]*2<=n)gen[p]=vis[p]=1;
}
void solve(int p){
	vis[p]=1;
	for(int i=son[p];i;i=nextt[i])if(!vis[ed[i]]){
		father[ed[i]]=p; solve(ed[i]);
	}
	q[++top]=p;
}
int main(){
	n=read(); f[0]=1e9;
	for(int i=1;i<n;i++){
		int a=read(),b=read();
		aedge(a,b); aedge(b,a);
	}
	sum=n; get(1,0);
	for(int i=1;i<=n;i++)if(gen[i]){
		for(int j=son[i];j;j=nextt[j])if(!gen[ed[j]]){
			top=0; solve(ed[j]); 
			ans[++tot][0]=i; ans[tot][1]=ed[j]; ans[tot][2]=q[1];
			for(int j=2;j<=top;j++){
				ans[++tot][0]=q[j-1]; ans[tot][1]=father[q[j-1]]; ans[tot][2]=q[j];
			}
			for(int j=top-1;j;j--){
				ans[++tot][0]=q[j]; ans[tot][1]=q[j+1]; ans[tot][2]=q[top];
			}
			//cout<<q[top]<<" axs "<<ed[j]<<endl;
			ans[++tot][0]=i; ans[tot][1]=q[1]; ans[tot][2]=q[top];
		}
	}
	sum=0;
	for(int i=1;i<=tot;i++)if(ans[i][1]!=ans[i][2])sum++;
	writeln(sum);
	for(int i=1;i<=tot;i++)if(ans[i][1]!=ans[i][2]){
		cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
	}
}