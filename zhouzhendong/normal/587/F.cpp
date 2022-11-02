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
const int N=100005;
int n,Q,B,bc;
string s[N];
int pos[N];
namespace blk{
	int a[N+400],b[260];
	void Add(int x,int d){
		int id=x/B,t=id*B+B-1;
		For(i,x,t)
			a[i]+=d;
		For(i,id,bc)
			b[i+1]+=d;
	}
	int Ask(int x){
		int id=x/B;
		return b[id]+a[x];
	}
	int Query(int L,int R){
		return Ask(R)-Ask(L-1);
	}
}
int *que;
namespace AC{
	int cnt;
	int Next[N][26],fa[N],Fail[N];
	vector <int> lid[N],vid[N],e[N];
	void init(){
		cnt=1;
		For(i,0,25)
			Next[0][i]=1;
	}
	int Ins(string &s,int ID){
		int len=s.size();
		int x=1;
		For(i,0,len-1){
			int k=s[i]-'a';
			if (!Next[x][k])
				Next[x][k]=++cnt,fa[cnt]=x;
			x=Next[x][k];
			vid[x].pb(ID);
		}
		lid[x].pb(ID);
		return x;
	}
	void Build(){
		static int q[N];
		int head=0,tail=0;
		Fail[0]=1,Fail[1]=0;
		q[++tail]=1;
		while (head<tail){
			int x=q[++head];
			For(i,0,25){
				if (!Next[x][i]){
					Next[x][i]=Next[Fail[x]][i];
					continue;
				}
				int y=Next[x][i];
				Fail[y]=Next[Fail[x]][i];
				e[Fail[y]].pb(y);
				q[++tail]=y;
			}
		}
		que=q;
	}
}
struct Query{
	int L,R,k;
	LL ans;
}q[N];
vector <int> qid[N];
int bstr[N];
LL bres[260][N];
void SolveBig(){
	static int a[N];
	int bcnt=0;
	For(i,1,n)
		if ((int)s[i].size()>B){
			bstr[i]=++bcnt;
			clr(a);
			for (int x=pos[i];x!=1;x=AC::fa[x])
				a[x]++;
			Fod(j,AC::cnt,1)
				a[AC::Fail[que[j]]]+=a[que[j]];
			For(j,1,n)
				bres[bcnt][j]=bres[bcnt][j-1]+a[pos[j]];
		}
}
void dfs(int x){
	for (auto i : AC::lid[x])
		blk::Add(i,1);
	for (auto y : AC::vid[x])
		for (auto i : qid[y])
			q[i].ans+=blk::Query(q[i].L,q[i].R);
	for (auto y : AC::e[x])
		dfs(y);
	for (auto i : AC::lid[x])
		blk::Add(i,-1);
}
int main(){
	n=read(),Q=read();
	B=400;
	bc=n/B;
	AC::init();
	For(i,1,n){
		cin>>s[i];
		pos[i]=AC::Ins(s[i],i);
	}
	AC::Build();
	SolveBig();
	For(i,1,Q){
		q[i].L=read(),q[i].R=read(),q[i].k=read();
		q[i].ans=0;
		if ((int)s[q[i].k].size()<=B)
			qid[q[i].k].pb(i);
		else
			q[i].ans=bres[bstr[q[i].k]][q[i].R]
					-bres[bstr[q[i].k]][q[i].L-1];
	}
	dfs(1);
	For(i,1,Q)
		printf("%lld\n",q[i].ans);
	return 0;
}