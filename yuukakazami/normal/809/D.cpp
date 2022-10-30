#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define mp make_pair
#define fi first
#define se second
#define per(i,a,n) for (int i=int(n)-1;i>=(a);i--)
#define pb push_back
using namespace std;
const int md = int(1e9) + 7;
ll mypow(ll a,ll e){
	if(e==0) return 1;
	return e%2==0?mypow(a*a%md,e>>1):mypow(a,e-1)*a%md;
}
// head
// i -> max(0..i-1) + 1
//1111222223333444455555
//11112333334444555566666

const int N=int(3e5 + 10);

struct node {
	int wt;

	int add;
	int key;
	node *s[2];
	void apply_add(int a){
		add += a;
		key += a;
	}
	void push() {
		rep(i,0,2) if(s[i])
			s[i]->apply_add(add);
		add = 0;
	}
	void upd() {
	}
}pool[N],*cur=pool,*rt;

node *newnode(int w) {
	node *q=cur++;
	q->key = w;
	q->wt=(rand()<<15)+rand();
	rep(i,0,2) q->s[i] = 0;
	return q;
}

void merge(node *&p,node *l,node *r) {
	if (!l||!r) p=l?l:r;
	else if (l->wt<r->wt) {
		l->push();
		merge(l->s[1],l->s[1],r);
		(p=l)->upd();
	} else {
		r->push();
		merge(r->s[0],l,r->s[0]);
		(p=r)->upd();
	}
}

void split(node *p,node *&l,node *&r,int x) { //<x,>=x
	if (p==0) l=r=0;
	else {
		p->push();
		if (p->key>=x) r=p,split(p->s[0],l,r->s[0],x),r->upd();
		else l=p,split(p->s[1],l->s[1],r,x),l->upd();
	}
}

const int INF = ~0U>>1;
int dp[N];

node*get(node*u,int c){
	while(u->s[c]){
		u->push();
		u=u->s[c];
	}
	return u;
}

int ans;

void dfs(node*u){
	if(!u) return;
	++ans;
	rep(i,0,2) dfs(u->s[i]);
}

node*merge(node*L,node*R){
	node*t;merge(t,L,R); return t;
}

int main(){
	int n; cin>>n; rt = 0; ans = 0;

	rep(i,0,n){
		int l,r;cin>>l>>r;
		int x = 0;
		node*L,*MR,*M,*R;
		split(rt,L,MR,l); //L : <l
		split(MR,M,R,r); // M : [l,r-1] R: >=r
		//M -> all add 1
		//cout<<i<<endl;
		node*is = newnode(l);
		rt = L; rt = merge(rt,is);

		if(M)
			M->apply_add(1);

		//cout<<i<<endl;
		rt = merge(rt,M);
		if(R){
			int key = get(R,0)->key;
			node*x,*y;
			split(R,x,y,key+1);
			R = y;
		}
		rt = merge(rt,R);
		//cout<<i<<endl;
	}
	ans = 0;
	dfs(rt);
	cout<<ans<<endl;
	return 0;
}