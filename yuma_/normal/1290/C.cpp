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
    vector<vector<int>>sums(int(2e5)+1,vector<int>(26));
    
vector<int>aget(int l,int r){
    vector<int>v(26);
    for(int i=0;i<26;++i){
        v[i]=sums[r][i]-sums[l][i];
    }
    sort(v.begin(),v.end(),greater<int>());
    while(!v.empty()&&v.back()==0)v.pop_back();
    return v;
}
    
struct aUnionFind {
    vector<pair<int, long long int>> data;
    aUnionFind(int size) : data(size, make_pair(-1, 0)) { }
    
    //y is w bigger than x
    bool unionSet(const int x, const int y, const long long int w) {
        const int rx(root(x).first), ry(root(y).first);
        if (rx != ry) {
            data[rx].first += data[ry].first; data[ry].first = rx;
            data[ry].second = (w + data[x].second - data[y].second+8)%2;
            return true;
        }
        else {
            return root(x).second + w == root(y).second;
        }
    }
    bool findSet(const int x, const int y) {
        return root(x) == root(y);
    }
    
    //x is belong to first
    //x is second bigger than first
    pair<int, long long int> root(const int x) {
        if (data[x].first < 0) {
            return make_pair(x, 0);
        }
        else {
            pair<int, long long int>ndata;
            ndata.first = root(data[x].first).first;
            ndata.second = (8+data[x].second + root(data[x].first).second)%2;
            return data[x] = ndata;
        }
    }
    int root2(const int x){
        return root(x).first;
    }
    int size(const int x) {
        return -data[root(x).first].first;
    }
};
    
ll nanswer=0;
void add(pair<ll,ll>p,ll mul){
    // WHATS(p)
    // WHATS(mul)
    nanswer+=min(p.first,p.second)*mul;
}
    
int main() {
    
    
    ios::sync_with_stdio(false);
    int N,M;cin>>N>>M;
    string st;cin>>st;
    vector<vector<int>>ids(N);
    for(int i=0;i<M;++i){
        int K;cin>>K;
        for(int j=0;j<K;++j){
            int a;cin>>a;a--;
            ids[a].push_back(i);
        }
    }
    //WHATS(ids)
    
    vector<int>answers(N+1);
    vector<pair<ll,ll>>sums(M,make_pair(1,0));
    aUnionFind uf(M);
    
    for(int i=0;i<N;++i){
        //WHATS(i)
        bool flag=st[i]=='1';
        
        {
            if(ids[i].size()==0){
    
            }else if(ids[i].size()==1){
                auto p(sums[uf.root2(ids[i][0])]);
    
                add(p,-1);
                //  WHATS(uf.data)
                if(flag!=uf.data[ids[i][0]].second)sums[uf.root2(ids[i][0])].first+=int(1e9);
                else sums[uf.root2(ids[i][0])].second+=int(1e9);
                auto p2(sums[uf.root2(ids[i][0])]);
    
                add(p2,1);
            }
            else if(ids[i].size()==2){
                // WHATS(i)
                if(uf.root2(ids[i][0])==uf.root2(ids[i][1])){
    
                }else{
    
                
    
                    auto p(sums[uf.root2(ids[i][0])]);
                    add(p,-1);
                    auto p2(sums[uf.root2(ids[i][1])]);
    
                    add(p2,-1);
    
                    
                    auto aid=uf.root2(ids[i][0]);
                    if(uf.data[ids[i][0]].second==(1+flag+uf.data[ids[i][1]].second)%2){
                        
                        uf.unionSet(ids[i][0],ids[i][1],!flag);
                        sums[aid].first=p.first+p2.first;
                        sums[aid].second=p.second+p2.second;
                        
                    }else{
                        uf.unionSet(ids[i][0],ids[i][1],!flag);
    
                        if(aid==uf.root2(ids[i][0])){
                            sums[aid].first+=p2.second;
                            sums[aid].second+=p2.first;
                        }else{
                            sums[aid].first+=p.second;
                            sums[aid].second+=p.first;
                        }
                    }
                   // WHATS(sums[aid])
                    auto p3(sums[aid]);
                    add(p3,1);
                }
            }
        }
        //WHATS(sums)
        //WHATS(uf.size(0))
        answers[i]=nanswer;
        cout<<nanswer<<'\n';
    }
    
    return 0;
}