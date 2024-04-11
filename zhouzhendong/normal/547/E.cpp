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
const int N=200005;
int n,q;
string s[N];
int cnt=1,Next[N][26],Fail[N];
int pos[N];
namespace Seg{
	const int S=N*20*2;
	int ls[S],rs[S];
	LL sum[S];
	int cnt;
	void Insert(int &rt,int L,int R,int x,int v){
		if (!rt)
			rt=++cnt;
		sum[rt]+=v;
		if (L==R)
			return;
		int mid=(L+R)>>1;
		if (x<=mid)
			Insert(ls[rt],L,mid,x,v);
		else
			Insert(rs[rt],mid+1,R,x,v);
	}
	int Merge(int x,int y,int L,int R){
		if (!x||!y)
			return x|y;
		int rt=++cnt,mid=(L+R)>>1;
		sum[rt]=sum[x]+sum[y];
		if (L<R){
			ls[rt]=Merge(ls[x],ls[y],L,mid);
			rs[rt]=Merge(rs[x],rs[y],mid+1,R);
		}
		return rt;
	}
	LL query(int rt,int L,int R,int xL,int xR){
		if (!rt||R<xL||L>xR)
			return 0;
		if (xL<=L&&R<=xR)
			return sum[rt];
		int mid=(L+R)>>1;
		return query(ls[rt],L,mid,xL,xR)+query(rs[rt],mid+1,R,xL,xR);
	}
}
int rt[N];
vector <int> son[N];
int Insert(string s,int id){
	int x=1;
	For(i,0,(int)s.size()-1){
		int t=s[i]-'a';
		if (!Next[x][t])
			Next[x][t]=++cnt;
		x=Next[x][t];
		Seg::Insert(rt[x],1,n,id,1);
	}
	return x;
}
void build(){
	queue <int> q;
	q.push(1);
	For(i,0,25)
		Next[0][i]=1;
	while (!q.empty()){
		int x=q.front();
		q.pop();
		For(i,0,25){
			if (!Next[x][i]){
				Next[x][i]=Next[Fail[x]][i];
				continue;
			}
			int y=Next[x][i];
			Fail[y]=Next[Fail[x]][i];
			son[Fail[y]].pb(y);
			q.push(y);
		}
	}
}
void dfs(int x){
	for (auto y : son[x]){
		dfs(y);
		rt[x]=Seg::Merge(rt[x],rt[y],1,n);
	}
}
int main(){
	n=read(),q=read();
	For(i,1,n){
		cin>>s[i];
		pos[i]=Insert(s[i],i);
	}
	build();
	dfs(1);
	while (q--){
		int L=read(),R=read(),k=read();
		cout<<Seg::query(rt[pos[k]],1,n,L,R)<<endl;
	}
	return 0;
}