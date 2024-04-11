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
#define lowbit(x) (x&-x)
int d[M],n,m;
void Add(int x,int o){
	for (;x<=n+m;x+=lowbit(x)) d[x]+=o;
}
int S(int x){
	LL ret=0;
	for (;x;x-=lowbit(x)) ret+=d[x];
	return ret;
}
int c[M][2],f[M],sz[M],col[M];
bool r[M];
#define lc c[x][0]
#define rc c[x][1]
bool nroot(int x){
	return (c[f[x]][0]==x) || (c[f[x]][1]==x); 
}
void pu(int x){
	sz[x]=sz[lc]+sz[rc]+1;
} 
void rev(int x){
	r[x]^=1; swap(lc,rc); 
}
void pd(int x){
	if (r[x]){
		rev(lc); rev(rc);
		r[x]=0;
	}
	if (lc) col[lc]=col[x];
	if (rc) col[rc]=col[x];
}
void pl(int x){
	if (nroot(x)) pl(f[x]);
	pd(x);
}
void asshole(int x){
	assert(f[x]!=x);
}
void rotate(int x){
	int y=f[x],z=f[y],k=(c[y][1]==x),w=c[x][!k];	//cout<<x<<" "<<y<<" "<<w<<" "<<f[x]<<" "<<f[y]<<" "<<f[w]<<"   sb\n";

	if (nroot(y)) c[z][(c[z][1]==y)]=x; c[x][!k]=y; c[y][k]=w;
	if (w)  f[w]=y; f[x]=z; f[y]=x;
//	asshole(x); asshole(y); asshole(w);
	pu(y); 
}
void splay(int x){
	pl(x);
	while (nroot(x)){
		int y=f[x],z=f[y];
		if (nroot(y)) rotate((c[y][0]==x)^(c[z][0]==y) ? x : y); 
		rotate(x);
	}
	pu(x); 
}
void access(int x,int now){
	for (int y=0;x;y=x,x=f[x]){
//		cout<<x<<" "<<f[x]<<"\n";
		splay(x); sz[x]-=sz[rc];
		Add(col[x],-sz[x]);
//		cout<<o<<" ";
		Add(now,sz[x]);
//		cout<<S(n+m)<<"    fuck\n";
		c[x][1]=y;
		pu(x);
	}
}
vector<int> v[M];

void dfs(int x,int fa){
	col[x]=x; sz[x]=1; 
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (y==fa) continue; 
		f[y]=x;
		dfs(y,x);
		if (col[x]<col[y]) col[x]=col[y],c[x][1]=y,sz[x]=sz[y]+1; 
	}
//	cout<<x<<" "<<f[x]<<"    yy\n";
	Add(col[x],1); 
}
int qry(int x){
	splay(x);
	return sz[rc]+S(col[x]-1)+1;
}
int main(){
	n=read(); m=read();
	F(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	dfs(n,0);
	int mx=n,o=m;
	while (o--){
		string op; cin>>op;
		int x=read(),y=0;
		if (op[0]=='u'){
			access(x,++mx); splay(x);
			col[x]=mx; rev(x);
		} 
		if (op[0]=='w'){
			cout<<qry(x)<<"\n";
		}
		if (op[0]=='c'){
			y=read();
			cout<<(qry(x)<qry(y) ? x : y)<<"\n";
			
		}
//		cout<<S(n+m)<<"    ed\n";
//		assert(S(n+m)==n);
	}
    return 0;
}