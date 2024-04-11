#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
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
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
//void ckmax(int &x,int y){
//	if (x<y)
//		x=y;
//}
//void ckmin(int &x,int y){
//	if (x>y)
//		x=y;
//}
const int N=200005;
int n,cnt;
char s[N];
int c[N];
void upd(int x,int v){
	for (;x<=n;x+=x&-x)
		c[x]+=v;
}
int ask(int x){
	int ans=0;
	for (;x;x-=x&-x)
		ans+=c[x];
	return ans;
}
int a[N],p[N];
int cntp[26];
set <int> dl[26],dr[26];
int pre[N],nxt[N];
void Cut(int x,int y){
	if (a[x]!=a[y]&&x!=0&&y!=cnt+1){
		dl[a[x]].erase(x);
		dr[a[y]].erase(y);
	}
}
void Link(int x,int y){
	if (a[x]!=a[y]&&x!=0&&y!=cnt+1){
		dl[a[x]].insert(x);
		dr[a[y]].insert(y);
	}
}
vector <pii> res;
void gao(int L,int R){
	int l=ask(L-1)+1,r=ask(R);
	if (l<=r){
		res.pb(mp(l,r));
		upd(L,-(r-l+1));
	}
	else
		assert(0);
}
void fuck(int x,int y){
	int lx=pre[x],ry=nxt[y];
	Cut(x,y),Cut(lx,x),Cut(y,ry);
	gao(p[x]+1,p[y]);
	cntp[a[x]]--,cntp[a[y]]--;
	nxt[lx]=ry,pre[ry]=lx;
	Link(lx,ry);
}
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,0,n+1)
		c[i]=0;
	For(i,1,n)
		upd(i,1);
	cnt=0;
	clr(cntp);
	For(i,1,n-1)
		if (s[i]==s[i+1]){
			cnt++;
			a[cnt]=s[i]-'a';
			p[cnt]=i;
			nxt[cnt-1]=cnt,pre[cnt]=cnt-1;
			cntp[a[cnt]]++;
		}
	p[0]=0,p[cnt+1]=n;
	nxt[cnt]=cnt+1,pre[cnt+1]=cnt;
	pre[0]=nxt[cnt+1]=0;
	For(i,0,25)
		dl[i].clear(),dr[i].clear();
	For(i,1,cnt-1)
		Link(i,i+1);
	res.clear();
	while (1){
		int mx=-1;
		For(i,0,25)
			if (!~mx||cntp[i]>cntp[mx])
				mx=i;
		if (dl[mx].size()){
			int x=*dl[mx].begin(),y=nxt[x];
			fuck(x,y);
		}
		else if (dr[mx].size()){
			int x=*dr[mx].begin(),y=pre[x];
			fuck(y,x);
		}
		else
			break;
	}
	for (int i=nxt[0];i;i=nxt[i])
		gao(1,p[i]);
	printf("%d\n",(int)res.size());
	for (auto i : res)
		printf("%d %d\n",i.fi,i.se);
}
int main(){
	int T=read();
	For(_,1,T)
		solve();
	return 0;
}