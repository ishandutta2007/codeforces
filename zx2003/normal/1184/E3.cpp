#include<bits/stdc++.h>
using namespace std;
const int N=1e6+500;
struct edge{
	int a,b,e;
	inline void in(){cin>>a>>b>>e;}
}E[N];
class ltree{
    private:
        struct node{
            int v;
            node *l,*r;
            int d;
            node(int _v=0):v(_v){
                l=r=NULL;
                d=0;
            }
        };
        node *rt;
        inline void swap(node* &x,node* &y){
            node*t=x;
            x=y;
            y=t;
        }
        node* merge(node*x,node*y){
        	if(x==NULL)return y;
        	if(y==NULL)return x;
            if(x->v>y->v)swap(x,y);
            return y->r=x->l,x->l=y,x;
        }
        node* mergec(node*x){
        	if(x==NULL || x->r==NULL)return x;
        	node*a=x->r,*b=a->r;
        	x->r=a->r=NULL;
        	return merge(merge(x,a),mergec(b));
        }
    public:
    	inline bool empty(){
    		return rt==NULL;
    	}
        inline void push(int x){
            node* o=new node(x);
            rt=merge(rt,o);
        }
        inline void pop(){
            node*o=rt;
            rt=mergec(rt->l);
            delete o;
        }
        inline int top(){
            return rt->v;
        }
        inline void join(ltree&x){
            rt=merge(rt,x.rt);
        }
}q1[N/10],q2[N/10];
int n,m,i,j,g[N],id[N],f1[20][N/10],f2[20][N/10],dep[N],ans[N];
vector<int>e[N];
inline bool cmp(int x,int y){
	return E[x].e<E[y].e;
}
int gfa(int x){
	return g[x]==x?x:g[x]=gfa(g[x]);
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;f1[0][u]=fa;
	for(int i:e[u]){
		int v=E[i].a^E[i].b^u;
		if(v==fa)continue;
		f2[0][v]=E[i].e;dfs(v,u);
	}
}
void dfs2(int u,int fa){
	for(int i:e[u]){
		int v=E[i].a^E[i].b^u;
		if(v==fa)continue;
		dfs2(v,u);
		ans[i]=q1[v].empty()?1e9:q1[v].top();
		q1[u].join(q1[v]);q2[u].join(q2[v]);
	}
	for(;!q1[u].empty() && !q2[u].empty() && q1[u].top()==q2[u].top();)
		q1[u].pop(),q2[u].pop();
}
inline int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int dt=dep[y]-dep[x],i;
	for(i=0;1<<i<=dt;++i)if(dt>>i&1)y=f1[i][y];
	if(x==y)return x;
	for(i=19;i>=0;--i)if(f1[i][x]!=f1[i][y])x=f1[i][x],y=f1[i][y];
	return f1[0][x];
}
inline int A1(int x,int y){
	int dt=dep[y]-dep[x],i,ans=0;
	for(i=0;1<<i<=dt;++i)if(dt>>i&1)ans=max(ans,f2[i][y]),y=f1[i][y];
	return ans;
}
bool ont[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;for(i=1;i<=m;++i)E[id[i]=i].in();
	for(i=1;i<=n;++i)g[i]=i;
	sort(id+1,id+m+1,cmp);
	for(i=1;i<=m;++i){
		int x=E[id[i]].a,y=E[id[i]].b;
		if(gfa(x)==gfa(y))continue;
		ont[id[i]]=1;
		g[gfa(x)]=gfa(y);e[x].push_back(id[i]);e[y].push_back(id[i]);
	}
	dfs(1,0);
	for(i=1;i<20;++i)for(j=1;j<=n;++j)f1[i][j]=f1[i-1][f1[i-1][j]],
		f2[i][j]=max(f2[i-1][j],f2[i-1][f1[i-1][j]]);
	for(i=1;i<=m;++i)if(!ont[i]){
		int z=lca(E[i].a,E[i].b);
		ans[i]=max(A1(z,E[i].a),A1(z,E[i].b));
		q1[E[i].a].push(E[i].e);q1[E[i].b].push(E[i].e);
		q2[z].push(E[i].e);q2[z].push(E[i].e);
	}
	dfs2(1,0);
	for(i=1;i<=m;++i)cout<<ans[i]<<'\n';
	return 0;
}