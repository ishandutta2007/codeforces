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
const int N=1e5+5,mod=1e9+7;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
int n,m;
vector <pair <int,int> > e[N];
vector <pair <int,int> > v;
int a,b;
int Ins(int a,int b){
	if (a==-1)
		return -1;
	Fod(i,4,0){
		if (b>>i&1){
			if (!(a>>(i*5)&31)){
				For(j,0,i-1)
					if (b>>j&1)
						b^=a>>(j*5)&31;
				a^=b<<(i*5);
				For(j,i+1,4)
					if (a>>(j*5)>>i&1)
						a^=b<<(j*5);
				return a;
			}
			else {
				b^=a>>(i*5)&31;
			}
		}
	}
	return -1;
}
int vis[N];
int ww[N];
void out(int b){
	For(i,0,4)printf("%d ",b>>(i*5)&31);puts("");
}
unordered_map <int,int> id;
int st[400],cnt=0;
int trans[400][35];
void search(int d,int v){
	if (d<0){
		st[++cnt]=v;
		return;
	}
	search(d-1,v);
	For(i,d+1,4)
		if (v>>(i*5)>>d&1)
			return;
	For(i,(1<<d),(1<<(d+1))-1)
		search(d-1,v|i<<(d*5));
}
void getst(){
	search(4,0);
//	outval(cnt);
	id[-1]=-1;
	For(i,1,cnt)
		id[st[i]]=i;
	For(i,1,cnt){
		For(j,0,31)
			trans[i][j]=id[Ins(st[i],j)];
	}
}
int dep[N];
void dfs(int x,int pre,int w,int d=1){
	dep[x]=d;
	vis[x]=1;
	ww[x]=w;
	for (auto E : e[x]){
		int y=E.fi,v=E.se;
		if (y==pre)
			continue;
		if (!vis[y])
			dfs(y,x,w^v,d+1);
		else if (y==1&&pre!=1)
			a=w^v;
		else if (dep[y]<dep[x]){
//			outval(b),outval(st[trans[b][w^v^ww[y]]]);
//			outval(Ins(st[b],w^v^ww[y]));
			if (b!=-1)
				b=trans[b][w^v^ww[y]];
		}
	}
}
int f[400],g[400];
int main(){
	getst();
	n=read(),m=read();
	For(i,1,m){
		int x=read(),y=read(),w=read();
		e[x].pb(mp(y,w));
		e[y].pb(mp(x,w));
	}
	vis[1]=1;
	clr(f);
	f[id[0]]=1;
	for (auto E : e[1]){
		int i=E.fi;
		if (vis[i])
			continue;
		a=-1,b=id[0];
		dfs(i,1,E.se);
//		outval(i),outval(a),out(st[b]);
		if (b!=-1){
			clr(g);
			int bb=a>0&&trans[b][a]!=-1?trans[b][a]:-1;
//			out(st[bb]);
			For(s,1,cnt){
				if (!f[s])
					continue;
				Add(g[s],f[s]);
				int v=s,t;
				For(i,0,4){
					t=st[b]>>(i*5)&31;
					if (!t)
						continue;
					if ((v=trans[v][t])==-1)
						break;
				}
				if (v!=-1)
					Add(g[v],a!=-1?Add(f[s]<<1):f[s]);
				if (bb!=-1){
					int v=s,t;
//					outtag();out(st[s]);out(st[bb]);
					For(i,0,4){
						t=st[bb]>>(i*5)&31;
						if (!t)
							continue;
						if ((v=trans[v][t])==-1)
							break;
					}
					if (v!=-1)
						Add(g[v],f[s]);
				}
			}
			swap(f,g);
//			int ans=0;
//			For(i,1,cnt)
//				Add(ans,f[i]);
//			outval(ans);
		}
	}
	int ans=0;
	For(i,1,cnt)
		Add(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}