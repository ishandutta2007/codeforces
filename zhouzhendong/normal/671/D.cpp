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
const int N=300005;
const LL INF=1e18;
int n,m;
vector <int> e[N],id[N];
int depth[N];
void dfs0(int x,int pre,int d){
	depth[x]=d;
	for (auto y : e[x])
		if (y!=pre)
			dfs0(y,x,d+1);
}
int d[N],c[N];
int rt[N],ls[N],rs[N],len[N];
LL val[N],add[N];
void pushadd(int x,LL v){
	add[x]+=v;
	val[x]+=v;
}
void pushdown(int x){
	pushadd(ls[x],add[x]);
	pushadd(rs[x],add[x]);
	add[x]=0;
}
int Merge(int x,int y){
	if (!x||!y)
		return x|y;
	pushdown(x);
	pushdown(y);
	if (val[y]<val[x])
		swap(x,y);
	rs[x]=Merge(rs[x],y);
	if (len[rs[x]]>len[ls[x]])
		swap(ls[x],rs[x]);
	len[x]=len[rs[x]]+(len[ls[x]]==len[rs[x]]);
	return x;
}
int pop(int x){
	return Merge(ls[x],rs[x]);
}
void dfs(int x,int pre){
	rt[x]=0;
	for (auto y : id[x])
		rt[x]=Merge(rt[x],y);
	LL sum=0;
	for (auto y : e[x])
		if (y!=pre){
			dfs(y,x);
			while (d[rt[y]]>depth[x])
				rt[y]=pop(rt[y]);
			if (!rt[y]){
				puts("-1");
				exit(0);
			}
			sum+=val[rt[y]];
		}
	pushadd(rt[x],sum);
	for (auto y : e[x])
		if (y!=pre){
			pushadd(rt[y],sum-val[rt[y]]);
			rt[x]=Merge(rt[x],rt[y]);
		}
}
int main(){
	n=read(),m=read();
	if (n==1)
		return puts("0"),0;
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	dfs0(1,0,0);
	For(i,1,m){
		int x=read(),y=read(),z=read();
		d[i]=depth[y],c[i]=z;
		id[x].pb(i);
		val[i]=z;
	}
	dfs(1,0);
	while (d[rt[1]]>0)
		rt[1]=pop(rt[1]);
	if (!rt[1])
		puts("-1");
	else
		cout<<val[rt[1]]<<endl;
	return 0;
}