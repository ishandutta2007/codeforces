#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof(x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define y0 _z_y0
#define y1 _z_y1
#define x0 _z_x0
#define x1 _z_x1
#define pb push_back
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
void enable_comma(){}
string tostring(char c){
	string s="";
	s+=c;
	return s;
}
string tostring(string s){
	return "\""+s+"\"";
}
string tostring(const char *c){
	return tostring((string)c);
}
string tostring(long long x){
	if (x<0)
		return "-"+tostring(-x);
	if (x>9)
		return tostring(x/10)+tostring(char('0'+x%10));
	else
		return tostring(char('0'+x));
}
string tostring(int x){
	return tostring((long long)x);
}
string tostring(unsigned long long x){
	if (x>9)
		return tostring((long long)(x/10))+tostring(char('0'+x%10));
	else
		return tostring(char('0'+x));
}
string tostring(unsigned x){
	return tostring((long long)x);
}
string tostring(double x){
	static char res[114];
	sprintf(res,"%lf",x);
	string s=tostring(res);
	return s.substr(1,(int)s.size()-2);
}
string tostring(long double x){
	return tostring((double)x);
}
template <class A,class B> string tostring(pair <A,B> p){
	return "("+tostring(p.fi)+","+tostring(p.se)+")";
}
template <class T> string tostring(T v){
	string res="";
	for (auto p : v)
		res+=(res.size()?",":"{")+tostring(p);
	return res.size()?res+"}":"{}";
}
template <class A> string tostring(A* a,int L,int R){
	return tostring(vector <A>(a+L,a+R+1));
};
template <class A> string tostring(A a,int L,int R){
	return tostring(a.data(),L,R);
}
string tostrings(){
	return "";
}
template <typename Head,typename... Tail>
string tostrings(Head H,Tail... T){
	return tostring(H)+" "+tostrings(T...);
}
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
#ifdef zzd
	#define outval(x) cerr<<#x" = "<<tostring(x)<<endl
	#define outvals(...) cerr<<"["<<#__VA_ARGS__<<"]: "<<\
								tostrings(__VA_ARGS__)<<endl
	#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
	#define outsign(x) cerr<<"<"#x">"<<endl
	#define outarr(a,L,R) cerr<<#a"["<<(L)<<".."<<(R)<<"] = "<<\
								tostring(a,L,R)<<endl
#else
	#define outval(x) enable_comma()
	#define outvals(...) enable_comma()
	#define outtag(x) enable_comma()
	#define outsign(x) enable_comma()
	#define outarr(a,L,R) enable_comma()
#endif
#ifdef ONLINE_JUDGE
	#ifdef assert
		#undef assert
	#endif
	#define assert(x) (!(x)?\
			cout<<"Assertion failed!"<<endl<<\
			"function: "<<__FUNCTION__<<endl<<\
			"line: "<<__LINE__<<endl<<\
			"expression: "<<#x<<endl,exit(3),0:1)
