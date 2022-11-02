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
typedef pair <unsigned short,unsigned short> pss;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=550006*2;
int n,m,q;
int pos[N];
char s[N];
string str[50005];
namespace Seg{
	pss better(pss a,pss b){
		if (a.fi!=b.fi)
			return a.fi>b.fi?a:b;
		return a.se<b.se?a:b;
	}
	pss mx[N*40];
	int ls[N*40],rs[N*40];
	int cnt=0;
	void pushup(int rt){
		mx[rt]=better(mx[ls[rt]],mx[rs[rt]]);
	}
	void Ins(int &rt,int L,int R,int x){
		if (!rt)
			rt=++cnt;
		if (L==R){
			mx[rt]=mp(1,x);
			return;
		}
		int mid=(L+R)>>1;
		if (x<=mid)
			Ins(ls[rt],L,mid,x);
		else
			Ins(rs[rt],mid+1,R,x);
		pushup(rt);
	}
	int Merge(int x,int y,int L,int R){
		if (!x||!y)
			return x|y;
		int rt=++cnt;
		if (L==R)
			mx[rt]=mp(mx[x].fi+mx[y].fi,mx[x].se);
		else {
			int mid=(L+R)>>1;
			ls[rt]=Merge(ls[x],ls[y],L,mid);
			rs[rt]=Merge(rs[x],rs[y],mid+1,R);
			pushup(rt);
		}
		return rt;
	}
	pss Query(int rt,int L,int R,int xL,int xR){
		if (!rt||L>xR||R<xL)
			return mp(0,0);
		if (xL<=L&&R<=xR)
			return mx[rt];
		int mid=(L+R)>>1;
		return better(Query(ls[rt],L,mid,xL,xR),
					  Query(rs[rt],mid+1,R,xL,xR));
	}
}
namespace SAM{
	int fa[N],Next[N][26],Len[N];
	int cnt,last;
	void clear(){
		cnt=last=1;
	}
	void setnew(){
		last=1;
	}
	int Ins(int c){
		if (Next[last][c]&&Len[last]+1==Len[Next[last][c]])
			return last=Next[last][c];
		int p=last,np=++cnt,q,nq;
		Len[np]=Len[p]+1;
		for (;p&&!Next[p][c];p=fa[p])
			Next[p][c]=np;
		if (!p)
			fa[np]=1;
		else {
			q=Next[p][c];
			if (Len[q]==Len[p]+1)
				fa[np]=q;
			else {
				nq=++cnt;
				fa[nq]=fa[q];
				fa[np]=fa[q]=nq;
				Len[nq]=Len[p]+1;
				For(i,0,25)
					Next[nq][i]=Next[q][i];
				for (;p&&Next[p][c]==q;p=fa[p])
					Next[p][c]=nq;
			}
		}
		return last=np;
	}
	int rt[N];
	vector <int> son[N];
	int anst[N][20];
	void dfs(int x){
		anst[x][0]=fa[x];
		For(i,1,19)
			anst[x][i]=anst[anst[x][i-1]][i-1];
		for (auto y : son[x]){
			dfs(y);
			rt[x]=Seg::Merge(rt[x],rt[y],1,m);
		}
	}
	void build(){
		For(i,2,cnt)
			son[fa[i]].pb(i);
		dfs(1);
	}
}
int main(){
	cin>>(s+1);
	n=strlen(s+1);
	SAM::clear();
	For(i,1,n)
		pos[i]=SAM::Ins(s[i]-'a');
	m=read();
	For(i,1,m){
		cin>>str[i];
		SAM::setnew();
		For(j,0,(int)str[i].size()-1){
			int x=SAM::Ins(str[i][j]-'a');
			Seg::Ins(SAM::rt[x],1,m,i);
		}
	}
	SAM::build();
	q=read();
	while (q--){
		int L=read(),R=read(),pl=read(),pr=read();
		int x=pos[pr];
		Fod(i,19,0)
			if (SAM::Len[SAM::anst[x][i]]>=pr-pl+1)
				x=SAM::anst[x][i];
		pss res=Seg::Query(SAM::rt[x],1,m,L,R);
		if (res.fi==0)
			res.se=L;
		printf("%d %d\n",(int)res.se,(int)res.fi);
	}
	return 0;
}