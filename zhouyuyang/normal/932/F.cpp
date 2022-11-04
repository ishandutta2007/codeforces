#include<bits/stdc++.h>
#define It set<P>::iterator
#define inf (1ll<<60)
#define ll long long 
#define N 100005
using namespace std;
struct P{
	ll x,y;
	ll operator *(const P &a)const{
		double dt=1.0*x*a.y-1.0*y*a.x;
		if (fabs(dt)>inf) return dt>0?1:-1;
		return x*a.y-y*a.x;
	}
	P operator -(const P &a)const{
		return (P){x-a.x,y-a.y};
	}
	bool operator <(const P &a)const{
		return x<a.x||(x==a.x&&y<a.y);
	}
};
set<P> s[N];
struct edge{int to,next;}e[N*2];
int a[N],b[N],sz[N];
int pos[N],head[N];
int n,tot;
ll f[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void insert(int x,P p){
	//puts("insert");
	if (s[x].size()<2){
		s[x].insert(p);
		return; 
	}
	It r=s[x].lower_bound(p),l=r,q;
	if (r!=s[x].end()&&!((*r<p)||(p<*r))) return;
	if (l!=s[x].begin()){
		l--;
		if (r!=s[x].end()&&(*r-*l)*(p-*l)>0) return;
		s[x].insert(p); q=l;
		for (;l!=s[x].begin();){
			q--;
			if ((*l-p)*(*q-p)<0) break;
			s[x].erase(l);
			l=q;
		}
	}
	if (r!=s[x].end()){
		q=r++;
		for (;r!=s[x].end();){
			if ((*r-p)*(*q-p)<0) break;
			s[x].erase(q); q=r++;
		}
	}
	//puts("insert1");
}
void merge(int x,int y){
	//puts("merge");
	for (It it=s[y].begin();it!=s[y].end();it++)
		insert(x,*it);
	//puts("merge1");
}
bool check(int p,int x,ll k){
	It it=s[p].lower_bound((P){x,inf});
	It l=it,r=it;
	if ((++r)==s[p].end()) return 0;
	if ((--l)==s[p].begin()) return 1;
	return (l->y-it->y)>k*(it->x-l->x);
}
ll calc(int p,int x,ll k){
	It it=s[p].lower_bound((P){x,-inf});
	It r=it; r++;
	if (r==s[p].end()) return 0;
	return it->y+it->x*k;
}
ll ask(int p,ll k){
	int l=-N,r=N;
	while (l<r){
		//printf("%d %d\n",l,r);
		int mid=(l+r)>>1;
		if (check(p,mid,k))
			l=mid+1;
		else r=mid;
	}
	return calc(p,l,k);
}
void dfs(int x,int fa){
	//printf("%d %d\n",x,fa);
	sz[x]=0; pos[x]=x;
	for (int i=head[x];i;i=e[i].next){
		if (e[i].to==fa) continue;
		dfs(e[i].to,x);
		if (sz[e[i].to]>sz[x])
			swap(pos[x],pos[e[i].to]);
		merge(pos[x],pos[e[i].to]);
		sz[x]+=sz[e[i].to]; 
	}
	f[x]=ask(pos[x],a[x]);
	insert(pos[x],(P){b[x],f[x]});
	sz[x]++;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<=n;i++){
		s[i].insert((P){-N,inf});
		s[i].insert((P){N,inf});
	}
	for (int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) 
		printf("%lld ",f[i]);
}