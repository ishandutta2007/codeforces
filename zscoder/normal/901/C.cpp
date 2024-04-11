#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

template<class T> struct splnode {
  typedef splnode<T> node_t;

  splnode() : P(NULL), flip(0), pp(NULL) {
    C[0] = C[1] = NULL;
    fix();
  }

  node_t* P;
  node_t* C[2];

  int flip;
  node_t* pp;

  /* Fix the parent pointers of our children.  Additionally if we have any
   * extra data we're tracking (e.g. sum of subtree elements) now is the time to
   * update them (all of the children will already be up to date). */
  void fix() {
    if(C[0]) C[0]->P = this;
    if(C[1]) C[1]->P = this;
  }

  /* Push the flip bit down the tree. */
  void push_flip() {
    if(!flip) return;
    flip = 0;
    swap(C[0], C[1]);
    if(C[0]) C[0]->flip ^= 1;
    if(C[1]) C[1]->flip ^= 1;
  }

  /* Return the direction of this relative its parent. */
  int up() {
    return !P ? -1 : (P->C[0] == this ? 0 : 1);
  }

  /* Simple zig step in the 'c' direction when we've reached the root. */
  void zig(int c) {
    node_t* X = C[c];
    if(X->P = P) P->C[up()] = X;
    C[c] = X->C[1 - c];
    X->C[1 - c] = this;
    fix(); X->fix();
    if(P) P->fix();
    swap(pp, X->pp);
  }

  /* Zig zig in the 'c' direction both times. */
  void zigzig(int c) {
    node_t* X = C[c];
    node_t* Y = X->C[c];
    if(Y->P = P) P->C[up()] = Y;
    C[c] = X->C[1 - c];
    X->C[c] = Y->C[1 - c];
    Y->C[1 - c] = X;
    X->C[1 - c] = this;
    fix(); X->fix(); Y->fix();
    if(P) P->fix();
    swap(pp, Y->pp);
  }

  /* Zig zag first in the 'c' direction then in the '1-c' direciton. */
  void zigzag(int c) {
    node_t* X = C[c];
    node_t* Y = X->C[1 - c];
    if(Y->P = P) P->C[up()] = Y;
    C[c] = Y->C[1 - c];
    X->C[1 - c] = Y->C[c];
    Y->C[1 - c] = this;
    Y->C[c] = X;
    fix(); X->fix(); Y->fix();
    if(P) P->fix();
    swap(pp, Y->pp);
  }

  /* Splay this up to the root.  Always finishes without flip set. */
  node_t* splay() {
    for(push_flip(); P; ) {
      /* Reorganize flip bits so we can rotate as normal. */
      if(P->P) P->P->push_flip();
      P->push_flip();
      push_flip();

      int c1 = up();
      int c2 = P->up();
      if(c2 == -1) {
        P->zig(c1);
      } else if(c1 == c2) {
        P->P->zigzig(c1);
      } else {
        P->P->zigzag(c2);
      }
    }
    return this;
  }

  /* Return the max element of the subtree rooted at this. */
  node_t* last() {
    push_flip();
    return C[1] ? C[1]->last()  : splay();
  }

  /* Return the min element of the subtree rooted at this. */
  node_t* first() {
    push_flip();
    return C[0] ? C[0]->first() : splay();
  }
};


