#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=500005;
int n,m;
struct opt{
	char type;
	int a,b;
	LL ans;
}q[N];
vector <int> qid[N];
namespace u1{
	int cnt;
	int fa[N*2],mx[N*2];
	void init(){
		cnt=n;
		For(i,1,n*2)
			fa[i]=i,mx[i]=0;
	}
	int getf(int x){
		if (x==fa[x])
			return x;
		int f=getf(fa[x]);
		mx[x]=max(mx[x],mx[fa[x]]);
		return fa[x]=f;
	}
	void Merge(int x,int y){
		x=getf(x),y=getf(y);
		fa[x]=fa[y]=++cnt;
	}
	void update(int x,int v){
		x=getf(x);
		mx[x]=v;
	}
	int query(int x){
		getf(x);
		return max(mx[x],mx[fa[x]]);
	}
}
int fa[N],size[N];
LL sz[N];
int getf(int x){
	if (fa[x]==x)
		return x;
	int f=getf(fa[x]);
	if (f!=fa[x])
		sz[x]+=sz[fa[x]];
	return fa[x]=f;
}
void Merge(int x,int y){
	x=getf(x),y=getf(y);
	fa[y]=x;
	sz[y]-=sz[x];
//	outval(sz[y]);
	size[x]+=size[y];
}
void update(int x){
	x=getf(x);
	sz[x]+=size[x];
//	outval(x);outval(size[x]);outval(sz[x]);
}
LL query(int x){
	getf(x);
//	outval(x);outval(fa[x]);
//	outval(sz[x]);outval(sz[fa[x]]);
	return x==fa[x]?sz[x]:sz[x]+sz[fa[x]];
}
int main(){
	n=read(),m=read();
	u1::init();
	For(i,1,m){
		char s[2];
		scanf("%s",s);
		q[i].type=s[0];
		if (s[0]=='U'){
			q[i].a=read(),q[i].b=read();
		}
		else if (s[0]=='M'){
			q[i].a=read(),q[i].b=read();
			u1::Merge(q[i].a,q[i].b);
		}
		else if (s[0]=='A'){
			q[i].a=read();
		}
		else if (s[0]=='Z'){
			q[i].a=read();
			u1::update(q[i].a,i);
		}
		else if (s[0]=='Q'){
			q[i].a=read();
			qid[u1::query(q[i].a)].pb(i);
		}
	}
	For(i,1,n)
		fa[i]=i,sz[i]=0,size[i]=1;
	For(i,1,m){
		char T=q[i].type;
		if (T=='U'){
			Merge(q[i].a,q[i].b);
		}
		else if (T=='M'){
		}
		else if (T=='A'){
			update(q[i].a);
		}
		else if (T=='Z'){
		}
		else if (T=='Q'){
			q[i].ans+=query(q[i].a);
			printf("%lld\n",q[i].ans);
		}
		for (auto j : qid[i])
			q[j].ans-=query(q[j].a);
	}
	return 0;
}