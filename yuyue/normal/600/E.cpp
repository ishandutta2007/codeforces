#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1e5+10; 
int n,c[M];
vector<int> v[M];
int son[M],sz[M]; 
void dfs(int x,int fa){
	sz[x]=1; 
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (y==fa) continue;
		dfs(y,x);
		if (sz[y]>sz[son[x]]) son[x]=y;
		sz[x]+=sz[y];
	}
}
LL sum[M],ans[M];
int ct[M],mx;  
bool vis[M];
void calc(int x,int fa,int op){
	sum[ct[c[x]]]-=c[x]; 
	ct[c[x]]+=op;
	sum[ct[c[x]]]+=c[x];
	if (sum[mx+1]) mx++;
	else if (!sum[mx]) mx--;
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (y==fa || vis[y]) continue;
		calc(y,x,op); 
	}
}

void ds(int x,int fa,bool sv){
	F(i,0,SZ(v[x])){
		int y=v[x][i]; 
		if (y==fa || y==son[x]) continue; 
		ds(y,x,0); 
	}
	if (son[x]) ds(son[x],x,1),vis[son[x]]=1;
	calc(x,fa,1);
	ans[x]=sum[mx]; vis[son[x]]=0; 
	if (!sv) calc(x,fa,-1); 
}
int main(){
	n=read();
	F(i,1,n) c[i]=read(); 
	F(i,1,n-1){
		int x=read(),y=read(); 
		v[x].pb(y); v[y].pb(x);
	} 
	dfs(1,0); ds(1,0,0); 
	F(i,1,n) cout<<ans[i]<<" "; 
    return 0;
}