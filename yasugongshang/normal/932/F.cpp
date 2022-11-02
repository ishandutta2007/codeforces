#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=100005,M=5000000;
int n,nodecnt,a[N],b[N],lson[M],rson[M],rt[N];
vector<int> v[N];
ll dp[N];
struct line{
	int k; ll b; 
	inline ll get(ll x){
		return k*x+b;
	}
}tree[M];
inline bool cmp(line a,line b,int pos){
	return a.get(pos)>b.get(pos);
}
ll query(int l,int r,int pos,int nod){
	if(!nod)return 4e18;
	if(l==r)return tree[nod].get(pos);
	int mid=(l+r)>>1; ll t;
	if(pos<=mid)t=query(l,mid,pos,lson[nod]); else if(pos>mid)t=query(mid+1,r,pos,rson[nod]);
	return min(t,tree[nod].get(pos));
}
void insert(int l,int r,line x,int &nod){
	if(!nod){nod=++nodecnt; tree[nod]=x; return;}
	if(cmp(tree[nod],x,l))swap(tree[nod],x);
	if(l==r||tree[nod].k==x.k)return;
	int mid=(l+r)>>1; double X=(double)(tree[nod].b-x.b)/(x.k-tree[nod].k);
	if(X<l||X>r)return; 
	if(X<=mid)insert(l,mid,tree[nod],lson[nod]),tree[nod]=x;
	else insert(mid+1,r,x,rson[nod]);
}
inline int mer(int a,int b,int l,int r){
	if(!a||!b)return a|b;
	insert(l,r,tree[b],a);
	int mid=(l+r)>>1;
	lson[a]=mer(lson[a],lson[b],l,mid);
	rson[a]=mer(rson[a],rson[b],mid+1,r);
	return a;
}
void dfs(int p,int fa){
	for(unsigned i=0;i<v[p].size();i++)if(v[p][i]!=fa){dfs(v[p][i],p); rt[p]=mer(rt[p],rt[v[p][i]],-N,N);}
	dp[p]=rt[p]==0?0:query(-N,N,a[p],rt[p]);
	insert(-N,N,(line){b[p],dp[p]},rt[p]);
}
int main(){
	n=read(); 
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<n;i++){
		int a=read(),b=read();
		v[a].push_back(b); v[b].push_back(a);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		wri(dp[i]); 
	}
}