#endif
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
template <class T> void ckmax(T &x,const T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T y){
	if (x>y)
		x=y;
}
const int mod=998244353;
int Pow(int x,LL y){
	y=(y%(mod-1)+(mod-1))%(mod-1);
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
int md(LL x){
	return (x%mod+mod)%mod;
}
const int N=100005,INF=1e9;
const LL LLINF=5e9;
int n,m;
multiset <pair <int,pii> > S;
multiset <pii> e[N];
map <int,int> wei[N];
vi fuck;
struct seg{
	int ls,rs,v;
}a[N*18*6];
int cnt=0;
int rt[N];
void insert(int &rt,int L,int R,int x){
	if (!rt)
		rt=++cnt,a[rt].v=0;
	a[rt].v++;
	if (L==R)
		return;
	int mid=(L+R)>>1;
	if (x<=mid)
		insert(a[rt].ls,L,mid,x);
	else
		insert(a[rt].rs,mid+1,R,x);
}
void remove(int &rt,int L,int R,int x){
	assert(rt);
	a[rt].v--;
	if (L==R)
		return;
	int mid=(L+R)>>1;
	if (x<=mid)
		remove(a[rt].ls,L,mid,x);
	else
		remove(a[rt].rs,mid+1,R,x);
}
LL qmin(int rt1,int rt2,int rt3,int L,int R,int val){
	int t=L<=val&&val<=R;
	if (a[rt1].v-a[rt2].v-a[rt3].v+t<=0)
		return LLINF;
	if (L==R)
		return fuck[L];
	int mid=(L+R)>>1;
	if (a[a[rt1].ls].v-a[a[rt2].ls].v-a[a[rt3].ls].v+(L<=val&&val<=mid)>0)
		return qmin(a[rt1].ls,a[rt2].ls,a[rt3].ls,L,mid,val);
	else
		return qmin(a[rt1].rs,a[rt2].rs,a[rt3].rs,mid+1,R,val);
}
multiset <LL> three;
LL calc_three(int x){
	if (e[x].size()<3)
		return LLINF;
	auto it=e[x].begin();
	LL res=0;
	for (int i=0;i<3;i++){
		res+=it->fi;
		it++;
	}
	return res;
}
int get_fw(int w){
	return lower_bound(fuck.begin(),fuck.end(),w)-fuck.begin();
}
void add_edge(int x,int y,int w){
	int fw=get_fw(w);
	three.erase(three.find(calc_three(x)));
	three.erase(three.find(calc_three(y)));
	e[x].insert(mp(w,y));
	e[y].insert(mp(w,x));
	S.insert(mp(w,mp(x,y)));
	S.insert(mp(w,mp(y,x)));
	insert(rt[x],0,fuck.size()-1,fw);
	insert(rt[y],0,fuck.size()-1,fw);
	insert(rt[0],0,fuck.size()-1,fw);
	wei[x][y]=wei[y][x]=w;
	three.insert(calc_three(x));
	three.insert(calc_three(y));
}
void del_edge(int x,int y){
	three.erase(three.find(calc_three(x)));
	three.erase(three.find(calc_three(y)));
	int w=wei[x][y],fw=get_fw(w);
	e[x].erase(e[x].find(mp(w,y)));
	e[y].erase(e[y].find(mp(w,x)));
	S.erase(S.find(mp(w,mp(y,x))));
	S.erase(S.find(mp(w,mp(x,y))));
	remove(rt[x],0,fuck.size()-1,fw);
	remove(rt[y],0,fuck.size()-1,fw);
	remove(rt[0],0,fuck.size()-1,fw);
	three.insert(calc_three(x));
	three.insert(calc_three(y));
}
void query(){
	LL ans=LLINF;
	ckmin(ans,*three.begin());
	outval(ans);
	auto E=*S.begin();
	int w=E.fi,x=E.se.fi,y=E.se.se;
	ckmin(ans,w+qmin(rt[0],rt[x],rt[y],0,fuck.size()-1,get_fw(w)));
	outval(ans);
	vector <pair <LL,int> > xm,ym;
	for (auto it=e[x].begin();it!=e[x].end()&&xm.size()<3;it++)
		xm.pb(*it);
	for (auto it=e[y].begin();it!=e[y].end()&&ym.size()<3;it++)
		ym.pb(*it);
	outvals(x,y);
	outval(xm);outval(ym);
	for (auto p1 : xm)
		for (auto p2 : ym)
			if (p1.se!=p2.se&&p1.se!=y&&p2.se!=x)
				ckmin(ans,p1.fi+p2.fi);
	outval(ans);
	printf("%lld\n",ans);
}
struct pre_e{
	int x,y,w;
}pe[N];
struct pre_q{
	int tp,x,y,w;
}pq[N];
int main(){
	three.insert(LLINF);
	n=read(),m=read();
	For(i,1,n)
		three.insert(LLINF);
	For(i,1,m){
		int x=read(),y=read(),w=read();
		pe[i]={x,y,w};
		fuck.pb(w);
	}
	int q=read();
	For(i,1,q){
		int tp=read(),x=read(),y=read();
		if (tp==0)
			pq[i]={tp,x,y};
		else {
			int w=read();
			pq[i]={tp,x,y,w};
			fuck.pb(w);
		}
	}
	sort(fuck.begin(),fuck.end());
	fuck.resize(unique(fuck.begin(),fuck.end())-fuck.begin());
	For(i,1,m){
		add_edge(pe[i].x,pe[i].y,pe[i].w);
	}
	query();
	For(i,1,q){
		int tp=pq[i].tp,x=pq[i].x,y=pq[i].y;
		if (tp==0)
			del_edge(x,y);
		else
			add_edge(x,y,pq[i].w);
		query();
	}
	return 0;
}