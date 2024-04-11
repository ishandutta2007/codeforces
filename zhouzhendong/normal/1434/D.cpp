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
#define pb(x) push_back(x)
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
//int md(LL x){
//	return (x%mod+mod)%mod;
//}
const int N=500005*2;
int n,m;
struct Edge{
	int x,y,z;
}E[N];
vector <pii> e[N];
int tp[N],dep[N];
int dfn[N],I[N],O[N],dfc=0;
int _I[N],II[N],_O[N],Time=0;
int fa[N];
void dfs(int x,int pre,int t,int d){
	fa[x]=pre,tp[x]=t,dep[x]=d;
	dfn[++dfc]=x;
	I[x]=dfc;
	_I[x]=++Time;
	II[Time]=x;
	for (auto E : e[x]){
		int y=E.fi;
		if (y!=pre){
			dfs(y,x,t^E.se,d+1);
			dfn[++dfc]=x;
		}
	}
	O[x]=dfc;
	_O[x]=Time;
}
int st[N][20];
int Log[N];
int qst(int L,int R){
	int d=Log[R-L+1];
//	outvals(L,R,st[L+(1<<d)-1][d],st[R][d]);
	return min(st[L+(1<<d)-1][d],st[R][d]);
}
int getlca(int x,int y){
	if (I[x]>I[y])
		swap(x,y);
	return qst(I[x],I[y]);
}
//int getlca(int x,int y){
//	int res=_getlca(x,y);
//	outvals(x,y,res);
//	return res;
//}
int dis(int x,int y){
	if (!x||!y)
		return -1;
	return dep[x]+dep[y]-getlca(x,y)*2;
}
namespace seg{
	const int S=N*4;
	struct Node{
		int fi,se,len;
		Node(){}
		Node(int _x,int _y){
			fi=_x,se=_y;
			len=dis(fi,se);
		}
		Node(int _x,int _y,int _len){
			fi=_x,se=_y;
			len=_len;
		}
	}v0[S],v1[S];
	int tag[S];
	Node gao(Node a,Node b){
		int da=a.len;
		int db=b.len;
		int d00=dis(a.fi,b.fi);
		int d01=dis(a.fi,b.se);
		int d10=dis(a.se,b.fi);
		int d11=dis(a.se,b.se);
		int mxd=max(da,max(db,max(d00,max(d01,max(d10,d11)))));
		if (da==mxd)
			return a;
		else if (db==mxd)
			return b;
		else if (d00==mxd)
			return Node(a.fi,b.fi,mxd);
		else if (d01==mxd)
			return Node(a.fi,b.se,mxd);
		else if (d10==mxd)
			return Node(a.se,b.fi,mxd);
		else
			return Node(a.se,b.se,mxd);
	}
	void pushup(int rt){
		int ls=rt<<1,rs=ls|1;
		v0[rt]=gao(v0[ls],v0[rs]);
		v1[rt]=gao(v1[ls],v1[rs]);
	}
	void build(int rt,int L,int R){
		if (L==R){
			int x=II[L];
			v0[rt]=Node(x,x),v1[rt]=Node(0,0);
			if (tp[x])
				swap(v0[rt],v1[rt]);
			return;
		}
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		pushup(rt);
	}
	void pushdown(int rt){
		if (tag[rt]){
			int ls=rt<<1,rs=ls|1;
			tag[ls]^=1,tag[rs]^=1;
			swap(v0[ls],v1[ls]);
			swap(v0[rs],v1[rs]);
			tag[rt]=0;
		}
	}
	void update(int rt,int L,int R,int xL,int xR){
		if (R<xL||L>xR)
			return;
		if (xL<=L&&R<=xR){
			tag[rt]^=1;
			swap(v0[rt],v1[rt]);
			return;
		}
		pushdown(rt);
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		update(ls,L,mid,xL,xR);
		update(rs,mid+1,R,xL,xR);
		pushup(rt);
	}
	int query(){
		return max(v0[1].len,v1[1].len);
	}
//	void otp(int rt,int L,int R){
//		if (rt==1)
//			outtag();
//	}
}
int main(){
	n=read();
//	n=5e5;
	For(i,1,n-1){
		int x=read(),y=read(),z=read();
//		int x=i,y=i+1,z=1;
		E[i]={x,y,z};
		e[x].pb(mp(y,z));
		e[y].pb(mp(x,z));
	}
	dfs(1,0,0,1);
//	outarr(dep,1,n);
//	outarr(dfn,1,dfc);
	dep[0]=1e9;
	For(i,1,dfc){
		st[i][0]=dep[dfn[i]];
		For(j,1,19){
			st[i][j]=st[i][j-1];
			if (i-(1<<(j-1))>0)
				st[i][j]=min(st[i][j],st[i-(1<<(j-1))][j-1]);
		}
//		outval(i);
//		outarr(st[i],0,4);
	}
	For(i,2,dfc)
		Log[i]=Log[i>>1]+1;
	seg::build(1,1,n);
	int m=read();
//	int m=500000;
	while (m--){
		int id=read();
//		int id=2333;
		int x=E[id].x,y=E[id].y;
		if (dep[x]<dep[y])
			swap(x,y);
		seg::update(1,1,n,_I[x],_O[x]);
		printf("%d\n",max(0,seg::query()));
	}
	return 0;
}