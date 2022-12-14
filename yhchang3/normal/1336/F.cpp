#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>//ost
#include<ext/pb_ds/assoc_container.hpp>//ost
using namespace __gnu_pbds;//pq,ost,
using namespace std;
const int MAXN = 150010,MAXLOG = 18;
int p[MAXLOG+1][MAXN],dep[MAXN],in[MAXN],out[MAXN],dfscnt,who[MAXN];
vector<int> e[MAXN];
void dfs(int x,int fa){
	p[0][x]=fa;
	in[x]=++dfscnt;
	who[dfscnt]=x;
	for(int i=0;i+1<=MAXLOG;i++)
		p[i+1][x]=p[i][p[i][x]];
	for(int it:e[x])
		if(it!=fa){
			dep[it]=dep[x]+1;
			dfs(it,x);
		}
	out[x]=dfscnt;
}
inline int go(int x,int d){
   for(int k=0;d;d>>=1,k++)
      if(d&1)  x=p[k][x];
   return x;
}
int LCA(int a,int b){
   if(dep[a]>dep[b])   swap(a,b);
   b = go(b,dep[b]-dep[a]);
   if(a==b) return a;
   for(int i=MAXLOG;i>=0;i--)
      if(p[i][a]!=p[i][b]){
         a=p[i][a];
         b=p[i][b];
      }
   return p[0][a];
}

struct EVENT{
	int to,top,id;
	EVENT(int to=0,int top=0,int id=0):to(to),top(top),id(id){}
	bool operator<(const EVENT& rhs)const{
		return in[to]!=in[rhs.to]?in[to]<in[rhs.to]:id<rhs.id;
	}
};
vector<EVENT> event[MAXN];

tree<EVENT,null_type,less<EVENT>,rb_tree_tag,tree_order_statistics_node_update> T[MAXN];

long long int ans;
int K;
void gao(int x,int to,int top){
	int len = dep[x]-dep[top] + dep[to]-dep[top];
	if(len>=K){
		if(dep[x]-dep[top]>=K){
			int z = go(x,K-1);
			ans += T[x].size() - (int) (T[x].order_of_key(EVENT(who[out[z]],0,MAXN)) - T[x].order_of_key(EVENT(z,0,-1)));
		}
		else{
			int z = go(to,len-K);
			ans += (int) (T[x].order_of_key(EVENT(who[out[z]],0,MAXN)) - T[x].order_of_key(EVENT(z,0,-1)));
		}
	}
}

struct BIT_{
	int val[MAXN+1];
	void add(int x,int v){
		for(;x<=MAXN;x+=x&-x)
			val[x]+=v;
	}
	int query(int x){
		int res = 0;
		for(;x;x-=x&-x)
			res+=val[x];
		return res;
	}
	void add_int(int x,int y){
		add(x,1),add(y+1,-1);	
	}
}BIT,BIT2;
vector<int> todo[MAXN];
int st[MAXN],en[MAXN];
void solve(int x,int f){
	for(auto &it:event[x])
		gao(x,it.to,it.top),T[x].insert(it);
	for(int y:e[x])
		if(y!=f){
			solve(y,x);
			for(auto it=T[y].lower_bound(EVENT(y,0,-1));it!=T[y].end()&&in[it->to]<=out[y];)
				it = T[y].erase(it);
			if(T[y].size()>T[x].size())
				T[x].swap(T[y]);
			for(auto &it:T[y])
				gao(x,it.to,it.top);
			for(auto &it:T[y])
				T[x].insert(it);
		}
	for(int i:todo[x]){
		int y = st[i];
		ans += BIT.query(in[y]);
		ans -= BIT2.query(in[y]);
	}
	for(int i:todo[x]){
		int y = st[i];
		if(dep[y]-dep[x]>=K){
			int z = go(y,dep[y]-dep[x]-K);
			BIT.add_int(in[z],out[z]);
			BIT2.add_int(in[z],out[z]);
		}
	}
	for(int i:todo[x]){
		int y = en[i];
		ans += BIT.query(in[y]);
	}
	for(int i:todo[x]){
		int y = en[i];
		if(dep[y]-dep[x]>=K){
			int z = go(y,dep[y]-dep[x]-K);
			BIT.add_int(in[z],out[z]);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m>>K;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++){
		cin>>st[i]>>en[i];
		if(in[st[i]]>in[en[i]])
			swap(st[i],en[i]);
		int l = LCA(st[i],en[i]);
		todo[l].emplace_back(i);
		event[st[i]].emplace_back(EVENT(en[i],l,i));
	}
	solve(1,0);
	cout<<ans<<endl;
}