template<class T>
struct linkcut {
typedef splnode<T> node_t;

linkcut(int N) : node(N) {
}

void link(int u, int v) {
  make_root(v);
  node[v].pp = &node[u];
}

void cut(int u, int v) {
  make_root(u);
  node[v].splay();
  if(node[v].pp) {
    node[v].pp = NULL;
  } else {
    node[v].C[0]->P = NULL;
    node[v].C[0] = NULL;
    node[v].fix();
  }
}

bool connected(int u, int v) {
  node_t* nu = access(u)->first();
  node_t* nv = access(v)->first();
  return nu == nv;
}

/* Move u to root of represented tree. */
void make_root(int u) {
  access(u);
  node[u].splay();
  if(node[u].C[0]) {
    node[u].C[0]->P = NULL;
    node[u].C[0]->flip ^= 1;
    node[u].C[0]->pp = &node[u];

    node[u].C[0] = NULL;
    node[u].fix();
  }
}

/* Move u to root aux tree.  Return the root of the root aux tree. */
splnode<T>* access(int u) {
  node_t* x,* pp;
  for(x = node[u].splay(); x->pp; x = pp) {
    pp = x->pp->splay();
    x->pp = NULL;
    if(pp->C[1]) {
      pp->C[1]->P = NULL;
      pp->C[1]->pp = pp;
    }
    pp->C[1] = x;
    pp->fix();
  }
  return x;
}

vector<node_t> node;
};

/*
struct Node
{   int sz, label; 
    Node *p, *pp, *l, *r;
    Node() { p = pp = l = r = 0; }
};

void update(Node *x)
{   x->sz = 1;
    if(x->l) x->sz += x->l->sz;
    if(x->r) x->sz += x->r->sz;
}

void rotr(Node *x)
{   Node *y, *z;
    y = x->p, z = y->p;
    if((y->l = x->r)) y->l->p = y;
    x->r = y, y->p = x;
    if((x->p = z))
    {   if(y == z->l) z->l = x;
        else z->r = x;
    }
    x->pp = y->pp;
    y->pp = 0;
    update(y);
}

void rotl(Node *x)
{   Node *y, *z;
    y = x->p, z = y->p;
    if((y->r = x->l)) y->r->p = y;
    x->l = y, y->p = x;
    if((x->p = z))
    {   if(y == z->l) z->l = x;
        else z->r = x;
    }
    x->pp = y->pp;
    y->pp = 0;
    update(y);
}

void splay(Node *x)
{   Node *y, *z;
    while(x->p)
    {   y = x->p;
        if(y->p == 0)
        {   if(x == y->l) rotr(x);
            else rotl(x);
        }
        else
        {   z = y->p;
            if(y == z->l)
            {   if(x == y->l) rotr(y), rotr(x);
                else rotl(x), rotr(x);
            }
            else
            {   if(x == y->r) rotl(y), rotl(x);
                else rotr(x), rotl(x);
            }
        }
    }
    update(x);
}

Node *access(Node *x)
{   splay(x);
    if(x->r)
    {   x->r->pp = x;
        x->r->p = 0;
        x->r = 0;
        update(x);
    }

    Node *last = x;
    while(x->pp)
    {   Node *y = x->pp;
        last = y;
        splay(y);
        if(y->r)
        {   y->r->pp = y;
            y->r->p = 0;
        }
        y->r = x;
        x->p = y;
        x->pp = 0;
        update(y);
        splay(x);
    }
    return last;
}

Node *root(Node *x)
{   access(x);
    while(x->l) x = x->l;
    splay(x);
    return x;
}

void cut(Node *x)
{   access(x);
    x->l->p = 0;
    x->l = 0;
    update(x);
}

void link(Node *x, Node *y)
{   access(x);
    access(y);
    x->l = y;
    y->p = x;
    update(x);
}

Node *lca(Node *x, Node *y)
{   access(x);
    return access(y);
}

int depth(Node *x)
{   access(x);
    return x->sz - 1;
}

class LinkCut
{   Node *x;

    public:
    LinkCut(int n)
    {   x = new Node[n];
        for(int i = 0; i < n; i++)
        {   x[i].label = i;
            update(&x[i]);
        }
    }

    virtual ~LinkCut()
    {   delete[] x;
    }

   

    void cut(int u)
    {   ::cut(&x[u]);
    }

    int root(int u)
    {   return ::root(&x[u])->label;
    }

    int depth(int u)
    {   return ::depth(&x[u]);
    }
	
	void del(int u, int v)
	{
		if(depth(u)<depth(v)) swap(u,v);
		cut(u);
	}
	
    int lca(int u, int v)
    {   return ::lca(&x[u], &x[v])->label;
    }
    
    bool sameset(int u, int v)
    {
		return (root(u)==root(v));
	}
	
	 void merge(int u, int v)
    {  
		if(sameset(u,v)) return ;
		if(depth(u)>depth(v)) swap(u,v);
		int rt = root(u);
		if(rt!=u)
		{
			cut(u);
			cerr<<"CUT : "<<u+1<<' '<<rt+1<<'\n';
			merge(rt,u);
		}
		cerr<<"MERGE : "<<u+1<<' '<<v+1<<'\n';
		 ::link(&x[u], &x[v]);
		cerr<<"H : "<<root(u)+1<<' '<<depth(u)<<' '<<depth(v)<<'\n';
    }
};
*/

