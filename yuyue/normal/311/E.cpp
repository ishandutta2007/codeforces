#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10,inf=1e9;
int head[M/10],to[M],w[M],cnt,nxt[M];
void add(int x,int y,int v){
	nxt[++cnt]=head[x];  to[cnt]=y; w[cnt]=v; head[x]=cnt; 
}
void jb(int x,int y,int v){
	add(x,y,v); add(y,x,0);
}
int dep[M],q[M],cur[M/10],S,T,n,m,g;
bool a[M];
bool bfs(){
	int l,r; q[l=r=1]=S;
	ms(dep,0); dep[S]=1;
	while (l<=r){
		int x=q[l++];
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if (w[i] && !dep[y]) {
				dep[y]=dep[x]+1;
				q[++r]=y;
			}
		}
	}
	return dep[T];
}
int dfs(int x,int flow){
	if (x==T || !flow) return flow;
	int ret=0;
	for (int &i=cur[x];i;i=nxt[i]){
		int y=to[i];
		if (w[i] && dep[y]==dep[x]+1){
			int ff=dfs(y,min(flow-ret,w[i]));
			w[i]-=ff; w[i^1]+=ff; ret+=ff;
		}
	}
	return ret;
}
int main(){
	n=read(); m=read(); g=read(); S=0; T=n+m+m+1; cnt=1;
	F(i,1,n) a[i]=read();
	F(i,1,n) {
		int v=read();
		if (a[i]){
			jb(S,i,0); jb(i,T,v);
		}
		else {
			jb(S,i,v); jb(i,T,0);
		}
	}
	int ans=0;
	F(i,1,m){
		int op=read(),v=read(),k=read();
		int n1=i+n,n2=n1+m;
		F(j,1,k){
			int x=read();
			jb(x,n1,inf); jb(n2,x,inf);
		}
		int oo=read(); 
		if (oo) jb(n1,n2,g+v); 
		else jb(n1,n2,v);
		ans+=v;
		if (op) jb(n2,T,inf); 
		else jb(S,n1,inf);
	}
	while (bfs()) memcpy(cur,head,sizeof head),ans-=dfs(S,inf);
	cout<<ans<<"\n";
	return 0;
}