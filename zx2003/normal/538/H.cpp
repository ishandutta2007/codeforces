#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=1e9;
struct seg{
	int l,r;
	inline void in(){scanf("%d%d",&l,&r);}
	inline void operator&=(const seg&rhs){l=max(l,rhs.l);r=min(r,rhs.r);}
	inline seg operator&(const seg&rhs)const{return (seg){max(rhs.l,l),min(rhs.r,r)};}
	inline bool operator&&(const seg&rhs)const{return max(l,rhs.l)<=min(r,rhs.r);}
	inline seg operator|(const seg&rhs)const{return (seg){min(rhs.l,l),max(rhs.r,r)};}
	inline seg operator+(const seg&rhs)const{return (seg){l+rhs.l,r+rhs.r};}
	inline bool empty(){return l>r;}
	inline bool operator[](const int&i)const{return l<=i && i<=r;}
}A,a[N],s[2],ss[N][2];
const seg I=(seg){0,inf};
int n,m,i,j,x,y,col[N];
vector<int>e[N],vv[N][2];
inline void E(){puts("IMPOSSIBLE");exit(0);}
void dfs(int u,int c){
	s[col[u]=c]&=a[u];vv[::i][c].push_back(u);
	for(int v:e[u])if(col[v]==-1)dfs(v,c^1);else if(col[v]==col[u])E();
}
struct eve{
	int t,k,w;seg v;
	bool operator<(const eve&rhs)const{return t<rhs.t;}
}ev[N*6];int xb,tot,nw;
inline void ins(seg a,seg b,int w){
	ev[++xb]=(eve){a.l,1,w,b};ev[++xb]=(eve){a.r+1,-1,-w,b};
}
multiset<int>S[2];
inline void add(seg v,int k){
	if(k==1)S[0].insert(v.l),S[1].insert(v.r);
		else S[0].erase(S[0].find(v.l)),S[1].erase(S[1].find(v.r));
}
bool beg[N];
char ans[N];
inline void O(int n1,int n2){
	printf("POSSIBLE\n%d %d\n",n1,n2);
	assert(A[n1+n2]);
	for(i=1;i<=n;++i)if(beg[i]){
		if(e[i].empty())ans[i]=a[i][n1]?'1':'2';else{
			int o=ss[i][1][n1] && ss[i][0][n2];
			for(int x:vv[i][o])ans[x]='1',assert(a[x][n1]);
			for(int x:vv[i][!o])ans[x]='2',assert(a[x][n2]);
		}
	}
	puts(ans+1);
	exit(0);
}
int main(){
	A.in();scanf("%d%d",&n,&m);for(i=1;i<=n;++i)a[i].in();
	for(i=1;i<=m;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	memset(col+1,-1,n<<2);
	for(i=1;i<=n;++i)if(col[i]==-1){
		s[0]=s[1]=I;beg[i]=1;
		dfs(i,0);
		if(s[0].empty() || s[1].empty())E();
		if(e[i].empty()){
			if(a[i].l>0)ins((seg){0,a[i].l-1},a[i],0);
			if(a[i].r<inf)ins((seg){a[i].r+1,inf},a[i],0);
			ins(a[i],I,0);
		}else if(++tot,s[0] && s[1]){
			seg z=s[0]&s[1],y=s[0]|s[1];
			if(y.l<z.l)ins((seg){y.l,z.l-1},s[0].l>s[1].l?s[0]:s[1],1);
			ins(z,y,1);
			if(z.r<y.r)ins((seg){z.r+1,y.r},s[0].r>s[1].r?s[1]:s[0],1);
		}else ins(s[0],s[1],1),ins(s[1],s[0],1);
		ss[i][0]=s[0];ss[i][1]=s[1];
	}
	sort(ev+1,ev+xb+1);
	for(i=1;i<=xb;i=j){
		for(j=i;ev[j].t==ev[i].t;++j)nw+=ev[j].w,add(ev[j].v,ev[j].k);
		seg z=S[0].empty()?I:(seg){*S[0].rbegin(),*S[1].begin()},y=(seg){ev[i].t,ev[j].t-1};
		if(nw==tot && j<=xb && !z.empty()){
			if(((seg){y.l,y.l}+z) && A)O(y.l,(z&(A+(seg){-y.l,-y.l})).l);
			if(((seg){y.r,y.r}+z) && A)O(y.r,(z&(A+(seg){-y.r,-y.r})).l);
			swap(y,z);
			if(((seg){y.l,y.l}+z) && A)O(y.l,(z&(A+(seg){-y.l,-y.l})).l);
			if(((seg){y.r,y.r}+z) && A)O(y.r,(z&(A+(seg){-y.r,-y.r})).l);
		}
	}
	E();
	return 0;
}