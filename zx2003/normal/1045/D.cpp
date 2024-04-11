//cwystc <-->   --by cwy
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const double PI=acos(-1);
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define Rep(i,a,b) for (int i=(a);i<(b);i++)
#define Per(i,a,b) for (int i=(a);i>(b);i--)
#define travel_set(it,a) for (set<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_map(it,a) for (map<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_vec(it,a) for (vector<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define p(x) cout << x << endl;
#define def cout << "find" << endl;
#define what_is(x) cout << #x << " is " << x << endl;
template <class T>T sqr(T x){return x*x;}
template <class T>T alex(T x){return (x>0)?x:-x;}
template <class T>void read(T&x){
	x=0;T f=1;char ch=getchar();
	while ((ch<48||ch>57)&&ch!=45)ch=getchar();
	if (ch==45)f=-1,ch=getchar();
	while (ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();
	x*=f;
}

//-------------------------------------------------head-------------------------------------------------

#define maxn 100005
int n;
double a[maxn];
vector<int>E[maxn];
int x[maxn],y[maxn];

double solve(){
	double res=0.0;
	Rep(i,0,n)res+=a[i];
	Rep(i,1,n)res-=a[x[i]]*a[y[i]];
	return res;
}
struct Tree{
	int l,r;double v;
}T[maxn<<2];
void build(int rot,int l,int r){
	T[rot].l=l;T[rot].r=r;if (l==r)return;int mid=(l+r)>>1;
	build(rot<<1,l,mid);build(rot<<1|1,mid+1,r);
}
void update(int rot){T[rot].v=T[rot<<1].v+T[rot<<1|1].v;}
void change(int rot,int pos,double v){
	if (T[rot].l==T[rot].r){T[rot].v=v;return;}int mid=(T[rot].l+T[rot].r)>>1;
	if (pos<=mid)change(rot<<1,pos,v);else change(rot<<1|1,pos,v);update(rot);
}
double query(int rot,int l,int r){
	if (l>r)return 0;
	if (T[rot].l==l&&T[rot].r==r)return T[rot].v;int mid=(T[rot].l+T[rot].r)>>1;
	if (r<=mid)return query(rot<<1,l,r);else if (l>mid)return query(rot<<1|1,l,r);
	else return query(rot<<1,l,mid)+query(rot<<1|1,mid+1,r);
}
int que[maxn],f[maxn];bool vis[maxn];
int l[maxn],r[maxn];
int ind[maxn];
void bfs(){
	que[1]=0;vis[0]=true;ind[0]=1;
	int head=0,tail=1;
	while (head!=tail){
		head++;int x=que[head];l[x]=tail+1;
		Rep(i,0,E[x].size())if (!vis[E[x][i]]){
			f[E[x][i]]=x;que[++tail]=E[x][i];vis[E[x][i]]=true;ind[E[x][i]]=tail;
		}
		r[x]=tail;
	}
	// Rep(i,0,n)printf("%d %d\n",l[i],r[i]);
}
double get(int x){
	if (x==0)return query(1,l[x],r[x]);
	else return query(1,l[x],r[x])+a[f[x]];
}
int main(){
	read(n);
	Rep(i,0,n)scanf("%lf",&a[i]),a[i]=1.0-a[i];
	Rep(i,1,n){
		read(x[i]),read(y[i]);
		E[x[i]].pb(y[i]);
		E[y[i]].pb(x[i]);
	}
	int q;read(q);
	double res=solve();build(1,1,n);bfs();
	Rep(i,0,n)change(1,ind[i],a[i]);

	rep(i,1,q){
		int x;double p;read(x);scanf("%lf",&p);
		// printf("%lf\n",solve());
		res-=a[x];res+=a[x]*get(x);
		a[x]=1.0-p;
		res+=a[x];res-=a[x]*get(x);
		change(1,ind[x],a[x]);
		printf("%lf\n",res);
	}
	return 0;
}