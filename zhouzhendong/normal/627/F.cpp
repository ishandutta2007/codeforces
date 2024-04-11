#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
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
int n,s0,t0,s,t,tp;
vi e[N],ch[N];
int a[N],b[N],c[N],f[N];
deque <int> id;
int find(int *a,int v){
	For(i,1,n)
		if (a[i]==v)
			return i;
	return 0;
}
int check(int *a,int *b){
	For(i,1,n)
		if (a[i]!=b[i])
			return 0;
	return 1;
}
int fa[N],dep[N],anc[N][20];
void dfs(int x,int pre=0,int d=0){
	anc[x][0]=fa[x]=pre,dep[x]=d;
	For(i,1,19)
		anc[x][i]=anc[anc[x][i-1]][i-1];
	for (auto y : e[x])
		if (y!=pre)
			dfs(y,x,d+1);
}
int LCA(int x,int y){
	if (dep[x]<dep[y])
		swap(x,y);
	Fod(i,19,0)
		if (dep[x]-(1<<i)>=dep[y])
			x=anc[x][i];
	if (x==y)
		return x;
	Fod(i,19,0)
		if (anc[x][i]!=anc[y][i])
			x=anc[x][i],y=anc[y][i];
	return fa[x];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
void NO(){
	puts("-1");
	exit(0);
}
vi cid;
void dfs_ch(int x,int pre=0){
	cid.pb(x);
	if (x==t)
		tp=(int)cid.size()-1;
	for (auto y : ch[x])
		if (y!=pre)
			dfs_ch(y,x);
}
int main(){
	n=read();
	For(i,1,n)
		a[i]=read();
	For(i,1,n)
		b[i]=read();
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	s0=find(a,0),t0=find(b,0);
	dfs(t0);
	For(i,1,n)
		c[i]=a[i];
	for (int x=s0;x!=t0;x=fa[x])
		id.pb(x),swap(c[x],c[fa[x]]);
	id.pb(t0);
	if (check(b,c))
		printf("0 %d\n",dep[s0]),exit(0);
	deque <int> ID=id;
	#define S (int)id.size()
	while (S>=2&&b[id[0]]==c[id[0]])
		id.pop_front();
	while (S>=2&&b[id[S-2]]==c[id[S-2]])
		id.pop_back();
	assert(!id.empty());
	#undef S
	s=id.front(),t=id.back();
	if (b[id[0]]!=c[id[0]]){
		for (auto i : id)
			f[i]=1;
	}
	else {
		int x=-1;
		For(i,1,n)
			if (b[i]!=c[i])
				if (x==-1||dis(i,t0)<dis(x,t0))
					x=i;
		assert(x!=-1);
		for (auto y : e[x])
			if (dis(y,t0)<dis(x,t0)){
				f[s=t=y]=1;
				break;
			}
		assert(s!=0);
	}
	For(i,1,n)
		if (b[i]!=c[i])
			f[i]=1;
	For(i,1,n)
		for (auto j : e[i])
			if (f[i]&&f[j])
				ch[i].pb(j);
	int A=-1,B=-1;
	For(i,1,n)
		if (ch[i].size()>2)
			NO();
		else if (ch[i].size()==1){
			if (A==-1)
				A=i;
			else if (B==-1)
				B=i;
			else
				NO();
		}
		else if (ch[i].empty()&&f[i])
			NO();
	if (B==-1)
		NO();
	if (dis(B,s)<dis(B,t))
		swap(A,B);
	b[t]=c[t]=0;
	dfs_ch(A);
	vi pos(n+1,-1);
	int cs=(int)cid.size();
	For(i,0,cs-1)
		pos[b[cid[i]]]=i;
	int d=-1;
	For(i,0,cs-1){
		if (cid[i]==t)
			continue;
		int p0=pos[c[cid[i]]],p1=i;
		p0-=p0>=tp,p1-=p1>=tp;
		int di=(p1-p0+cs-1)%(cs-1);
		if (d!=-1&&d!=di)
			NO();
		d=di;
	}
	int dst=dis(s,t);
	LL d1=(LL)cs*d+dst,d2=(LL)cs*(cs-1)-d1;
	LL ans=dis(s0,s)+dis(t0,t)+min(d1,d2);
	cout<<min(A,B)<<" "<<max(A,B)<<" "<<ans<<endl;
	return 0;
}