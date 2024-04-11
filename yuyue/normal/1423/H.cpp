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
const int N = 5e5+10;
int n,m,k,fa[N],sz[N],top;
struct Stack{int x,y,add;} st[N<<3];
vector<int> t[N<<3];
struct QQ{
	int op,x,y,day;
}b[N];
int findfa(int x){
	while(x != fa[x]) x = fa[x];
	return fa[x];
}
void merge(int x,int y)
{
	int fx = findfa(x),fy = findfa(y);
	if(sz[fx] > sz[fy]) swap(fx,fy);
	sz[fy]+=sz[fx];
	st[++top] = (Stack){fx,fy,0};
	fa[fx] = fy;
}
void update(int u,int l,int r,int L,int R,int x)
{
	if(l > R || r < L) return;
	if(L <= l && r <= R) {t[u].pb(x);return;}
	int mid = l + r >> 1;
	update(u<<1,l,mid,L,R,x);
	update(u<<1|1,mid+1,r,L,R,x);
}
int ans[N];
void solve(int u,int l,int r)
{
//	debug();
	int lasttop = top;
	for(int i = 0;i < t[u].size();i++)
	{
		int x = findfa(b[t[u][i]].x);
		int y = findfa(b[t[u][i]].y);
		if(x == y) continue;
		merge(x,y);
	}
	if (l==r){
		if (b[l].op==2){
//			cout<<"fuck\n";
			ans[l]=sz[findfa(b[l].x)];
		}
		while(top > lasttop){
			sz[st[top].y] -= sz[st[top].x];
			fa[st[top].x] = st[top].x;
			top--;
		}
		return ;
	}
	int mid = l + r >> 1;
	solve(u<<1,l,mid);
	solve(u<<1|1,mid+1,r);
	while(top > lasttop){
		sz[st[top].y] -= sz[st[top].x];
		fa[st[top].x] = st[top].x;
		top--;
	}
}
int ed[N];
int main(){
	n = read(); m = read(); k = read();
	int now=1;
	for(int i = 1;i <= m;i++){
		b[i].op=read();
		b[i].day=now;
		if (b[i].op==1){
			b[i].x=read();
			b[i].y=read();
		}
		else if (b[i].op==2){
			b[i].x=read();
		}
		else ed[now]=i,now++;
	}
	ed[now]=m;
	for(int i = 1;i <= n;i++) fa[i] = i,sz[i] = 1;
	F(i,1,m){
		if (b[i].op==1){
			int r=min(now,b[i].day+k-1);
//			cout<<i<<" "<<ed[r]<<"   hh\n";
			update(1,1,m,i,ed[r],i);
		}
	}
	solve(1,1,m);
	F(i,1,m){
		if (b[i].op==2){
			cout<<ans[i]<<"\n";
		}
	}
	return 0;
}