vector<ii> edges;
vector<int> rightend;
vi adj[301111];
ll sum[300111];

ll S(int l, int r)
{
	if(l==0) return sum[r];
	else return sum[r]-sum[l-1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--; adj[u].pb(v); adj[v].pb(u);
		edges.pb(mp(max(u,v),min(u,v)));
	}
	int ptr=0; int ptrtest=0;
	sort(edges.begin(),edges.end());
	//LinkCut lc(n);
	linkcut<int> lc(n);
	rightend.resize(n);
	int curans = 0;
	for(int i=0;i<n;i++)
	{
		curans=max(curans,i);
		while(curans+1<n)
		{
			while(ptr<edges.size()&&edges[ptr].fi<=curans)
			{
				if(edges[ptr].se>=i) lc.link(edges[ptr].fi, edges[ptr].se);
				ptr++; ptrtest=max(ptrtest,ptr);
			}
			bool pos=1;
			while(ptr<edges.size()&&edges[ptr].fi==curans+1)
			{
				//cerr<<ptr<<' '<<edges[ptr].fi+1<<' '<<edges[ptr].se+1<<' '<<lc.root(edges[ptr].fi)+1<<' '<<lc.root(edges[ptr].se)+1<<' '<<curans+2<<'\n';
				if(edges[ptr].se>=i) 
				{
					if(lc.connected(edges[ptr].fi, edges[ptr].se))
					{
						pos=0; break;
					}
					else
					{
						lc.link(edges[ptr].fi,edges[ptr].se);
					}
				}
				ptr++;
			}
			if(pos)
			{
				curans++;
				while(ptr<edges.size()&&edges[ptr].fi<=curans)
				{
					if(edges[ptr].se>=i) lc.link(edges[ptr].fi, edges[ptr].se);
					ptr++; ptrtest=max(ptrtest,ptr);
				}
			}
			else break;
		}
		rightend[i] = curans;
		//cerr<<"SOLVE : "<<i+1<<' '<<curans+1<<'\n';
		for(int j=0;j<adj[i].size();j++)
		{
			int v=adj[i][j];
			//cerr<<i<<' '<<j<<' '<<v<<'\n';
			if(v>=i&&v<=curans)
			{
				//cerr<<"DEL : "<<i+1<<' '<<v+1<<' '<<lc.root(i)+1<<' '<<lc.root(v)+1<<' '<<lc.depth(i)<<' '<<lc.depth(v)<<'\n';
				lc.cut(i, v);
			}
		}
	}
	for(int i=0;i<rightend.size();i++)
	{
		sum[i]=rightend[i]-i+1;
		if(i>0) sum[i]+=sum[i-1];
	}
	int q; cin>>q;	
	for(int i=0;i<q;i++)
	{
		int l,r; cin>>l>>r;
		l--; r--;
		ll res=0;
		int z=lower_bound(rightend.begin()+l,rightend.end(),r)-rightend.begin();
		//[z, r] is answer r
		/*
		for(int j=l;j<=r;j++)
		{
			res+=min(rightend[j],r)-j+1;
		}
		*/
		ll cnt = r-z+1;
		res = ((cnt*(cnt+1)))/2 + S(l,z-1);
		cout<<res<<'\n';
	}
}