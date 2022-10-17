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
const int M=4e5+10;
vector<int> v[M];
int sz[M],son[M],k,n;
struct info{
	int m,mm;
}mx[M];
vector<info> p[M],s[M];
void mg(info &A,int x){
	if (x>k) return ;
	if (x>=A.m) A.mm=A.m,A.m=x;
	else if (x>A.mm) A.mm=x;
}
void mg(info &A,info B){
	mg(A,B.m); mg(A,B.mm);
}
void dfs(int x,int fa){
	sz[x]=1; 
	s[x].resize(SZ(v[x])+1);
	p[x].resize(SZ(v[x])+1);
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (y==fa) continue; 
		dfs(y,x); 
		info op; op.m=op.mm=0;
		mg(op,sz[y]); 
		mg(op,mx[y]); 
		mg(mx[x],mx[y]);
		mg(mx[x],sz[y]);
		s[x][i]=p[x][i]=op;
		sz[x]+=sz[y];
		if (sz[y]>sz[son[x]]) son[x]=y;
	}
	F(i,1,SZ(v[x])) mg(p[x][i],p[x][i-1]);
	DF(i,SZ(v[x])-1,0) mg(s[x][i],s[x][i+1]);
//	cout<<x<<"\n";
}
bool ans[M];
void dd(int x,int fa,int ff,info o){
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (y==fa) continue; 
		info u,t=o; u.m=u.mm=0; 
		if (i) mg(u,p[x][i-1]);
		if (i!=SZ(v[x])) mg(u,s[x][i+1]);
		mg(t,u);
		if (ff==x && n-sz[y]<=k) ff=y,mg(t,n-sz[y]); 
		if (sz[son[y]]>k && sz[son[y]]-mx[son[y]].m>k) ans[y]=1;
		if (n-sz[y]>k && n-sz[y]-t.m>k) ans[y]=1;
		dd(y,x,ff,t); 
	}
}
int main(){
	n=read(); k=n/2; 
	F(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	dfs(1,0); 
	if (sz[son[1]]>k && sz[son[1]]-mx[son[1]].m>k) ans[1]=1;
	info p; p.m=p.mm=0; dd(1,0,1,p);
	F(i,1,n) cout<<!ans[i]<<" "; cout<<"\n";
    return 0;
}