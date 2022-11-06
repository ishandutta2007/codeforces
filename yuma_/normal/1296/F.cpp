#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
#include<memory>
#include<numeric>
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace std;

using ll=long long;
using ld =long double;

#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
	os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it;
		i++;
	} 
	return os;
}
class Tree {
public:
	Tree(int V, int root) : V(V), root(root), cnum(V), place(V), id(V) {
		T.resize(V);
		for (int i = 0; i < MAXLOGV; i++) {
			parent[i].resize(V);
		}
		depth.resize(V);
	}
	// uv
	// lcaIOt
	void unite(int u, int v) {
		T[u].push_back(v);
		T[v].push_back(u);
	}
	// init
	// RXgN^lca
	void init() {
		dfs(root, root, 0);
		int id = 0;
		getid(root, root, id);
	}
	// uvlca
	int lca(int u, int v) const {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < MAXLOGV; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) return u;
		for (int k = MAXLOGV - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
	// uv
	// edge`_
	int dist(int u, int v) const {
		int p = lca(u, v);
		return (depth[u] - depth[p]) + (depth[v] - depth[p]);
	}
	int dfs(int v, int p, int d) {
		parent[0][v] = p;
		depth[v] = d;
		cnum[v] = 0;
		for (int i = 1; i < MAXLOGV; i++) {
			parent[i][v] = parent[i - 1][parent[i - 1][v]];
		}
		for (int next : T[v]) {
			if (next != p) cnum[v] += dfs(next, v, d + 1);
		}
		return cnum[v] + 1;
	}

	void getid(const int v, const int p, int &nplace) {
		place[v] = nplace;
		id[nplace] = v;
		nplace++;
		for (int next : T[v]) {
			if (next != p) getid(next, v, nplace);
		}
	}
	static const int MAXLOGV = 25;
	// OtXg\
	vector<vector<int> > T;
	// _
	int V;
	// m[h
	int root;

	// em[h
	vector<int> parent[MAXLOGV];
	// [
	vector<int> depth;

	//q
	vector<int>cnum;

	//
	vector<int>place;
	vector<int>id;

};

struct query{
    int l;
    int r;
    int c;

};
bool operator<(const query&l,const query&r){
    return l.c>r.c;
}

struct Edge{
    int src;
    int dst;
    int id;
};
using Graph=vector<vector<Edge>>;
Graph graph;
vector<int>get_root(int s,int t){
    vector<pair<int,int>>comes(graph.size(),make_pair(-1,-1));
    queue<int>que;
    que.emplace(s);
    while(!que.empty()){
        int now=que.front();
        que.pop();
        for(auto e:graph[now]){
            if(comes[e.dst].first==-1){
                comes[e.dst]=make_pair(e.src,e.id);
                que.emplace(e.dst);
            }
        }
    }
    assert(comes[t].first!=-1);
    int now=t;
    vector<int>roots;
    while(now!=s){
        roots.push_back(comes[now].second);
        now=comes[now].first;
    }
    return roots;
}
int main() {
    
    
    ios::sync_with_stdio(false);
    int N;cin>>N;
    graph.resize(N);
    for(int i=0;i<N-1;++i){
        int a,b;cin>>a>>b;
        a--;b--;
        graph[a].push_back(Edge{a,b,i});
        graph[b].push_back(Edge{b,a,i});
    }
    int M;cin>>M;
    vector<query>qs;
    for(int i=0;i<M;++i){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        qs.push_back(query{a,b,c});
    }
    vector<int>costs(N-1,1);
    sort(qs.begin(),qs.end());
    for(auto q:qs){
        auto roots=get_root(q.l,q.r);
        for(auto id:roots){
            costs[id]=max(costs[id],q.c);
        }
    }
    bool ok=true;
    for(auto q:qs){
        auto roots=get_root(q.l,q.r);
        int amin=1e7;
        for(auto id:roots){
            amin=min(costs[id],amin);
        }
        if(amin!=q.c)ok=false;
    }
    if(ok){
        for(int i=0;i<N-1;++i){
            cout<<costs[i]<<' ';
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}